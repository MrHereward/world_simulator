#pragma once

#include "Carnivore.h"

class Wolf : public Carnivore {
    public:
        Wolf(int, int, OrganismsManager*);
        Wolf(int, int, OrganismsManager*, Sex);

        void breed(Animal*) override;
        void move(Map*) override;
        void interact(Organism*) override;
        void eat(Organism*) override;
 
        ~Wolf() = default;
};