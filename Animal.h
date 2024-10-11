#pragma once

#include "Organism.h"
#include "Map.h"

class Animal : public Organism {
    public:
        virtual void breed() const = 0;
        virtual void move(Map*) = 0;
        virtual void interact(Organism*) = 0;
        virtual void eat(Organism*) = 0;

        virtual ~Animal() = default;
};