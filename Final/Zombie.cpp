#include "Zombie.h"

Zombie::Zombie() {
    color = 2;
    symbol = 90;
    age = 0;
}

Zombie::Zombie(City* city, int width, int height):Organism(city,width,height){

}

Zombie::~Zombie() {

}

void Zombie::move(City *city, int x, int y) {
    if (!moved) {

        ageSinceBreed++;
        age++;

        Move move = randomMove(v);

        switch (move) {

            case WEST:
                if (y != 0){
                    int newX = x;
                    int newY = y -1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case NORTH:
                if (x != 0){
                    int newX = x-1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case EAST:
                if (y != GRID_WIDTH){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case SOUTH:
                if (x != GRID_HEIGHT){
                    int newX = x+1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case NORTHWEST:
                if (x != 0 && y != 0){
                    int newX = x-1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case NORTHEAST:
                if (x != 0 && y != GRID_WIDTH){
                    int newX = x-1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case SOUTHWEST:
                if (x != GRID_HEIGHT && y != 0){
                    int newX = x+1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case SOUTHEAST:
                if (x != GRID_HEIGHT && y != GRID_WIDTH){
                    int newX = x+1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr || city->getOrganism(newX, newY)->getSpecies() == 1) {
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
        }
    }
}

int Zombie::getSpecies() {
    return 2;
}

void Zombie::breed(City *city, int x, int y) {

}





