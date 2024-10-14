#pragma once

#include "Animal.h"

class Herbivore : public Animal {
    public:
        Herbivore(int, int, int, char, OrganismsManager*, Sex);

        virtual ~Herbivore() = default;
};