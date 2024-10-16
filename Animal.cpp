#include "Animal.h"

Animal::Animal(int positionX, int positionY, int energy, char symbol, OrganismsManager* organismsManager, Sex sex) 
    : Organism(positionX, positionY, energy, symbol, organismsManager), sex{ sex } {
}

Sex Animal::getSex() const {
    return sex;
}
