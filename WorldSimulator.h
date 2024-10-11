#pragma once

#include "OrganismsManager.h"
#include "Map.h"

class WorldSimulator {
    public:
        WorldSimulator();

        void run();

        ~WorldSimulator();
    
    private:
        OrganismsManager* organismsManager;
        Map* map;
};