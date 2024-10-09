#pragma once

#include "Animal.h"

class Carnivore : public Animal {
    public:
        virtual void eat(Organism*) = 0;

        virtual ~Carnivore() = default;
};