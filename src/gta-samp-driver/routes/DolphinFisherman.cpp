#include <iostream>
#include <Windows.h>
#include "../Driver.cpp"
#include "../CaptchaSolver.cpp"
#include "../ChatManager.cpp"

class DolphinFisherman {

private:
    Movement *movement = new Movement();
    Driver *driver = new Driver();
    ChatManager *chat = new ChatManager();

public:
    void Start() {
        driveToDolphin();
        goToBoatDeck();
        fish();
        returnToBoat();
        driveToDock();
    }

private:
    void fish() {
        printf("Throwing the fishing harpoon...\n");
        Sleep(1000);
        chat->Type("/lanzar arpon");
        Sleep(2000);
        solveCaptcha();
        Sleep(12 * 1000);
    }

private:
    void driveToDolphin() {
        printf("Going to the dolphin fishing area...\n");
        driver->DriveToPos(2775, -2702);
        driver->DriveToPos(2417, -2859);
        driver->DriveToPos(1267, -2911);
        driver->DriveToPos(101, -1979);
        driver->DriveToPos(36, -1766);
        driver->DriveToPos(36, -1710);
        movement->MoveBack();
        Sleep(2000);
        movement->StopMovingBack();
        movement->Brake();
        Sleep(2000);
        movement->StopBraking();
    }

private:
    void driveToDock() {
        printf("Going to the dock...\n");
        driver->DriveToPos(101, -1979);
        driver->DriveToPos(1267, -2911);
        driver->DriveToPos(2417, -2859);
        driver->DriveToPos(2775, -2702);
        driver->DriveToPos(2798, -2594);
    }

private:
    void goToBoatDeck() {
        printf("Going to the boat deck...\n");
        movement->JoinOrLeaveCar();
        Sleep(1000);
        movement->MoveBack();
        Sleep(700);
        movement->StopMovingBack();
    }

private:
    void returnToBoat() {
        printf("Returning to the boat...\n");
        movement->Run();
        movement->JoinOrLeaveCar();
        Sleep(3000);
        movement->StopRunning();
    }

private:
    void solveCaptcha() {
        printf("Starting captcha solver...\n");
        auto *captchaSolver = new CaptchaSolver();
        captchaSolver->Solve();
    }

};