#pragma once

#include <iostream>
#include <Windows.h>
#include "../../drivers/Walker.cpp"
#include "../../interactions/CaptchaSolver.cpp"
#include "../../interactions/ChatManager.cpp"

class IronMiner {

private:
    Movement *movement = new Movement();
    ChatManager *chat = new ChatManager();
    GameResources *gameResources;
    Walker *walker;

public:
    IronMiner(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->walker = new Walker(gameResources);
    }

public:
    void Start() {
        goToStart();
        goToOutsideDoor();
        goToStone();
        pickStone();
        goToInnerDoor();
        goDeliveryPoint();
        deliverStone();
    }

private:
    void deliverStone() {
        walker->RunToPos(new Checkpoint(-550, 2337));
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
        walker->overSecureWalkTo(new Checkpoint(-565, 2338));
    }

private:
    void goDeliveryPoint() {
        walker->RunToPos(new Checkpoint(-611, 2325));
        walker->RunToPos(new Checkpoint(-605, 2330));
        walker->RunToPos(new Checkpoint(-597, 2331));
        walker->RunToPos(new Checkpoint(-587, 2339));
    }

private:
    void goToInnerDoor() {
        walker->RunToPos(new Checkpoint(-740, 2392));
        walker->RunToPos(new Checkpoint(-727, 2408));
        walker->RunToPos(new Checkpoint(-717, 2422));
        walker->RunToPos(new Checkpoint(-718, 2462));
        Sleep(1000);
        movement->JoinOrLeaveInterior();
    }

private:
    void goToOutsideDoor() {
        walker->RunToPos(new Checkpoint(-587, 2339));
        walker->RunToPos(new Checkpoint(-597, 2331));
        walker->RunToPos(new Checkpoint(-605, 2330));
        walker->RunToPos(new Checkpoint(-611, 2325));
        movement->JoinOrLeaveInterior();
    }

private:
    void goToStone() {
        walker->RunToPos(new Checkpoint(-717, 2444));
        walker->RunToPos(new Checkpoint(-717, 2422));
        walker->RunToPos(new Checkpoint(-727, 2408));
        walker->RunToPos(new Checkpoint(-740, 2392));
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