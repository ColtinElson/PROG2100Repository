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
                    if (city->getOrganism(x, y-1) == nullptr) {
                        makeMove(city, this, x, y, x, y-1);
                    }
                }
                break;
            case NORTH:
                if (x != 0){
                    if (city->getOrganism(x-1, y) == nullptr) {
                        makeMove(city, this, x, y, x-1, y);
                    }
                }
                break;
            case EAST:
                if (y != GRID_WIDTH){
                    if (city->getOrganism(x, y+1) == nullptr) {
                        makeMove(city, this, x, y, x, y+1);
                    }
                }
                break;
            case SOUTH:
                if (x != GRID_HEIGHT){
                    if (city->getOrganism(x+1, y) == nullptr) {
                        makeMove(city, this, x, y, x+1, y);
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

}

