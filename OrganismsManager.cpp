#include "OrganismsManager.h"

#include "Animal.h"
#include "Sheep.h"
#include "Wolf.h"

#include <algorithm>

OrganismsManager::OrganismsManager(Map* map)
    : map{ map } {
    organisms.push_back(new Sheep(0, 0, this));
    organisms.push_back(new Wolf(0, 0, this));
}

void OrganismsManager::move() {
    for (auto& organism : organisms) {
        if (auto animal = dynamic_cast<Animal*>(organism)) {
            map->removeOrganism(animal);
            animal->move(map);
            map->addOrganism(animal);
        }
    }
}

void OrganismsManager::interact() {
    for (auto& organism : organisms) {
        if (auto animal = dynamic_cast<Animal*>(organism)) {
            for (auto& otherOrganism : organisms) {
                if (organism != otherOrganism && 
                organism->getPositionX() == otherOrganism->getPositionX() && 
                organism->getPositionY() == otherOrganism->getPositionY()) {
                    animal->interact(otherOrganism);
                }
            }
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
