#pragma once

#include "MathTrigonometry.cpp"
#include "../game/GameResources.cpp"

enum FacingDirection {
    NORTH, EAST, SOUTH, WEST
};

enum MovingDirection {
    LEFT, FORWARD, RIGHT
};

class AxisCalculation {

private:
    GameResources *gameResources;
    MathTrigonometry *mathTrigonometry;

public:
    AxisCalculation(GameResources *gameResources) {
        this->gameResources = gameResources;
        this->mathTrigonometry = new MathTrigonometry(gameResources);
    }

public:
    FacingDirection GetFacingDirection() {
        double angle = gameResources->GetPlayerRotationAngle();
        if (angle >= 45 && angle <= 134) return EAST;
        if (angle >= 135 && angle <= 224) return SOUTH;
        if (angle >= 225 && angle <= 315) return WEST;
        return NORTH;
    }

public:
    MovingDirection GetDirectionTo(float destinationX, float destinationY) {
        float desiredAngle = AngleFromCoordinate(destinationX, destinationY);
        double carAngle = gameResources->GetPlayerRotationAngle();
        double closeDistance = mathTrigonometry->CalculateAngleDistance(desiredAngle, carAngle);

        if (closeDistance <= 5 && closeDistance >= -5) return FORWARD;
        return (closeDistance < 0) ? RIGHT : LEFT;
    }

public:
    float GetDistanceTo(float destinationX, float destinationY) {
        float carX = gameResources->GetPlayerX();
        float carY = gameResources->GetPlayerY();
        return mathTrigonometry->Distance(carX, carY, destinationX, destinationY);
    }

public:
    float AngleFromCoordinate(float destX, float destY) {
        return mathTrigonometry->GetAngleTo(destX, destY);
    }

};