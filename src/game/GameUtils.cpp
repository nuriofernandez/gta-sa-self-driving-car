#pragma once

#include "GameResources.cpp"

class GameUtils {

private:
    GameResources *gameResources;

public:
    GameUtils(GameResources *gameResources) {
        this->gameResources = gameResources;
    }

    void waitInVehicle() {
        while (!gameResources->IsInVehicle()) {
            printf("Waiting for the player to be in a vehicle...\n");
            Sleep(1000);
        }
    }

    void waitOnFloor() {
        while (!gameResources->IsOnFloor()) {
            printf("Waiting for the player to be in the floor...\n");
            Sleep(1000);
        }
    }

};