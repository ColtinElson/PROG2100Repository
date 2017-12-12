#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"
#include "City.h"

class Zombie : public Organism
{
protected:
    int age;
    vector<int> v { 0,1,2,3,4,5,6,7 };
public:

	Zombie();
	Zombie( City *city, int width, int height );

    ~Zombie() override;

	int getSpecies() override;

	void move(City *city, int x, int y) override;

	void breed(City *city, int x, int y) override;

};

#endif
