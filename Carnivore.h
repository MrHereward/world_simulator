#pragma once

#include "Animal.h"

class Carnivore : public Animal {
    public:
        Carnivore(int, int, int, char, OrganismsManager*, Sex);

        virtual ~Carnivore() = default;
};