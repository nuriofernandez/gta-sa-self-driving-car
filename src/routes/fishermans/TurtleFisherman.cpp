#pragma once

#include <iostream>
#include <Windows.h>
#include "../../drivers/Driver.cpp"
#include "../../interactions/CaptchaSolver.cpp"
#include "../../interactions/ChatManager.cpp"
#include "Fisherman.cpp"

class TurtleFisherman {

private:
    Movement *movement = new Movement();
    ChatManager *chat = new ChatManager();
    GameResources *gameResources;
    GameUtils *gameUtils;
    Driver *driver;

public:
    TurtleFisherman(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->gameUtils = new GameUtils(gameResources);
        this->driver = new Driver(gameResources);
    }

public:
    void Start() {
        driveToTurtle();
        goToBoatDeck();
        fish();
        returnToBoat();
        driveToDock();
        deliver();
    }

private:
    void fish() {
        gameUtils->waitOnFloor();
        printf("Throwing the fishing harpoon...\n");
        Sleep(1000);
        chat->Type("/lanzar arpon");
        Sleep(2000);
        solveCaptcha();
        Sleep(12 * 1000);
    }

private:
    void driveToTurtle() {
        gameUtils->waitInVehicle();
        printf("Going to the turtle fishing area...\n");
        driver->DriveToPos(Fisherman::Checkpoints::DOCK_EXIT);
        driver->DriveToPos(Fisherman::Checkpoints::OCEAN_DOCS_CORNER);
        driver->DriveToPos(Fisherman::Checkpoints::BEACH_CORNER);
        driver->DriveToPos(Fisherman::Checkpoints::TURTLE_REORIENTATION_POINT);
        driver->DriveToPos(Fisherman::Checkpoints::TURTLE_POINT);
        movement->MoveBack();
        Sleep(2000);
        movement->StopMovingBack();
        movement->Brake();
        Sleep(2000);
        movement->StopBraking();
    }

private:
    void driveToDock() {
        gameUtils->waitInVehicle();
        printf("Going to the dock...\n");
        driver->DriveToPos(Fisherman::Checkpoints::BEACH_CORNER);
        driver->DriveToPos(Fisherman::Checkpoints::OCEAN_DOCS_CORNER);
        driver->DriveToPos(Fisherman::Checkpoints::DOCK_EXIT);
    }

private:
    void deliver() {
        gameUtils->waitInVehicle();
        while (gameResources->IsInVehicle()) {
            driver->DriveToPos(Fisherman::Checkpoints::DELIVERY_POINT);
            Sleep(500);
        }
    }

private:
    void goToBoatDeck() {
        gameUtils->waitInVehicle();
        printf("Going to the boat deck...\n");
        movement->JoinOrLeaveCar();
        Sleep(1000);
        movement->MoveBack();
        Sleep(700);
        movement->StopMovingBack();
    }

private:
    void returnToBoat() {
        gameUtils->waitOnFloor();
        while (!gameResources->IsInVehicle()) {
            printf("Returning to the boat...\n");
            movement->Run();
            movement->JoinOrLeaveCar();
            Sleep(3000);
            movement->StopRunning();
            Sleep(500);
        }
    }

private:
    void solveCaptcha() {
        printf("Starting captcha solver...\n");
        auto *captchaSolver = new CaptchaSolver();
        captchaSolver->Solve();
    }

};