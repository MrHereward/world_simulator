#pragma once

#include "Map.h"
#include "OrganismsManager.h"

class WorldSimulator {
    public:
        WorldSimulator();

        void run();

        ~WorldSimulator();
    
    private:
        Map* map;
        OrganismsManager* organismsManager;
};