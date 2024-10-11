#include "Sheep.h"
#include "OrganismsManager.h"
#include "Grass.h"

#include <cstdlib>

Sheep::Sheep(int positionX, int positionY, OrganismsManager* organismsManager) {
    this->positionX = positionX;
    this->positionY = positionY;
    this->energy = 0;
    this->symbol = 'S';
    this->organismsManager = organismsManager;
}

void Sheep::breed() const {
    organismsManager->addOrganism(new Sheep(positionX, positionY, organismsManager));
}

void Sheep::move(Map* map) {
    int x;
    int y;

    do {
        x = -2 + rand() % 5;
        y = -2 + rand() % 5;
    } while (positionX + x < 0 || positionX + x >= map->getWidth() || positionY + y < 0 || positionY + y >= map->getLength());

    positionX += x;
    positionY += y;
}

void Sheep::interact(Organism* organism) {
    if (auto sheep = dynamic_cast<Sheep*>(organism)) {
        if (energy >= 50 && sheep->getEnergy() >= 50) {
            breed();
            energy -= 50;
            sheep->setEnergy(sheep->getEnergy() - 50);
        }
    } else if (auto plant = dynamic_cast<Grass*>(organism)) {
        eat(organism);
    }
}

void Sheep::eat(Organism* organism) {
    energy += 50;
    organismsManager->removeOrganism(organism);
}
