#pragma once

#include "Organism.h"
#include "Map.h"

class Plant : public Organism {
    public:
        virtual void proliferate(Map* map) = 0;

        virtual ~Plant() = default;
};