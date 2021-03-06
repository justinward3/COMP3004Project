#include <ACMAlgorithm.h>
#include "qmap.h"
#include <vector>
#include <cstdlib>
#include <sstream>
#include "QMessageBox"


using namespace std;

//Constructor for the ACM Algorithm
ACMAlgorithm::ACMAlgorithm() {
  caseDict["type"] = 1;
	caseDict["sex"] = 1;
	caseDict["size"] = 1;
	caseDict["colour"] = 1;
	caseDict["age"] = 1; //Change to case 1
	caseDict["DoC"] = 2;
	caseDict["affection"] = 2;
	caseDict["cost"] = 2;
	caseDict["time"] = 2;
    caseDict["lifespan"] = 3;
	caseDict["space"] = 2;
	caseDict["loudness"] = 3;
	caseDict["activeness"] = 3;
	caseDict["obedience"] = 3;
	caseDict["shedding"] = 3;
	caseDict["intwithdog"] = 1;
	caseDict["intwithcat"] = 1;
	caseDict["intwithchild"] = 1;

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
	weightDict["space"] = 4;
	weightDict["loudness"] = 2;
	weightDict["activeness"] = 3;
	weightDict["obedience"] = 3;
	weightDict["shedding"] = 4;
	weightDict["intwithdog"] = 5;
	weightDict["intwithcat"] = 5;
	weightDict["intwithchild"] = 5;

}

ACMAlgorithm::~ACMAlgorithm(){
    qDebug()  << "ACM Algorithm Deconstructed";
}

QMap<Animal*, Client*> ACMAlgorithm::runACM(vector<Client*> clients, vector<Animal*> animals){
    qDebug()  << "Running..." ;

    //The list of the top numMatchesSaved matches for every client, in the form of Map<Client, Map<Match Score, Animal Matched>>
    QMap<Client*, QMap<float, Animal*>> clientMatches;

    vector<Client*> usableClients;

    for (auto client : clients){
      if(client->getMatchingPrefs().isEmpty()){
          qDebug() << "Client " << client->getFname() << " cannot be used as it has no Matching Prefs";
        }
        else{
          usableClients.insert(usableClients.end(),client);
        }
    }

  //The numMatchesSaved is the lesser of clients or animals as we want at most that many matches
  int numMatchesSaved = (usableClients.size() < animals.size()) ? usableClients.size() : animals.size();

  qDebug()<<"There are "<<usableClients.size() << "usable clients out of" << clients.size() << "clients";

  //For every client and every animal, run the match algorithm and saved the top numSavedMatches matches for each client.
    for (auto client : usableClients){
        for (auto animal : animals){
            qDebug() << "\nRunning ACM on " << client->getFname() << " and " << animal->getName() << " numMatchesSaved: " << numMatchesSaved;
            float matchScore = runACMOnPair(animal, client);
            if(matchScore != -100){
                //If there are currently less matches saved than numMatchesSaved
                if (clientMatches[client].count() < numMatchesSaved){
                    qDebug() << client->getFname() << " " << client->getLname() << " matched with: " << animal->getName() << " score: " << matchScore;
                    clientMatches[client].insert(matchScore,animal);
                }else{
                    int worst = 0;

                    //Pop is a boolean (0 false, 1 true) value indicating whether the current matchScore is going to be popping an
                    //existing match score from clientMatches[client]
                    int pop = 0;
                    for (auto key : clientMatches[client].keys()){
                        if (matchScore >= key && pop == 0){
                            pop = 1;
                            worst = key;
                        }else if (key < worst){
                            worst = key;
                            pop = 1;
                        }
                    }

                    //If pop == 1 then we need to remove the worst score and add in the key (current animal) score
                    if (pop == 1){
                        qDebug() << "Unmatching " << client->getFname() << " " << client->getLname() << " and " << clientMatches[client][worst]->getName() << " score: " << worst;
                        clientMatches[client].remove(worst);
                        clientMatches[client].insert(matchScore , animal);
                        qDebug() << client->getFname() << " " << client->getLname() << " matched with: " << animal->getName() << " score: " << matchScore;
                    }
                }
            }
        }
	}

    QMap<Animal*,Client*> pairs;
    vector<Client*> exhausted; //Clients who dont have a match
    vector<Client*> lowMatchCount; //Clients who don't have enough matches
    qDebug()<<"Client Name : Match Keys";
    for (size_t i=0; i<usableClients.size(); i++){
        qDebug() << usableClients[i]->getFname() << " : " <<clientMatches[usableClients[i]].keys() ;
        for(auto key : clientMatches[usableClients[i]].keys()){
          qDebug() <<"  "<< key << " : " << clientMatches[usableClients[i]][key]->getName();
        }
        if (clientMatches[usableClients[i]].keys().size() < numMatchesSaved){
          lowMatchCount.insert(lowMatchCount.end(), clients[i]);
        }
    }


    int iteration = 0;
    //While we dont have enough matches + clients without possible matches
    while (pairs.count() < (numMatchesSaved - static_cast<int>(exhausted.size()))) {
        for (size_t i=0; i<usableClients.size(); i++){
            Client* client = usableClients[i];
            qDebug()<< "Current Client is " << client->getFname() << " In pairs " << pairs.values().count(client) << " time(s)";

            //Only look to add this client if they don't already exist in pairs
            if (pairs.values().count(client) == 0){
                //For all scores in decrementing order
                for (int i=clientMatches[client].keys().size()-1; i>=0; i--){
                    float key = clientMatches[client].keys().at(i);
                    if (clientMatches[client][key] != NULL){
                        Animal* animal = clientMatches[client][key];
                        qDebug() << "       Checking if we can add" << client->getFname() << " with " << animal->getName();

                        //If the pair doesn't contain the animal already, add this match
                        if (!pairs.contains(animal) && pairs.values().count(client) == 0){
                            qDebug() << "       Adding: " << animal->getName() << " with " << client->getFname() << " score: " << key;
                            pairs.insert(animal,client);
                            qDebug() <<"            Done with "<< client->getFname();
				                    break;
                        }
                        else{
                            qDebug() <<"     "<< animal->getName() << "could not be used";
                            std::vector<Client*>::iterator it;
                            it = find (lowMatchCount.begin(), lowMatchCount.end(), pairs[animal]);
                            //If the existing match is worse than the new match, pop it out and replace it with this match
                            if ((key > clientMatches[pairs[animal]].key(animal) && it == lowMatchCount.end()) && pairs.values().count(client) == 0) {
                                qDebug() << "Swapping: " << animal->getName() << " from " << pairs[animal]->getFname() << " to " << client->getFname();
                                pairs.remove(animal);
                                pairs.insert(animal,client);
								                break;
							               }
						             }
        					}
        				}


              Animal * temp = pairs.key(client);

              //If this client doesn't have enough matches and didn't receive a match
              if (clientMatches[client].count() < numMatchesSaved && !temp){
  				          //Check the matches this client does have to see if they have nay good matches
  				        int matchable = 0;
                  for (int i = clientMatches[client].keys().size() -1; i>= 0; i--){
                      int key = clientMatches[client].keys()[i];
                      Animal* animal = clientMatches[client][key];

                      //Grab the existing match for this animal
                      std::vector<Client*>::iterator it;
                      it = find (lowMatchCount.begin(),lowMatchCount.end(), pairs[animal]);

                      //If lowMatchCount does not contain the client this animal is paired with currently, then its safe to remove him for rematching
                      if (it == lowMatchCount.end()) {
                          qDebug() << "Removing " << pairs[animal]->getFname() <<  " Inserting: " << client->getFname();
  						            pairs.remove(animal);
                          pairs.insert(animal,client);
  						            matchable = 1;
                          break;
                        }else {

                          //Otherwise check the existing match old score
                          int oldScore=0;
                          int newScore=0;
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

                          it = find (exhausted.begin(),exhausted.end(), pairs[animal]);

                          //If exhausted does not contain the client this animal is paired with currently, then its safe to remove him for rematching
                          if (newScore > oldScore && it == exhausted.end()){
                            qDebug() << "Senstive: " << animal->getName() << " from " << pairs[animal]->getFname() << " to " << client->getFname();

                            pairs.remove(animal);
                            pairs.insert(animal,client);
          						      matchable = 1;
                            break;
                          }
        					}
        				}
        				if (matchable == 0){
                            qDebug() << client->getFname() << "is unmatchable";
                            exhausted.insert(exhausted.end(),client);
        				}
        			}
            }
          }
        iteration +=1;
        if(iteration == 100){
             qDebug() << "ACM Error!";
             if(pairs.size() == 0){
                QMessageBox::critical(0, "ACM Error","ACM has failed due to an unknown error. Please contact a JSB Member!", QMessageBox::Ok);
             }
             break;
        }
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

    //Grab the trait values and set the pastMatchScore variable
    float clientValue = client->getMatchingPrefs()[trait];
    float animalValue = animal->getTraits()[trait];

    //Loading of animalValue and clientValue, if they are not in traits dict or are not 1:1
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
    else if (trait == "activeness"){
      clientValue = client->getMatchingPrefs()["active"];
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
        //Recall that for older 1 is Y and 2 is N
        //Recall for age that Older is 1 and Younger is 2
        if(animal->getAge() >=5){
          animalValue = 2;
        }
        else if(animal->getAge() < 5){
          animalValue = 1;
        }

        //Take priority that an older animal can go, since they tend to be in shelter longer
        if(client->getMatchingPrefs()["older"] == 1 || client->getMatchingPrefs()["age"] == 1){
          clientValue = 2;
        }
        else{
          clientValue = 1;
        }
    }
    else if(trait == "DoC"){
        clientValue = client->getMatchingPrefs()["experience"];
    }else if (trait == "size" || trait == "affection" || trait == "time" || trait == "space"){
      //qDebug() << " Skipping CV " << clientValue << "...\n" << endl;
    }else if(trait == "colour"){
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
    else if(trait == "intwithdog"){
        // Remember for these 1 is Y and 2 is N
        // -1 so 0 is Y and 1 is N
        // 0 is friendly 1 is not
        clientValue = (client->getMatchingPrefs()["dogs"] == 1 || client->getMatchingPrefs()["dogsfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "intwithcat"){
        clientValue = (client->getMatchingPrefs()["cats"] == 1 || client->getMatchingPrefs()["catsfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "intwithchild"){
        clientValue = (client->getMatchingPrefs()["children"] == 1 || client->getMatchingPrefs()["childrenfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "loudness"){
        // 1 is Minimal, 2 is N/A
        clientValue = (client->getMatchingPrefs()["noise"] == 1) ? 2 : 3;
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



		pastMatchScore = matchScore;


		//Check our cases and compute trait match score
		if (caseDict.value(trait) == 1){
			if (clientValue == animalValue){
				matchScore += (1 * weightDict.value(trait));
      }else if ((((trait == "intwithdog" || trait == "intwithcat" || trait == "intwithchild")) && animalValue != 1) || !(trait == "intwithdog" || trait == "intwithcat" || trait == "intwithchild")){
				matchScore += (-1 * weightDict.value(trait));
      }else{
        qDebug() << "Integration Case Which is not equal +- 0";
      }
		}else if (caseDict.value(trait) == 2){
			matchScore += (((clientValue-animalValue)/clientValue)*weightDict.value(trait));
		}else if (caseDict.value(trait) == 3){
            matchScore += weightDict.value(trait)/(abs(clientValue-animalValue)+1);
		}

		if (pastMatchScore >= (matchScore+5)){
            qDebug() << "Nulled Match: " << client->getFname() << " and " << animal->getName() << "CV: " << clientValue << " AV: " << animalValue <<" trait: " << trait << ": " << (matchScore - pastMatchScore);
            return -100;
        }

    //PRINT the values necessary for the equation
    if (client->getFname() == "Universal"){
      qDebug()<<"Trait: " << trait << " Animal Value is :"<<animalValue<< " " << " Client Value is :"<<clientValue << " case: " << caseDict.value(trait) << " weight: " << weightDict.value(trait) << " score: " << (matchScore - pastMatchScore);
    }
  }
  qDebug() << "Match Score of " << client->getFname() << "and " << animal->getName() << " = " << matchScore;
  return matchScore;
}

QList<QString> ACMAlgorithm::getTraitScores(Animal* animal, Client* client){
	//Variable used to check if a trait match value is <= -5
	float pastMatchScore = 0;

	//Actual Match Score
  float matchScore = 0;
  QList<QString> caseKeys = caseDict.keys();
  QList<QString> traitScores;
  for(int i=0; i<caseKeys.size();i++){
    QString trait = caseKeys[i];

    //Grab the trait values and set the pastMatchScore variable
    float clientValue = client->getMatchingPrefs()[trait];
    float animalValue = animal->getTraits()[trait];

    //Loading of animalValue and clientValue, if they are not in traits dict or are not 1:1
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
    else if (trait == "activeness"){
      clientValue = client->getMatchingPrefs()["active"];
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
        //Recall that for older 1 is Y and 2 is N
        //Recall for age that Older is 1 and Younger is 2
        if(animal->getAge() >=5){
          animalValue = 2;
        }
        else if(animal->getAge() < 5){
          animalValue = 1;
        }

        //Take priority that an older animal can go, since they tend to be in shelter longer
        if(client->getMatchingPrefs()["older"] == 1 || client->getMatchingPrefs()["age"] == 1){
          clientValue = 2;
        }
        else{
          clientValue = 1;
        }
    }
    else if(trait == "DoC"){
        clientValue = client->getMatchingPrefs()["experience"];
    }else if (trait == "size" || trait == "affection" || trait == "time" || trait == "space"){
      //qDebug() << " Skipping CV " << clientValue << "...\n" << endl;
    }else if(trait == "colour"){
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
    else if(trait == "intwithdog"){
        // Remember for these 1 is Y and 2 is N
        // -1 so 0 is Y and 1 is N
        // 0 is friendly 1 is not
        clientValue = (client->getMatchingPrefs()["dogs"] == 1 || client->getMatchingPrefs()["dogsfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "intwithcat"){
        clientValue = (client->getMatchingPrefs()["cats"] == 1 || client->getMatchingPrefs()["catsfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "intwithchild"){
        clientValue = (client->getMatchingPrefs()["children"] == 1 || client->getMatchingPrefs()["childrenfuture"] == 1) ? 1 : 0;
    }
    else if(trait == "loudness"){
        // 1 is Minimal, 2 is N/A
        clientValue = (client->getMatchingPrefs()["noise"] == 1) ? 2 : 3;
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



		pastMatchScore = matchScore;

    QString currentTraitScore;
    QString equation;
		//Check our cases and compute trait match score
		if (caseDict.value(trait) == 1){
			if (clientValue == animalValue){
				matchScore += (1 * weightDict.value(trait));
                equation = QString::number(matchScore) + " += 1 x " + QString::number(weightDict.value(trait));
      }else if ((((trait == "intwithdog" || trait == "intwithcat" || trait == "intwithchild")) && animalValue != 1) || !(trait == "intwithdog" || trait == "intwithcat" || trait == "intwithchild")){
				matchScore += (-1 * weightDict.value(trait));
                equation = QString::number(matchScore) + " += -1 x " + QString::number(weightDict.value(trait));
      }else{
        qDebug() << "Integration Case Which is not equal +- 0";
        equation = QString::number(matchScore) + " += 0";
      }
		}else if (caseDict.value(trait) == 2){
			matchScore += (((clientValue-animalValue)/clientValue)*weightDict.value(trait));
            equation = QString::number(matchScore) + " += (((" + QString::number(clientValue) + " - " + QString::number(animalValue) + ") x " + QString::number(weightDict.value(trait)) + "))";
		}else if (caseDict.value(trait) == 3){
            matchScore += weightDict.value(trait)/(abs(clientValue-animalValue)+1);
            equation = QString::number(matchScore) + " += " + QString::number(weightDict.value(trait)) + " / (ABS(" + QString::number(clientValue) + " - " + QString::number(animalValue) + ") +1)";
		}

		if (pastMatchScore >= (matchScore+5)){
      traitScores.insert(traitScores.size(), "This match is invalid!");
      return traitScores;
    }


    currentTraitScore.append("Score for ");
    currentTraitScore.append(trait);
    currentTraitScore.append("\n");
    currentTraitScore.append("Trait Weight : ");
    currentTraitScore.append(QString::number(weightDict.value(trait)));
    currentTraitScore.append("\n");
    currentTraitScore.append(" Animal Value: ");
    currentTraitScore.append(QString::number(animalValue));
    currentTraitScore.append("\n");
    currentTraitScore.append(" Client Value: ");
    currentTraitScore.append(QString::number(clientValue));
    currentTraitScore.append("\n");
    currentTraitScore.append(" Case : ");
    currentTraitScore.append(QString::number(caseDict.value(trait)));
    currentTraitScore.append("\n");
    currentTraitScore.append(" Equation : ");
    currentTraitScore.append(equation);
    currentTraitScore.append("\n");
    currentTraitScore.append(" Trait Score =");
    currentTraitScore.append(QString::number(matchScore-pastMatchScore));
    traitScores.insert(traitScores.size(), currentTraitScore);
  }

  return traitScores;
}
