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
    this->sex = rand() % 1 == 0 ? Sex::male : Sex::female;
}

Sheep::Sheep(int positionX, int positionY, OrganismsManager* organismsManager, Sex sex)
    : Sheep(positionX, positionY, organismsManager) {
    this->sex = sex;
}

void Sheep::breed(Animal* animal) {
    if (energy >= 50 && animal->getEnergy() >= 50  && sex != animal->getSex()) {
        energy -= 50;
        animal->setEnergy(animal->getEnergy() - 50);
        organismsManager->addOrganism(new Sheep(positionX, positionY, organismsManager));
    }
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
        breed(sheep);
    } else if (auto plant = dynamic_cast<Grass*>(organism)) {
        eat(plant);
    }
}

void Sheep::eat(Organism* organism) {
    energy += 50;
    organismsManager->removeOrganism(organism);
}
