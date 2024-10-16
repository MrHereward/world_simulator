#pragma once

#include "Organism.h"
#include "Map.h"

enum class Sex : unsigned char {
    male, female
};

class Animal : public Organism {
    public:
        Animal(int, int, int, char, OrganismsManager*, Sex);

        virtual void breed(Animal*) = 0;
        virtual void move(Map*) = 0;
        virtual void interact(Organism*) = 0;
        virtual void eat(Organism*) = 0;

        Sex getSex() const;

        virtual ~Animal() = default;

    protected:
        const Sex sex;
};