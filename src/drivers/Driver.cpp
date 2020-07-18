#pragma once

#include "../math/AxisManager.cpp"
#include "../interactions/Movement.cpp"
#include "../game/GameUtils.cpp"

class Driver {

private:
    Movement *movement = new Movement();
    GameResources *gameResources;
    GameUtils *gameUtils;
    AxisCalculation *axisCalculation;

public:
    Driver(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->gameUtils = new GameUtils(gameResources);
        this->axisCalculation = new AxisCalculation(gameResources);
    }

public:
    void DriveToPos(float destX, float destY) {
        printf("Driving to %f, %f...\n", destX, destY);
        while (axisCalculation->GetDistanceTo(destX, destY) >= 5) {
            Sleep(10);
            drive(destX, destY);
        }
        movement->StopMoving();
    }

private:
    void drive(float destX, float destY) {
        gameUtils->waitInVehicle();

        movement->MoveForward();
        MovingDirection movingTo = axisCalculation->GetDirectionTo(destX, destY);

        if (movingTo == FORWARD) {
            movement->StopMovingLeft();
            movement->StopMovingRight();
        } else if (movingTo == LEFT) {
            movement->StopMovingRight();
            movement->MoveLeft();
        } else {
            movement->StopMovingLeft();
            movement->MoveRight();
        }
    }

};
