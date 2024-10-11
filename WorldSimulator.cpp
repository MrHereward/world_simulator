#include "WorldSimulator.h"

#include <iostream>

WorldSimulator::WorldSimulator() {
    map = new Map(10, 10);
    organismsManager = new OrganismsManager(map);
}

void WorldSimulator::run() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    int operation{};

    do {
        std::system("clear");

        organismsManager->update();
        map->print();

        std::cout << "1. Next round\n";
        std::cout << "2. Exit\n";

        std::cin >> operation;
    } while (operation != 2);
}

WorldSimulator::~WorldSimulator() {
    delete map;
    delete organismsManager;
}