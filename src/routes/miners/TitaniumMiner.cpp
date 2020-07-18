#pragma once

#include <iostream>
#include <Windows.h>
#include "../../drivers/Walker.cpp"
#include "../../interactions/CaptchaSolver.cpp"
#include "../../interactions/ChatManager.cpp"

class TitaniumMiner {

private:
    Movement *movement = new Movement();
    ChatManager *chat = new ChatManager();
    GameResources *gameResources;
    Walker *walker;

public:
    TitaniumMiner(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->walker = new Walker(gameResources);
    }

public:
    void Start() {
        goToStart();
        goToOutsideDoor();
        goToTitaniumStone();
        pickStone();
        goToInnerDoor();
        goDeliveryPoint();
        deliverStone();
    }

private:
    void deliverStone() {
        walker->RunToPos(-550, 2337);
        Sleep(1000);
        chat->Type("/dejar roca");
        solveCaptcha();
        Sleep(5000);
    }

private:
    void goToStart() {
        movement->StopMovingForward();
        movement->StopRunning();
        movement->StopSlowlyWalk();
        movement->StopMovingBack();
        movement->StopMovingLeft();
        movement->StopMovingRight();
        walker->overSecureWalkTo(-565, 2338);
    }

private:
    void goDeliveryPoint() {
        walker->RunToPos(-611, 2325);
        walker->RunToPos(-605, 2330);
        walker->RunToPos(-597, 2331);
        walker->RunToPos(-587, 2339);
    }

private:
    void goToInnerDoor() {
        walker->RunToPos(-729, 2409);
        walker->RunToPos(-723, 2410);
        walker->RunToPos(-717, 2425); // Rails end
        walker->RunToPos(-718, 2462); // Exit door
        Sleep(1000);
        movement->JoinOrLeaveInterior();
    }

private:
    void goToOutsideDoor() {
        walker->RunToPos(-587, 2339);
        walker->RunToPos(-597, 2331);
        walker->RunToPos(-605, 2330);
        walker->RunToPos(-611, 2325); // Enter door
        movement->JoinOrLeaveInterior();
    }

private:
    void goToTitaniumStone() {
        walker->RunToPos(-717, 2425); // Rails end
        walker->RunToPos(-723, 2410);
        walker->RunToPos(-729, 2409);
    }

private:
    void pickStone() {
        Sleep(2500);
        chat->Type("/picar");
        Sleep(20 * 1000);
    }

private:
    void solveCaptcha() {
        printf("Starting captcha solver...\n");
        Sleep(1500);
        auto *captchaSolver = new CaptchaSolver();
        captchaSolver->Solve();
    }

};