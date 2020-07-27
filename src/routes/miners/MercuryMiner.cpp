#pragma once

#include <iostream>
#include <Windows.h>
#include "../../drivers/Walker.cpp"
#include "../../interactions/CaptchaSolver.cpp"
#include "../../interactions/ChatManager.cpp"
#include "Miner.cpp"

class MercuryMiner {

private:
    Movement *movement = new Movement();
    ChatManager *chat = new ChatManager();
    GameResources *gameResources;
    Walker *walker;

public:
    MercuryMiner(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->walker = new Walker(gameResources);
    }

public:
    void Start() {
        goToStart();
        goToOutsideDoor();
        goToMercuryStone();
        pickStone();
        goToInnerDoor();
        goDeliveryPoint();
        deliverStone();
    }

private:
    void deliverStone() {
        walker->RunToPos(Miner::Checkpoints::DELIVERY_POINT);
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
        walker->overSecureWalkTo(Miner::Checkpoints::START_RAMP);
    }

private:
    void goDeliveryPoint() {
        walker->RunToPos(Miner::Checkpoints::ENTER_DOOR);
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_DOOR_CORNER);
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_DOOR_BRIDGE);
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_RAMP_CORNER);
    }

private:
    void goToInnerDoor() {
        walker->RunToPos(Miner::Checkpoints::MERCURY_STONE);
        walker->RunToPos(Miner::Checkpoints::RAIL_END);
        walker->RunToPos(Miner::Checkpoints::EXIT_DOOR);
        Sleep(1000);
        movement->JoinOrLeaveInterior();
    }

private:
    void goToOutsideDoor() {
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_RAMP_CORNER);
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_DOOR_BRIDGE);
        walker->RunToPos(Miner::Checkpoints::OUTSIDE_PATH_DOOR_CORNER);
        walker->RunToPos(Miner::Checkpoints::ENTER_DOOR);
        movement->JoinOrLeaveInterior();
    }

private:
    void goToMercuryStone() {
        walker->RunToPos(Miner::Checkpoints::RAIL_END);
        walker->RunToPos(Miner::Checkpoints::MERCURY_STONE);
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