#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include "Organism.h"

using namespace std;

const int GRID_WIDTH = 5;
const int GRID_HEIGHT = 5;

class Organism;
class Human;
class Zombie;

class City
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	City();
	virtual ~City();

	Organism *getOrganism( int x, int y );

	void setOrganism(Organism *organism, int x, int y );

	void move();

	friend ostream& operator<<( ostream &output, City &city );

};

#endif

