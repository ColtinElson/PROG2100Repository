#include "Human.h"

Human::Human() {
    color = 5;
    symbol = 79;
}

Human::Human(City *city, int width, int height):Organism(city, width, height) {

}

Human::~Human() {

}

void Human::move(City *city, int x, int y) {
    if (!moved) {

        ageSinceBreed++;

        Move move = randomMove(v);

        switch (move) {

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
                if (y != GRID_WIDTH){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        makeMove(city, this, x, y, newX, newY);
                    }
                }
                break;
            case SOUTH:
                if (x != GRID_HEIGHT){
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

int Human::getSpecies() {
    return 1;
}

void Human::breed(City *city, int x, int y) {
    if (ageSinceBreed >= 3) {
        ageSinceBreed = 0;

        Move move = randomMove(v);
        switch (move) {

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
                if (y != GRID_WIDTH){
                    int newX = x;
                    int newY = y+1;
                    if (city->getOrganism(newX, newY) == nullptr) {
                        city->setOrganism(new Human(), newX, newY);
                    }
                }
                break;
            case SOUTH:
                if (x != GRID_HEIGHT){
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
