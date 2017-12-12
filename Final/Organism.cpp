#include <algorithm>
#include "Organism.h"

Organism::Organism() {

}

Organism::Organism(City *city, int width, int height) {

}

Organism::~Organism() {

}


void Organism::newTurn() {
    moved = false;
}


ostream &operator<<(ostream &output, Organism *organism) {
    organism->textcolor(BRIGHT, organism->color, WHITE);
    output << (char) organism->symbol;
    organism->textcolor(RESET, BLACK, WHITE);
    return output;
}

//Code from No2Pencil at http://www.dreamincode.net/forums/topic/92900-rock-paper-scissors-multi-os-console/
void Organism::textcolor(int attribute, int textColor, int backgroundColor) {

    char command[13];

    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attribute, textColor + 30, backgroundColor + 40);

    printf("%s", command);

}


void Organism::makeMove(City *city, Organism *organism, int x, int y, int newX, int newY) {
    if (!moved) {
        city->setOrganism(organism, newX, newY);
        city->setOrganism(nullptr, x, y);
        moved=true;
    }

}

Organism::Move Organism::randomMove(vector<int> v) {
    random_shuffle(v.begin(), v.end());
    return (Move)v.front();
}

int Organism::getAge() const {
    return age;
}

void Organism::setAge(int age) {
    Organism::age = age;
}

int Organism::getAgeSinceBreed() const {
    return ageSinceBreed;
}

void Organism::setAgeSinceBreed(int ageSinceBreed) {
    Organism::ageSinceBreed = ageSinceBreed;
}




