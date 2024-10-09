#pragma once

#include "Map.h"

#include <vector>

class OrganismsManager {
    public:
        OrganismsManager(Map*);

        void move();
        void interact();
        void addOrganism(Organism*);
        void removeOrganism(Organism*);

        ~OrganismsManager();

    private:
        Map* map;
        std::vector<Organism*> organisms;
};