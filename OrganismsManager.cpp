#include "OrganismsManager.h"

#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"

#include <algorithm>

OrganismsManager::OrganismsManager(Map* map)
    : map{ map } {
    addOrganism(new Sheep(0, 0, this, Sex::male));
    addOrganism(new Sheep(0, 0, this, Sex::male));
    addOrganism(new Sheep(1, 1, this, Sex::male));
    addOrganism(new Sheep(1, 1, this, Sex::female));
    addOrganism(new Sheep(2, 2, this, Sex::female));
    addOrganism(new Sheep(2, 2, this, Sex::female));
    addOrganism(new Grass(0, 0, this));
    addOrganism(new Grass(2, 2, this));
    addOrganism(new Grass(5, 5, this));
    addOrganism(new Grass(7, 7, this));
    addOrganism(new Grass(9, 9, this));
    addOrganism(new Wolf(9, 9, this, Sex::male));
    addOrganism(new Wolf(9, 9, this, Sex::female));
}

void OrganismsManager::update() {
    for (int i = 0; i < organisms.size(); ++i) {
        if (auto animal = dynamic_cast<Animal*>(organisms[i])) {
            map->removeOrganism(animal);
            animal->move(map);
            map->addOrganism(animal);

            for (int j = 0; j < organisms.size(); ++j) {
                if (i != j && 
                animal->getPositionX() == organisms[j]->getPositionX() && 
                animal->getPositionY() == organisms[j]->getPositionY()) {
                    animal->interact(organisms[j]);
                }
            }
        } else if (auto plant = dynamic_cast<Plant*>(organisms[i])) {
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
