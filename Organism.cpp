#include "Organism.h"

Organism::Organism(int positionX, int positionY, int energy, char symbol, OrganismsManager* organismsManager) 
    : positionX{ positionX }, positionY{ positionY }, energy{ energy }, symbol{ symbol }, organismsManager{ organismsManager } {
}

int Organism::getPositionX() const {
    return positionX;
}

void Organism::setPositionX(int newPositionX) {
    positionX = newPositionX;
}

int Organism::getPositionY() const {
    return positionY;
}

void Organism::setPositionY(int newPositionY) {
    positionY = newPositionY;
}

int Organism::getEnergy() const {
    return energy;
}

void Organism::setEnergy(int newEnergy) {
    energy = newEnergy;
}

char Organism::getSymbol() const {
    return symbol;
}