#ifndef ACMALGORITHM_H
#define ACMALGOIRTHM_H

#include <Shelter.h>
#include <Client.h>
#include <Animal.h>
#include <Dog.h>
#include <Cat.h>
#include <Bird.h>
#include <SmallPet.h>
#include "qmap.h"

class ACMAlgorithm{

	public:
		ACMAlgorithm();
		~ACMAlgorithm();
		Map<Animal, Client> runACM();

	private:
		int runACMOnPair(Animal, Client);
		QMap<String, Int> caseDict;
		QMap<String, Int> weightDict;

};

#endif
