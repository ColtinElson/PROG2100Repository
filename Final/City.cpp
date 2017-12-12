#include <random>
#include "City.h"

City::City() {
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            setOrganism(nullptr, i, j);
        }
    }
}

City::~City() {
for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (getOrganism(i,j) != nullptr) {
                delete getOrganism(i,j);
            }

        }
    }

}

Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

void City::move() {
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->newTurn();
            }
            else {
            }
        }
    }

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->move(this, i,j);
            }
        }
    }
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
