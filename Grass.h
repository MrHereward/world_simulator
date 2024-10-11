#pragma once

#include "Plant.h"

class Grass : public Plant {
    public:
        Grass(int, int, OrganismsManager*);

        void proliferate(Map*) override;

        ~Grass() = default;
};