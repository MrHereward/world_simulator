#pragma once

#include "Organism.h"

#include <vector>

class Map {
    public:
        Map(int, int);

        void addOrganism(Organism*);
        void removeOrganism(Organism*);
        void print() const;

        int getLength() const;
        int getWidth() const;

        ~Map() = default;
        
    private:
        std::vector<std::vector<std::vector<Organism*>>> grid;

        const int length;
        const int width;
};
