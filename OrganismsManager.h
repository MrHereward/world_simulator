#pragma once

#include "Map.h"

#include <vector>

class OrganismsManager {
    public:
        OrganismsManager(Map*);

        void addOrganism(Organism*);
        void removeOrganism(Organism*);
        void update();

        ~OrganismsManager();

    private:
        Map* map;
        std::vector<Organism*> organisms;
};