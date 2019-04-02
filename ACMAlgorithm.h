#ifndef ACMALGORITHM_H
#define ACMALGORITHM_H

#include <Shelter.h>
#include <Client.h>
#include <Animal.h>
#include <Dog.h>
#include <Cat.h>
#include <Bird.h>
#include <SmallAnimal.h>
#include "qmap.h"

class ACMAlgorithm{

	public:
		ACMAlgorithm();
		~ACMAlgorithm();
        QMap<Animal*, Client*> runACM(vector<Client*>,vector<Animal*>);
        int runACMOnPair(Animal*, Client*);

	private:
        QMap<QString, int> caseDict;
        QMap<QString, int> weightDict;

};

#endif
