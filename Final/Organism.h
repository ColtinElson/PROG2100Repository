#ifndef _Organism_H
#define _Organism_H

#include <vector>
#include <iostream>
#include "City.h"

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
	int color;
	int symbol = 32;
public:
	int getSymbol() const;

public:
	void setSymbol(int symbol);

protected:
	int width;
	int height;
	bool moved;

	enum Move { WEST, NORTH, EAST, SOUTH, NORTHWEST, NORTHEAST, SOUTHWEST, SOUTHEAST };

public:

#define RESET           0
#define BRIGHT          1
#define DIM             2
#define UNDERLINE       3
#define BLINK           4
#define REVERSE         7
#define HIDDEN          8

#define BLACK           0
#define RED             1
#define GREEN           2
#define YELLOW          3
#define BLUE            4
#define MAGENTA         5
#define CYAN            6
#define GREY            7
#define WHITE           8

	Organism();
	Organism(City *city, int width, int height );
	virtual ~Organism();

	virtual void move(City *city, int x, int y) = 0;

    Move randomMove(vector<int> v);

    void makeMove(City *city, Organism *organism, int x, int y, int newX, int newY);

    int ageSinceBreed = 0;

	virtual void breed(City *city, int x, int y) = 0;

	//virtual void spawn() = 0;
	virtual int getSpecies() = 0;
	//virtual void getPosition() = 0;

	void setPosition( int x, int y );
	void newTurn();
	bool isTurn();
	void textcolor(int attribute, int textColor, int backgroundColor);

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
