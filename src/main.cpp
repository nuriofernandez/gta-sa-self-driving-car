#include "game/GameResources.cpp"
#include "application/Console.cpp"
#include "routes/fishermans/TurtleFisherman.cpp"
#include "routes/fishermans/DolphinFisherman.cpp"
#include "routes/miners/IronMiner.cpp"
#include "routes/miners/CopperMiner.cpp"
#include "routes/miners/TitaniumMiner.cpp"
#include "routes/miners/MercuryMiner.cpp"

using namespace std;
GameResources *gameResources;

void fishTurtle() {
    Console::println("Starting turtle fisherman route...");
    Sleep(4000);
    TurtleFisherman *fisher = new TurtleFisherman(gameResources);
    fisher->Start();
}

void fishDolphin() {
    Console::println("Starting dolphin fisherman route...");
    Sleep(4000);
    DolphinFisherman *fisher = new DolphinFisherman(gameResources);
    fisher->Start();
}

void mineIron() {
    Console::println("Starting iron miner route...");
    Sleep(4000);
    IronMiner *miner = new IronMiner(gameResources);
    miner->Start();
}

void mineCopper() {
    Console::println("Starting copper miner route...");
    Sleep(4000);
    CopperMiner *miner = new CopperMiner(gameResources);
    miner->Start();
}

void mineTitanium() {
    Console::println("Starting titanium miner route...");
    Sleep(4000);
    TitaniumMiner *miner = new TitaniumMiner(gameResources);
    miner->Start();
}

void mineMercury() {
    Console::println("Starting mercury miner route...");
    Sleep(4000);
    MercuryMiner *miner = new MercuryMiner(gameResources);
    miner->Start();
}

int main() {
    Console::println("Starting...");
    gameResources = new GameResources();

    Console::println("List of routes:");
    Console::println(" ");
    Console::println(" 1 - TurtleFisherman");
    Console::println(" 2 - DolphinFisherman");
    Console::println(" ");
    Console::println(" 3 - IronMiner");
    Console::println(" 4 - CopperMiner");
    Console::println(" 5 - TitaniumMiner");
    Console::println(" 6 - MercuryMiner");
    Console::println(" ");

    Console::println("Please select a route:");
    int routeId = Console::askIntegerNumberBetween(1, 6);

    switch (routeId) {
        case 1:
            fishTurtle();
            break;
        case 2:
            fishDolphin();
            break;
        case 3:
            mineIron();
            break;
        case 4:
            mineCopper();
            break;
        case 5:
            mineTitanium();
            break;
        case 6:
            mineMercury();
            break;
        default:
            Console::println("Selected route '%d' not found.", routeId);
    }
    return 0;
}
