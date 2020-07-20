#pragma once

#include "../interactions/Movement.cpp"
#include "../math/AxisManager.cpp"
#include "../game/GameUtils.cpp"
#include "Checkpoint.cpp"

class Walker {

private:
    GameResources *gameResources;
    AxisCalculation *axisCalculation;
    GameUtils *gameUtils;
    Movement *movement = new Movement();
    bool overSecure = false;

public:
    Walker(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->gameUtils = new GameUtils(gameResources);
        this->axisCalculation = new AxisCalculation(gameResources);
    }

public:
    void WalkToPos(Checkpoint *destination) {
        printf("Walking to %f, %f...\n", destination->getX(), destination->getY());
        movement->MoveForward();
        while (axisCalculation->GetDistanceTo(destination->getX(), destination->getY()) >= 1) {
            Sleep(10);
            goTo(destination->getX(), destination->getY());
        }
        movement->StopMovingForward();
    }

public:
    void overSecureWalkTo(Checkpoint *destination) {
        overSecure = true;
        SlowlyToPos(destination);
        overSecure = false;
    }

public:
    void SlowlyToPos(Checkpoint *destination) {
        movement->SlowlyWalk();
        WalkToPos(destination);
        movement->StopSlowlyWalk();
    }

public:
    void RunToPos(Checkpoint *destination) {
        movement->Run();
        WalkToPos(destination);
        movement->StopRunning();
    }

private:
    void goTo(float destX, float destY) {
        gameUtils->waitOnFloor(100, false);
        movement->MoveForward();

        MovingDirection movingTo = axisCalculation->GetDirectionTo(destX, destY);

        if (movingTo == LEFT) {
            if (overSecure) {
                movement->moveCursorFastLeft();
                return;
            }
            movement->moveCursorLeft();
        }

        if (movingTo == RIGHT) {
            if (overSecure) {
                movement->moveCursorFastRight();
                return;
            }
            movement->moveCursorRight();
        }
    }

};