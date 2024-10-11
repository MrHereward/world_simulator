#pragma once

#include "Herbivore.h"

class Sheep : public Herbivore {
    public:
        Sheep(int, int, OrganismsManager*);

        void breed() const override;
        void move(Map*) override;
        void interact(Organism*) override;
        void eat(Organism*) override;

        ~Sheep() = default;
};