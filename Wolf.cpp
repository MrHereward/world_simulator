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
    this->sex = rand() % 1 == 0 ? Sex::male : Sex::female;
}

Wolf::Wolf(int positionX, int positionY, OrganismsManager* organismsManager, Sex sex) 
    : Wolf(positionX, positionY, organismsManager) {
    this->sex = sex;
}

void Wolf::breed(Animal* animal) {
    if (energy >= 50 && animal->getEnergy() >= 50 && sex != animal->getSex()) {
        energy -= 50;
        animal->setEnergy(animal->getEnergy() - 50);
        organismsManager->addOrganism(new Wolf(positionX, positionY, organismsManager));
    }
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
        breed(wolf);
    } else if (auto herbivore = dynamic_cast<Herbivore*>(organism)) {
        eat(herbivore);
    }
}

void Wolf::eat(Organism* herbivore) {
    energy += 50;
    organismsManager->removeOrganism(herbivore);
}
