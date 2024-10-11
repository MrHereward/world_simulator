#include "Grass.h"
#include "OrganismsManager.h"

#include <cstdlib>

Grass::Grass(int positionX, int positionY, OrganismsManager* organismsManager) {
    this->positionX = positionX;
    this->positionY = positionY;
    this->energy = 0;
    this->symbol = 'G';
    this->organismsManager = organismsManager;
}

void Grass::proliferate(Map* map) {
    int x;
    int y;

    if (rand() % 10 == 0) {
        do {
            x = -1 + rand() % 3;
            y = -1 + rand() % 3;
        } while (positionX + x < 0 || positionX + x >= map->getWidth() || positionY + y < 0 || positionY + y >= map->getLength());

        organismsManager->addOrganism(new Grass(positionX + x, positionY + y, organismsManager));
    }
}
