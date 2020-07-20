#pragma once

#include "GameResources.cpp"
#include "../interactions/Movement.cpp"

class GameUtils {

private:
    GameResources *gameResources;
    Movement *movement = new Movement();

public:
    GameUtils(GameResources *gameResources) {
        this->gameResources = gameResources;
    }

public:
    void waitInVehicle() {
        waitOnFloor(1000);
    }

public:
    void waitInVehicle(int sleepTime) {
        while (!gameResources->IsInVehicle()) {
            printf("Waiting for the player to be in a vehicle...\n");
            Sleep(1000);
        }
    }

public:
    void waitOnFloor() {
        waitOnFloor(500, true);
    }

public:
    void waitOnFloor(int sleepTime) {
        waitOnFloor(sleepTime, true);
    }

public:
    void waitOnFloor(int sleepTime, bool stopMoving) {
        while (!gameResources->IsOnFloor()) {
            if (stopMoving) movement->StopMoving();
            printf("Waiting for the player to be in the floor...\n");
            Sleep(sleepTime);
        }
    }

};