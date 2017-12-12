#include <random>
#include "City.h"

City::City() {
    //make a new board of all null values
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            setOrganism(nullptr, i, j);
        }
    }
}

City::~City() {
    //destroy all objects in board
for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (getOrganism(i,j) != nullptr) {
                delete getOrganism(i,j);
            }

        }
    }

}
//get organism in cell
Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

//set organism in cell
void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

void City::move() {
    //first, reset all moved values to false

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->newTurn();
            }
            else {
            }
        }
    }

    //next, move all organisms
    //for zombies, this includes eating and dying

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->move(this, i,j);
            }
        }
    }

    //finally, breed all organisms

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->breed(this, i,j);
            }
        }
    }

}

ostream &operator<<(ostream &output, City &city) {
}
