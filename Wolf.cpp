#include "Wolf.h"

#include "OrganismsManager.h"
#include "Herbivore.h"

#include <cstdlib>

Wolf::Wolf(int positionX, int positionY, OrganismsManager* organismsManager) {
    this->positionX = positionX;
    this->positionY = positionY;
    this->energy = 0;
    this->symbol = 'W';
    this->organismsManager = organismsManager;
}

void Wolf::breed() const {
    organismsManager->addOrganism(new Wolf(positionX, positionY, organismsManager));
}

void Wolf::move(Map* map) {
    int x;
    int y;

    do {
        x = -1 + rand() % 3;
        y = -1 + rand() % 3;
    } while (positionX + x < 0 || positionX + x >= map->getWidth() || positionY + y < 0 || positionY + y >= map->getLength());

    positionX += x;
    positionY += y;
}

void Wolf::interact(Organism* organism) {
    if (auto wolf = dynamic_cast<Wolf*>(organism)) {
        if (energy >= 50 && wolf->getEnergy() >= 50) {
            breed();
            energy -= 50;
            wolf->setEnergy(wolf->getEnergy() - 50);
        }
    } else if (auto herbivore = dynamic_cast<Herbivore*>(organism)) {
        eat(herbivore);
        energy += 50;
    }
}

void Wolf::eat(Organism* herbivore) {
    organismsManager->removeOrganism(herbivore);
}
