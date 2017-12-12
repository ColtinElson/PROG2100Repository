#ifndef _Human_H
#define _Human_H


#include "Organism.h"
#include "City.h"

class Human : public Organism
{

protected:
	vector<int> v { 1,3,5,7 };
public:
	Human(); 
	Human( City *city, int width, int height );

	~Human() override;

	void move(City *city, int x, int y) override;

	bool getOrganism(int x, int y);
};

#endif
