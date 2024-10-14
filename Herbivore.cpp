#include "Herbivore.h"

Herbivore::Herbivore(int positionX, int positionY, int energy, char symbol, OrganismsManager* organismsManager, Sex sex) 
    : Animal(positionX, positionY, energy, symbol, organismsManager, sex) {
}