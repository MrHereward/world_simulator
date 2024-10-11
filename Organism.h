#pragma once

class OrganismsManager;

class Organism {
    public:
        int getPositionX() const;
        void setPositionX(int);
        int getPositionY() const;
        void setPositionY(int);
        int getEnergy() const;
        void setEnergy(int);
        char getSymbol() const;

        virtual ~Organism() = default;

    protected:
        OrganismsManager* organismsManager;
        int positionX;
        int positionY;
        int energy;
        char symbol;
};