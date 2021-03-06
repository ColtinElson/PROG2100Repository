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
    //start at 0 turns and set up board
    int turnCount = 0;
    City *city = new City();

    populateBoard(numHumans, numZombies, city);

    //get the time
    float a=clock();
    //while the turn count is less than 10000 (essentially forever)
    while(turnCount < 10000)
    {
        //while 250 milliseconds have passed
        while((clock()-a)>= 250000){
            //clear screen
            int clear = 5;
            do {
                cout << endl;
                clear -= 1;
            } while (clear !=0);

            //print the board and update turn count
            turnCount = printBoard(city, turnCount);

            //move all organisms
            city->move();

            //update time
            a=clock();
        }

    }

    return 0;
}

void populateBoard(int numHumans, int numZombies, City *city) {
    //create random number generator
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, GRID_HEIGHT);

    //add 100 humans randomly
    int humansAdded = 0;
    while (humansAdded < numHumans) {
        int randX = dist(mt);
        int randY = dist(mt);
        if (city->getOrganism(randX, randY) == nullptr) {
            city->setOrganism(new Human(), randX, randY);
            humansAdded++;
        }
    }

    //add 5 zombies randomly
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
    //update and print turncount
    turnCount++;
    cout << "Turns: " << turnCount << endl;
    bool humanAlive = false;
    bool zombieAlive = false;
    //print each cell individually, checking what it is
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
    //if there are no humans or zombies left, an ELE has occurred and the game ends
    if (!humanAlive || !zombieAlive) {
        cout << "GAME OVER! Extinction Level Event has occured at turn: " << turnCount << endl;
        turnCount = 10000;
    }
    return turnCount;
}
