#include <ACMAlgorithm.h>
#include "qmap.h"
#include <vector>
#include <cstdlib>


using namespace std;

//Constructor for the ACM Algorithm
ACMAlgorithm::ACMAlgorithm() {
    cout << "ACM Algorithm Constructed" << endl;
	caseDict["type"] = 1;
	caseDict["sex"] = 1;
	caseDict["size"] = 1;
	caseDict["colour"] = 1;
	caseDict["age"] = 3;
	caseDict["DoC"] = 2;
	caseDict["Affection"] = 2;
	caseDict["Cost"] = 2;
	caseDict["Time"] = 2;
	caseDict["LifeSpan"] = 3;
	caseDict["Space"] = 2;
	caseDict["Loudness"] = 2;
	caseDict["Activeness"] = 3;
	caseDict["Obedience"] = 3;
	caseDict["Shedding"] = 3;
	caseDict["IntWithDog"] = 1;
	caseDict["IntWithCat"] = 1;
	caseDict["IntWithChild"] = 1;

	weightDict["type"] = 5;
	weightDict["sex"] = 2;
	weightDict["size"] = 4;
	weightDict["colour"] = 1;
	weightDict["age"] = 4;
	weightDict["DoC"] = 5;
	weightDict["Affection"] = 3;
	weightDict["Cost"] = 5;
	weightDict["Time"] = 4;
	weightDict["LifeSpan"] = 4;
	weightDict["Space"] = 5;
	weightDict["Loudness"] = 3;
	weightDict["Activeness"] = 3;
	weightDict["Obedience"] = 3;
	weightDict["Shedding"] = 4;
	weightDict["IntWithDog"] = 5;
	weightDict["IntWithCat"] = 5;
	weightDict["IntWithChild"] = 5;
	
}

ACMAlgorithm::~ACMAlgorithm(){
	cout << "ACM Algorithm Deconstructed" << endl;
}


QMap<Animal*, Client*> ACMAlgorithm::runACM(){
    QMap<Animal*, Client> ACMAlgorithm::runACM(vector<Client*> clients, vector<Animal*> animals){
	QMap<Client, QMap<int, Animal*>> clientMatches;
	int numMatchesSaved = (clients.size() < animals.size()) ? clients.size() : animals.size();

	for (client in clients){	
		for (animal in animals){
			int matchScore = runACMOnPair(animal, client);
			
			if (clientMatches.count <= numMatchesSaved){
				clientMatches[client].insert([matchScore : animal]);
			}else{
				int worst = 0;
				int pop = 0;
				for (auto key : clientMatches[client]){
					if (matchScore >= key && pop == 0){
						pop = 1;
						worst = key;					
					}else if (key < worst){
						worst = key;
					}
				}
				if (pop == 1){
					clientMatches[client].remove(worst);
					clientMatches[client].insert([matchScore : animal]);
				}
			}
		}
	}
	QMap<Animal Client> pairs;
	vector<Client> exhausted; //Clients who dont have a match
	vector<Client> lowMatchCount; //Clients who don't have enough matches
	while ((pairs.size() < numMatchesSaved && pairs.size()) ||  pairs.size() < numMatchesSaved + exhausted.size()){
		for (client in clients){
			if (!pairs.contains(client)){
				for (auto key : clientMatches[client]){ // needs to be sorted order
					if (clientMatches[client][key] != null){
						Animal animal = clientMatches[client][key];
						if (!pairs.value(client).contains(animal)){
							pairs.add([animal : client]);
							break;
						}else{
							if (clientMatches[client] > clientMatches[pairs[animal]] && !exhausted.contains(pairs[animal])){
								pairs.remove(animal);
								pairs.add([animal : client]);
								break;
							}
						}
					}	
				}
			}
			if (clientMatches[client].count() < animals.size() && clientMatches[client].count() < clients.size() && !pairs.contains(client)){
				//Check the matches this client does have to see if they have nay good matches
				int matchable = 0;
				for (auto key : clientMatches[client]){
					Animal animal = clientMatches[client][key]; 
					//If Exhausted does not contain the client this animal is paired with currently, then its safe to remove him for rematching
					if (!lowMatchCount.contains(pair[animal]){
						pairs.remove(animal);
						pairs.add([animal : client]);
						lowMatchCount.add(client);
						matchable = 1;
					}else{
						pairs.remove(animal);
						pairs.add([animal : client]);
						lowMatchCount.add(client);
						lowMatchCount.remove(pair[animal]);
						matchable = 1;
					}
				}
				if (matchable == 0){
					exhausted.add(client);
				}
			}
		}
	}
	
	return pairs;
}
}

int ACMAlgorithm::runACMOnPair(Animal* animal, Client* client){
	//Variable used to check if a trait match value is <= -5
	int pastMatchScore = 0;

	//Actual Match Score
    int matchScore = 0;
	for (auto trait : caseDict.keys()){
		
		//Grab the trait values and set the pastMatchScore variable
        int clientValue = client->getMatchingPrefs()[trait];
        int animalValue = animal->getTraits()[trait];
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
            return -1;
		}
		return matchScore;
	}
    return 0;
}
