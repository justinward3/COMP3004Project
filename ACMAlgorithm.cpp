#include <ACMAlgorithm.h>
#include "qmap.h"
#include <vector>
#include <cstdlib>


using namespace std;

//Constructor for the ACM Algorithm
ACMAlgorithm::ACMAlgorithm() {
    cout << "ACM Algorithm Constructed" << endl;
    QStringList keys = {"type","active","affection","age","cats","catsfuture","children","childrenfuture","colour","cost","dogs","dogsfuture","experience","home","lifespan","noise","obedient","older","sex","shedding","size","space","time"};


    QStringList ClientKeys = {"experience","affection","cost","time","home","children","childrenfuture","dogs","dogsfuture","lifespan","noise","obedient","older","sex","shedding","size","space","time"};
    QStringList AnimalKeys = {"DoC","affection","cost","time","space","loudness","activeness","obedience","shedding","lifespan","intwithdog","intwithcat","intwithchild"};


    caseDict["type"] = 1;
	caseDict["sex"] = 1;
	caseDict["size"] = 1;
	caseDict["colour"] = 1;
	caseDict["age"] = 3;
	caseDict["DoC"] = 2;
	caseDict["affection"] = 2;
	caseDict["cost"] = 2;
	caseDict["time"] = 2;
    caseDict["lifespan"] = 3;
	caseDict["space"] = 2;
	caseDict["loudness"] = 2;
	caseDict["activeness"] = 3;
	caseDict["obedience"] = 3;
	caseDict["shedding"] = 3;
	caseDict["intWithDog"] = 1;
	caseDict["intWithCat"] = 1;
	caseDict["intWithChild"] = 1;

	weightDict["type"] = 5;
	weightDict["sex"] = 2;
	weightDict["size"] = 4;
	weightDict["colour"] = 1;
	weightDict["age"] = 4;
	weightDict["DoC"] = 4;
	weightDict["affection"] = 3;
	weightDict["Cost"] = 5;
	weightDict["time"] = 4;
	weightDict["lifeSpan"] = 4;
	weightDict["space"] = 5;
	weightDict["loudness"] = 3;
	weightDict["activeness"] = 3;
	weightDict["obedience"] = 3;
	weightDict["shedding"] = 4;
	weightDict["intWithDog"] = 5;
	weightDict["intWithCat"] = 5;
	weightDict["intWithChild"] = 5;

}

ACMAlgorithm::~ACMAlgorithm(){
	cout << "ACM Algorithm Deconstructed" << endl;
}

QMap<Animal*, Client*> ACMAlgorithm::runACM(vector<Client*> clients, vector<Animal*> animals){
    cout << "Running..." <<endl;
    QMap<Client*, QMap<float, Animal*>> clientMatches;
	int numMatchesSaved = (clients.size() < animals.size()) ? clients.size() : animals.size();

    for (auto client : clients){
        for (auto animal : animals){
            //qDebug() << "Running ACM on " << client->getFname() << " and " << animal->getName();
            float matchScore = runACMOnPair(animal, client);
            if(matchScore != -100){
                if (clientMatches.count() <= numMatchesSaved){
                    clientMatches[client].insert(matchScore,animal);
                }else{
                    int worst = 0;
                    int pop = 0;
                    for (auto key : clientMatches[client].keys()){
                        if (matchScore >= key && pop == 0){
                            pop = 1;
                            worst = key;
                        }else if (key < worst){
                            worst = key;
                        }
                    }
                    if (pop == 1){
                        clientMatches[client].remove(worst);
                        clientMatches[client].insert(matchScore , animal);
                    }
                }
            }
        }
	}
    cout<<"On Pair Complete"<<endl;
    QMap<Animal*,Client*> pairs;
    vector<Client*> exhausted; //Clients who dont have a match
    vector<Client*> lowMatchCount; //Clients who don't have enough matches
    cout<<"While: " << pairs.size() << " < " << numMatchesSaved <<endl;
    int iteration = 0;
	while ((pairs.count() < numMatchesSaved) ||  pairs.count() < (numMatchesSaved + exhausted.size())) {
        for (int i=0; i<clients.size(); i++){
            Client* client = clients[i];
            //qDebug()<< "Current Client is " << client->getFname();
            if (pairs.values().count(client) == 0){
                //qDebug() <<"    "<<client->getFname() << "has no matches";
                for (int i=0; i<clientMatches[client].keys().size(); i++){
                    float key = clientMatches[client].keys().at(i);
                    if (clientMatches[client][key] != NULL){
                        Animal* animal = clientMatches[client][key];
                        //qDebug() << "       Checking if we can add" << client->getFname() << " with " << animal->getName();
                        if (!pairs.contains(animal)){
                            //qDebug() << "       Adding: " << animal->getName() << " with " << client->getFname();
                            pairs.insert(animal,client);
                            //qDebug() <<"            Done with "<< client->getFname();
				                    break;
						            }else{
                            //qDebug() <<"    "<< animal->getName() << "could not be used";
                            //int temp = clientMatches[pairs[animal]].values(animal)[0];
                            std::vector<Client*>::iterator it;
                            it = find (exhausted.begin(), exhausted.end(), pairs[animal]);
                            if (key > clientMatches[pairs[animal]].key(animal) && it != exhausted.end()){
                                //qDebug() << "Swapping: " << animal->getName() << " from " << pairs[animal]->getFname() << " to " << client->getFname();
                                pairs.remove(animal);
                                pairs.insert(animal,client);
								                break;
							               }
						             }
        					}
        				}
        			}

            Animal * temp = pairs.key(client);
            //qDebug() << "Before  IF";
            if (clientMatches[client].count() < animals.size() && clientMatches[client].count() < clients.size() && !temp){
				          //Check the matches this client does have to see if they have nay good matches
				        int matchable = 0;
                for (auto key : clientMatches[client].keys()){
                    Animal* animal = clientMatches[client][key];
                    std::vector<Client*>::iterator it;
                    it = find (lowMatchCount.begin(), lowMatchCount.end(), pairs[animal]);
					//If Exhausted does not contain the client this animal is paired with currently, then its safe to remove him for rematching
                    if (it == lowMatchCount.end()) {
                        //qDebug() << "Removing " << pairs[animal]->getFname() <<  " Inserting: " << client->getFname();
						            pairs.remove(animal);
                        pairs.insert(animal,client);
                        lowMatchCount.insert(lowMatchCount.end(),client);
						            matchable = 1;
                                    break;
                      }else {

                        int oldScore;
                        int newScore;
                        for (int i=0; i<clientMatches[client].keys().size(); i++){
                          if (clientMatches[client][clientMatches[client].keys()[i]] == animal){
                            newScore = clientMatches[client].keys()[i];
                            break;
                          }
                        }
                        Client* currentMatch = lowMatchCount[std::distance(lowMatchCount.begin(), it)];
                        for (int i=0; i<clientMatches[currentMatch].keys().size(); i++){
                          if (clientMatches[currentMatch][clientMatches[currentMatch].keys()[i]] == animal){
                            oldScore = clientMatches[currentMatch].keys()[i];
                            break;
                          }
                        }
                        if (newScore > oldScore){
                          pairs.remove(animal);
                          pairs.insert(animal,client);
                          lowMatchCount.insert(lowMatchCount.end(),client);
                          std::vector<Client*>::iterator it;
                          it = find (lowMatchCount.begin(), lowMatchCount.end(), pairs[animal]);
                          lowMatchCount.erase(it);
        						      matchable = 1;
                        }
      					}
      				}
      				if (matchable == 0){
                          exhausted.insert(exhausted.end(),client);
      				}
      			}
            //qDebug() << "";
          }

          //qDebug() << "BROKE FREE";
          QList<Animal*> akeys = pairs.keys();
          int total = 0;
          for(int i=0; i<akeys.size();i++){
            //qDebug() << iteration << ": " << pairs.count() << " + " << exhausted.size();
          }
          total = pairs.count() + exhausted.size();

          if (total >= numMatchesSaved){
            break;
          }
          iteration += 1;
        }

	return pairs;
}



int ACMAlgorithm::runACMOnPair(Animal* animal, Client* client){
	//Variable used to check if a trait match value is <= -5
	float pastMatchScore = 0;

	//Actual Match Score
  float matchScore = 0;
  QList<QString> caseKeys = caseDict.keys();
  for(int i=0; i<caseKeys.size();i++){
    QString trait = caseKeys[i];
    //qDebug() <<"Analyzing :"<<trait <<" for " << animal->getName() << "and" << client->getFname();

    //Grab the trait values and set the pastMatchScore variable
    float clientValue = client->getMatchingPrefs()[trait];
    float animalValue = animal->getTraits()[trait];
    //^this doesnt work for type^

    //REMEMBER NOT ALL FROM THAT DICT IS IN ANIMAL TRAITS EX, COLOUR

    if (trait == "type"){
        if ( dynamic_cast<Dog*>( animal ) )
           animalValue =  1;

        else if ( dynamic_cast<Cat*>( animal ) )
           animalValue =  2;

        else if ( dynamic_cast<Bird*>( animal ) )
           animalValue =  3;

        else if ( dynamic_cast<SmallAnimal*>( animal ) )
           animalValue = 4;
    }
    else if (trait == "sex"){
        if(animal->getSex() == 'M'){
            animalValue = 1;
        }
        else if(animal->getSex() == 'F'){
            animalValue = 2;
        }
    }
    else if (trait == "age"){
        //Must put age in correct range
        client->getMatchingPrefs()["older"];
    }
    else if(trait == "DoC"){
        clientValue = client->getMatchingPrefs()["experience"];
    }
    else if(trait == "colour"){
        QString colour = animal->getColour();
        if(colour == "Brown"){
            animalValue = 1;
        }
        else if(colour == "Black"){
            animalValue = 2;
        }
        else if(colour == "Golden"){
            animalValue = 3;
        }
        else if(colour == "Orange"){
            animalValue = 4;
        }
        else if(colour == "White"){
            animalValue = 5;
        }
        else if(colour == "Grey"){
            animalValue = 6;
        }
        else{
            animalValue = 7;
        }
    }
    else if(trait == "intWithDog"){
        // Remember for these 1 is Y and 2 is N
        // -1 so 0 is Y and 1 is N
        // 0 is friendly 1 is not
        clientValue = (client->getMatchingPrefs()["dogs"]-1 || client->getMatchingPrefs()["dogsfuture"]-1);
    }
    else if(trait == "intWithCat"){
        clientValue = client->getMatchingPrefs()["cats"]-1 || client->getMatchingPrefs()["catsfuture"]-1;
    }
    else if(trait == "intWithChild"){
        clientValue = client->getMatchingPrefs()["children"]-1 || client->getMatchingPrefs()["childrenfuture"]-1;
    }
    else if(trait == "loudness"){
        // 1 is Minimal, 2 is N/A
        clientValue = client->getMatchingPrefs()["noise"]+1;
        //Apartment is 1, House is 2
        if(client->getMatchingPrefs()["home"] == 1)
            clientValue = clientValue -1;
        }
        else if(client->getMatchingPrefs()["home"] ==  2){
            clientValue = clientValue +1;
        }
    else if(trait == "obedience"){
        clientValue = client->getMatchingPrefs()["obedient"];
    }
    else if(trait == "lifespan"){
        clientValue = client->getMatchingPrefs()["lifespan"];
        int lS = animal->getTraits()["lifespan"];
        if(0<=lS && lS<=2){
            animalValue = 1;
        }
        else if( 3<=lS && lS<=5){
            animalValue = 2;
        }
        else if (6<=lS && lS<=10){
            animalValue = 3;
        }
        else if (lS > 10){
            animalValue = 4;
        }
        else {
            animalValue = 1;
        }
    }
    else if(trait == "cost"){
        int cost = animal->getTraits()["cost"];
        if(0<=cost && cost<=200){
            animalValue = 1;
        }
        else if( 201<=cost && cost<=500){
            animalValue = 2;
        }
        else if (501<=cost && cost<=750){
            animalValue = 3;
        }
        else if (751<=cost && cost<= 1000){
            animalValue = 4;
        }
        else if( cost > 1000){
            animalValue = 5;
        }
        else{
            animalValue = 1;
        }
    }

    //qDebug()<<" Animal Value is :"<<animalValue<<"      "<<" Client Value is :"<<clientValue;

		pastMatchScore = matchScore;

		//Check our cases and compute trait match score
		if (caseDict.value(trait) == 1){
			if (clientValue == animalValue && animalValue != 0){
				matchScore += (1 * weightDict.value(trait));
			}else if (animalValue != 0){
				matchScore += (-1 * weightDict.value(trait));
			}
		}else if (caseDict.value(trait) == 2){
			matchScore += (((clientValue-animalValue)/clientValue)*weightDict.value(trait));
		}else if (caseDict.value(trait) == 3){
            matchScore += weightDict.value(trait)/(abs(clientValue-animalValue)+1);
		}

		if (pastMatchScore >= (matchScore+5)){
      //qDebug() << "     No Match! Due to: " << trait << "  total: " << (matchScore-pastMatchScore);
      //qDebug() << clientValue;
      return -100;
		}

  }
  //qDebug() << "     Match Score of " << client->getFname() << "and " << animal->getName() << " = " << matchScore;
  return matchScore;
}
