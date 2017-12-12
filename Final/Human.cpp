#include <algorithm>
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
        if (x == 0) {
            v.erase(std::remove(v.begin(), v.end(), 1), v.end());
        }
        if (x == 20) {
            v.erase(std::remove(v.begin(), v.end(), 5), v.end());
        }
        if (y == 0) {
            v.erase(std::remove(v.begin(), v.end(), 7), v.end());
        }
        if (y == 20) {
            v.erase(std::remove(v.begin(), v.end(), 3), v.end());
        }


        random_shuffle(v.begin(), v.end());
        switch (v.front()) {
            case 1:
                if (city->getOrganism(x - 1, y) != nullptr) {
                    city->setOrganism(this, x - 1, y);
                    city->setOrganism(nullptr, x, y);
                    moved = true;
                    v = {1, 3, 5, 7};
                }
            case 3:
                if (city->getOrganism(x, y + 1) != nullptr) {
                    city->setOrganism(this, x, y + 1);
                    city->setOrganism(nullptr, x, y);
                    moved = true;
                    v = {1, 3, 5, 7};
                }
            case 5:
                if (city->getOrganism(x + 1, y) != nullptr) {
                    city->setOrganism(this, x + 1, y);
                    city->setOrganism(nullptr, x, y);
                    moved = true;
                    v = {1, 3, 5, 7};
                }
            case 7:
                if (city->getOrganism(x, y - 1) != nullptr) {
                    city->setOrganism(this, x, y - 1);
                    city->setOrganism(nullptr, x, y);
                    moved = true;
                    v = {1, 3, 5, 7};
                }
            default:
                cout << "";
        }
        v = {1, 3, 5, 7};
    }
}
