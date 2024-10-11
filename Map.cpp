#include "Map.h"

#include <iostream>
#include <algorithm>

Map::Map(int length, int width)
    : length{ length }, width{ length }, 
    grid{ std::vector<std::vector<std::vector<Organism*>>>(length, std::vector<std::vector<Organism*>>(width, std::vector<Organism*>())) } {

}

void Map::addOrganism(Organism *organism)
{
    grid[organism->getPositionY()][organism->getPositionX()].push_back(organism);
}

void Map::removeOrganism(Organism *organism)
{
    int y = organism->getPositionY();
    int x = organism->getPositionX();
    grid[y][x].erase(std::remove(grid[y][x].begin(), grid[y][x].end(), organism), grid[y][x].end());
}

void Map::print() const {
    for (const auto& line : grid) {
        std::cout << '|';
        for (const auto& field : line) {
            if (field.empty()) {
                std::cout << '.';
            } else if (field.size() > 1) {
                std::cout << '*';
            } else {
                std::cout << field[0]->getSymbol();
            }
        }
        std::cout << "|\n";
    }
}

void Map::printList() const {
    for (const auto& line : grid) {
        for (const auto& field : line) {
            for (const auto& organism : field) {
                std::cout << organism->getSymbol() << ": (" << organism->getPositionY() << ", " << organism->getPositionX() << ")\n"; 
            }
        }
    }
}

int Map::getLength() const {
    return length;
}

int Map::getWidth() const {
    return width;
}
