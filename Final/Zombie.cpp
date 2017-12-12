#include "Zombie.h"

Zombie::Zombie() {
    //set zombies color, symbol and age
    color = 2;
    symbol = 90;
    age = 0;
}

Zombie::Zombie(City* city, int width, int height):Organism(city,width,height){

}

Zombie::~Zombie() {

}

void Zombie::move(City *city, int x, int y) {
    //if the zombie hasn't moved
    if (!moved) {

        //increase age since bred and age
        this->setAgeSinceBreed(this->getAgeSinceBreed()+1);
        this->setAge(this->getAge()+1);

        //get random move *including diagonal*
        Move move = randomMove(v);

        switch (move) {

            //In all cases, zombie checks to see if there is a cell in the given direction
                //if there is an empty spot and the zombie has eaten recently, move there
                //if there is an empty spot but it hasn't eaten, make a new human there
                //if there is a human there, destroy the human and move there, resetting age

            case WEST:
                if (y != 0){
                    int newX = x;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case NORTH:
                if (x != 0){
                    int newX = x-1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case EAST:
                if (y != GRID_WIDTH-1){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case SOUTH:
                if (x != GRID_HEIGHT-1){
                    int newX = x+1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case NORTHWEST:
                if (x != 0 && y != 0){
                    int newX = x-1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case NORTHEAST:
                if (x != 0 && y != GRID_WIDTH-1){
                    int newX = x-1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }

                }
                break;
            case SOUTHWEST:
                if (x != GRID_HEIGHT-1 && y != 0){
                    int newX = x+1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }
                }
                break;
            case SOUTHEAST:
                if (x != GRID_HEIGHT-1 && y != GRID_WIDTH-1){
                    int newX = x+1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        if (this->getAge() >= 3) {
                            makeMove(city, new Human(), x, y, newX, newY);
                        }
                        else {
                            makeMove(city, this, x, y, newX, newY);
                        }
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        this->setAge(0);
                        delete city->getOrganism(newX, newY);
                        makeMove(city, this, x, y, newX, newY);

                    }
                }
                break;
        }
    }
}

//return 2 as species
int Zombie::getSpecies() {
    return 2;
}

void Zombie::breed(City *city, int x, int y) {
    //if the zombie hasn't bred in 8 turns (or longer if couldn't breed before)
    if (this->getAgeSinceBreed() >= 8) {

        //get random move
        Move move = randomMove(v);

        switch (move) {

            //in all cases zombie checks to see if there is a cell in the given direction
            //if there is an open cell, it makes a new zombie there
            //if there is a human there, it turns that human into a zombie

            case WEST:
                if (y != 0){
                    int newX = x;
                    int newY = y -1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case NORTH:
                if (x != 0){
                    int newX = x-1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case EAST:
                if (y != (GRID_WIDTH-1)){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case SOUTH:
                if (x != (GRID_WIDTH-1)){
                    int newX = x+1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case NORTHWEST:
                if (x != 0 && y != 0){
                    int newX = x-1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case NORTHEAST:
                if (x != 0 && y != (GRID_WIDTH-1)){
                    int newX = x-1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case SOUTHWEST:
                if (x != (GRID_WIDTH-1) && y != 0){
                    int newX = x+1;
                    int newY = y-1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
            case SOUTHEAST:
                if (x != (GRID_WIDTH-1) && y != (GRID_WIDTH-1)){
                    int newX = x+1;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr){
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                    else if (city->getOrganism(newX, newY)->getSpecies() == 1) {
                        city->setOrganism(new Zombie(), newX, newY);
                        this->setAgeSinceBreed(0);
                    }
                }
                break;
        }
    }
}



