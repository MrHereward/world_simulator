#include "WorldSimulator.h"

#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

WorldSimulator::WorldSimulator() {
    map = new Map(10, 10);
    organismsManager = new OrganismsManager(map);
}

void WorldSimulator::run() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    int operation{ 1 };

    while (true) {
        std::system("clear");

        organismsManager->update();
        map->print();
        map->printList();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

WorldSimulator::~WorldSimulator() {
    delete map;
    delete organismsManager;
}