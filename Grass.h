#pragma once

#include "Plant.h"

class Grass : public Plant {
    public:
        Grass(int, int, OrganismsManager*);

        void proliferate(Map*) const override;

        ~Grass();
    
    private:
        static int amountOfInstances;
};