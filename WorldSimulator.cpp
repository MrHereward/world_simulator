#include "WorldSimulator.h"

#include <iostream>
#include <chrono>
#include <thread>

WorldSimulator::WorldSimulator() {
    map = new Map(10, 10);
    organismsManager = new OrganismsManager(map);
}

void WorldSimulator::run() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    int operation{ 1 };

    do {
        std::system("clear");

        organismsManager->update();
        map->print();
        map->printList();

        std::cout << "1. Next round\n";
        std::cout << "2. Exit\n";

        //std::cin >> operation;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    } while (operation != 2);
}

WorldSimulator::~WorldSimulator() {
    delete map;
    delete organismsManager;
}