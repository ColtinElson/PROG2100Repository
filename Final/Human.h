#ifndef _Human_H
#define _Human_H


#include "Organism.h"
#include "City.h"

class Human : public Organism
{

protected:
	vector<int> v { 1,2,3,4 };
public:
	Human(); 
	Human( City *city, int width, int height );

	~Human() override;

	void move(City *city, int x, int y) override;

	void breed(City *city, int x, int y) override;

	int getSpecies() override;

};

#endif
