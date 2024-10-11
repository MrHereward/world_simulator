#include "OrganismsManager.h"

#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"

#include <algorithm>

OrganismsManager::OrganismsManager(Map* map)
    : map{ map } {
    addOrganism(new Sheep(0, 0, this));
    addOrganism(new Sheep(0, 0, this));
    addOrganism(new Sheep(0, 0, this));
    addOrganism(new Sheep(0, 0, this));
    addOrganism(new Sheep(0, 0, this));
    addOrganism(new Grass(5, 5, this));
}

void OrganismsManager::update() {
    for (auto& organism : organisms) {
        if (auto animal = dynamic_cast<Animal*>(organism)) {
            map->removeOrganism(animal);
            animal->move(map);
            map->addOrganism(animal);

            for (auto& otherOrganism : organisms) {
                if (organism != otherOrganism && 
                organism->getPositionX() == otherOrganism->getPositionX() && 
                organism->getPositionY() == otherOrganism->getPositionY()) {
                    animal->interact(otherOrganism);
                }
            }
        } else if (auto plant = dynamic_cast<Plant*>(organism)) {
            plant->proliferate(map);
        }
    }
}

void OrganismsManager::addOrganism(Organism* organism) {
    organisms.push_back(organism);
    map->addOrganism(organism);
}

void OrganismsManager::removeOrganism(Organism* organism) {
    map->removeOrganism(organism);
    organisms.erase(std::remove(organisms.begin(), organisms.end(), organism));
    delete organism;
}

OrganismsManager::~OrganismsManager() {
    for (auto& organism : organisms) {
        delete organism;
    }
}
