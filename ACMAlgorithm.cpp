#include <ACMAlgirithm.h>
#include "qmap"
#include <vector>


using namespace std;

//Constructor for the ACM Algorithm
ACMAlgorithm::ACMAlgorithm() {
	cout << "ACM Algorithm Constructued" << endl;
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


QMap<Animal*, Client> ACMAlgorithm::runACM(){
	
}

int ACMAlgorithm::runACMOnPair(animal, client){
	//Variable used to check if a trait match value is <= -5
	int pastMatchScore = 0;

	//Actual Match Score
	int matchScore = 0
	for (auto trait : caseDict.keys()){
		
		//Grab the trait values and set the pastMatchScore variable
		clientValue = client.getTraits().at(trait);
		animalValue = animal.getTraits().at(trait);
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
			matchScore += weightDict.value(trait)/(ABS(clientValue-animalValue)+1);
		}

		if (pastMatchScore >= (matchScore+5)){
			return null;
		}
		return matchScore;
	}
	
}
