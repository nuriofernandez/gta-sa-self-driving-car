#pragma once

#include "../interactions/Movement.cpp"
#include "../math/AxisManager.cpp"
#include "../game/GameUtils.cpp"

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
    void WalkToPos(float destX, float destY) {
        printf("Walking to %f, %f...\n", destX, destY);
        movement->MoveForward();
        while (axisCalculation->GetDistanceTo(destX, destY) >= 1) {
            Sleep(10);
            goTo(destX, destY);
        }
        movement->StopMovingForward();
    }

public:
    void overSecureWalkTo(float destX, float destY) {
        overSecure = true;
        SlowlyToPos(destX, destY);
        overSecure = false;
    }

public:
    void SlowlyToPos(float destX, float destY) {
        movement->SlowlyWalk();
        WalkToPos(destX, destY);
        movement->StopSlowlyWalk();
    }

public:
    void RunToPos(float destX, float destY) {
        movement->Run();
        WalkToPos(destX, destY);
        movement->StopRunning();
    }

private:
    void goTo(float destX, float destY) {
        gameUtils->waitOnFloor();

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