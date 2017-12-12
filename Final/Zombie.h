#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"
#include "City.h"

class Zombie : public Organism
{
protected:
    vector<int> v { 0,1,2,3,4,5,6,7 };
public:

	Zombie();
	Zombie( City *city, int width, int height );

    ~Zombie() override;

	void move(City *city, int x, int y) override;

};

#endif
