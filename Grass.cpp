#include "Grass.h"
#include "OrganismsManager.h"

#include <cstdlib>

int Grass::amountOfInstances = 0;

Grass::Grass(int positionX, int positionY, OrganismsManager* organismsManager)
    : Plant(positionX, positionY, 0, 'G', organismsManager) {
    ++amountOfInstances;
}

void Grass::proliferate(Map* map) const {
    int x;
    int y;

    if (amountOfInstances < 100 && rand() % 10 == 0) {
        do {
            x = -1 + rand() % 3;
            y = -1 + rand() % 3;
        } while (positionX + x < 0 || positionX + x >= map->getWidth() || positionY + y < 0 || positionY + y >= map->getLength());

        organismsManager->addOrganism(new Grass(positionX + x, positionY + y, organismsManager));
    }
}

Grass::~Grass() {
    --amountOfInstances;
}
