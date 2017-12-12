#include "City.h"

City::City() {
}

City::~City() {

}

Organism *City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

void City::move() {

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->move(this, i,j);
            }
            else {
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->getOrganism(i,j) != nullptr) {
                this->getOrganism(i,j)->endTurn();
            }
            else {
            }
        }
    }
}

ostream &operator<<(ostream &output, City &city) {
}
