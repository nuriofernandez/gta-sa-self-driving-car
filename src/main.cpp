#include <iostream>
#include "game/GameResources.cpp"
#include "routes/fishermans/TurtleFisherman.cpp"

GameResources *gameResources = new GameResources();

int main() {
    printf("Starting turtle fisherman route...\n");
    Sleep(4000);
    TurtleFisherman *turtle = new TurtleFisherman(gameResources);
    turtle->Start();
    return 0;
}
