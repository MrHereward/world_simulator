#pragma once

#include "Organism.h"
#include "Map.h"

class Animal : public Organism {
    public:
        virtual void move(Map* map) = 0;
        virtual void interact(Organism* organism) = 0;

        virtual ~Animal() = default;
};