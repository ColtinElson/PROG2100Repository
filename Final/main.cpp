#include <iostream>
#include <random>
#include <ctime>

#include "Human.h"
#include "City.h"
#include "Zombie.h"

void populateBoard(int numHumans, int numZombies, City *city);
int printBoard(City *city, int turnCount);

using namespace std;

int main() {
    int turnCount = 0;
    City *city = new City();

    populateBoard(numHumans, numZombies, city);

    float a=clock();
    while(turnCount < 10000)
    {
        while((clock()-a)>= 300000){
            int clear = 5;
            do {
                cout << endl;
                clear -= 1;
            } while (clear !=0);

            turnCount = printBoard(city, turnCount);

            city->move();

            a=clock();
        }

    }

    return 0;
}

void populateBoard(int numHumans, int numZombies, City *city) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, GRID_HEIGHT);

    int humansAdded = 0;
    while (humansAdded < numHumans) {
        int randX = dist(mt);
        int randY = dist(mt);
        if (city->getOrganism(randX, randY) == nullptr) {
            city->setOrganism(new Human(), randX, randY);
            humansAdded++;
        }
    }

    int zombiesAdded = 0;
    while (zombiesAdded < numZombies) {
        int randX = dist(mt);
        int randY = dist(mt);
        if (city->getOrganism(randX, randY) == nullptr) {
            city->setOrganism(new Zombie(), randX, randY);
            zombiesAdded++;
        }
    }
}

int printBoard(City *city, int turnCount) {
    turnCount++;
    cout << "Turns: " << turnCount << endl;
    bool humanAlive = false;
    bool zombieAlive = false;
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (city->getOrganism(i,j) != nullptr) {
                if (city->getOrganism(i,j)->getSpecies() == 1) {
                    humanAlive = true;
                }
                else if (city->getOrganism(i,j)->getSpecies() == 2) {
                    zombieAlive = true;
                }
                cout << city->getOrganism(i,j);
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (!humanAlive || !zombieAlive) {
        cout << "GAME OVER! Extinction Level Event has occured at turn: " << turnCount << endl;
        turnCount = 10000;
    }
    return turnCount;
}
