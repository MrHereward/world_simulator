#pragma once

#include "Organism.h"
#include "Map.h"

class Plant : public Organism {
    public:
        Plant(int, int, int, char, OrganismsManager*);

        virtual void proliferate(Map*) = 0;

        virtual ~Plant() = default;
};