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
    int numHumans = 1;
    int numZombies = 1;
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
    bool organismAdded = false;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 5);

    int humansAdded = 0;
    while (humansAdded < numHumans) {
        Human *human = new Human();
        int randX = dist(mt);
        int randY = dist(mt);
        if (city->getOrganism(randX, randY) == nullptr) {
            city->setOrganism(human, randX, randY);
            humansAdded++;
        }
    }

    int zombiesAdded = 0;
    while (zombiesAdded < numZombies) {
        Zombie *zombie = new Zombie();
        int randX = dist(mt);
        int randY = dist(mt);
        if (city->getOrganism(randX, randY) == nullptr) {
            city->setOrganism(zombie, randX, randY);
            zombiesAdded++;
        }
    }
}

int printBoard(City *city, int turnCount) {
    turnCount++;
    cout << "Turns: " << turnCount << endl;
    bool somethingAlive = false;
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (city->getOrganism(i,j) != nullptr) {
                somethingAlive = true;
                cout << city->getOrganism(i,j);
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (!somethingAlive) {
        cout << "GAME OVER! Extinction Level Event has occured at turn: " << turnCount << endl;
        turnCount = 10000;
    }
    return turnCount;
}
