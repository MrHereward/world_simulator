#include "Plant.h"

Plant::Plant(int positionX, int positionY, int energy, char symbol, OrganismsManager* organismsManager)
    : Organism(positionX, positionY, energy, symbol, organismsManager) {
}