#include <iostream>
#include <random>
#include <ctime>

#include "Human.h"
#include "City.h"
#include "Zombie.h"

void populateBoard(int numHumans, int numZombies, City *city);
void printBoard(City *city);

using namespace std;

int main() {
    int turnCount = 0;
    int numHumans = 100;
    int numZombies = 5;
    City *city = new City();

    populateBoard(numHumans, numZombies, city);

    float a=clock();
    while(turnCount < 100)
    {
        while((clock()-a)>= 3000000){
            int clear = 5;
            do {
                cout << endl;
                clear -= 1;
            } while (clear !=0);
            turnCount++;
            cout << "Turns: " << turnCount << endl;

            printBoard(city);

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
    uniform_int_distribution<int> dist(0, 20);

    for (int i = 0; i <= numHumans; i++) {
        Organism *human = new Human();
        while(!organismAdded) {

            int randX = dist(mt);
            int randY = dist(mt);
            if (city->getOrganism(randX, randY) == nullptr) {
                city->setOrganism(human, randX, randY);
                organismAdded = true;
            }
        }
        organismAdded = false;
    }

    for (int i = 0; i <= numZombies; i++) {
        Organism *zombie = new Zombie();
        while(!organismAdded) {

            int randX = dist(mt);
            int randY = dist(mt);
            if (city->getOrganism(randX, randY) == nullptr) {
                city->setOrganism(zombie, randX, randY);
                organismAdded = true;
            }
        }
        organismAdded = false;
    }
}

void printBoard(City *city) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (city->getOrganism(i,j) != nullptr) {
                cout << city->getOrganism(i,j);
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
