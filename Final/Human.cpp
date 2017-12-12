#include "Human.h"

Human::Human() {
    //set symbol and color value for human
    color = 5;
    symbol = 79;
}

Human::Human(City *city, int width, int height):Organism(city, width, height) {

}

Human::~Human() {

}

void Human::move(City *city, int x, int y) {
    //check if human has moved
    if (!moved) {

        //increase age
        ageSinceBreed++;

        //chose a random move
        Move move = randomMove(v);

        switch (move) {

            //for each move option, check to see if there is an open cell in that direction and move there
            case WEST:
                if (y != 0){
                    int newX = x;
                    int newY = y -1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case NORTH:
                if (x != 0){
                    int newX = x-1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case EAST:
                if (y != (GRID_WIDTH-1)){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case SOUTH:
                if (x != (GRID_WIDTH-1)){
                    int newX = x+1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
        }
    }
}

//return 1 if human
int Human::getSpecies() {
    return 1;
}

void Human::breed(City *city, int x, int y) {
    //if the human hasn't bred in 3 turns
    if (ageSinceBreed >= 3) {
        //reset time to 0
        ageSinceBreed = 0;

        //get random move
        Move move = randomMove(v);
        switch (move) {

            //for all cases, if there is an open spot in the given direction make a new human there
            case WEST:
                if (y != 0){
                    int newX = x;
                    int newY = y -1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        city->setOrganism(new Human(), newX, newY);
                    }
                }
                break;
            case NORTH:
                if (x != 0){
                    int newX = x-1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        city->setOrganism(new Human(), newX, newY);
                    }
                }
                break;
            case EAST:
                if (y != (GRID_WIDTH-1)){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        city->setOrganism(new Human(), newX, newY);
                    }
                }
                break;
            case SOUTH:
                if (x != (GRID_WIDTH-1)){
                    int newX = x+1;
                    int newY = y;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        city->setOrganism(new Human(), newX, newY);
                    }
                }
                break;
        }
    }
}
