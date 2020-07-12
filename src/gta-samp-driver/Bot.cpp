#include <iostream>
#include <Windows.h>
#include "Movement.cpp"
#include "AxisManager.cpp"

Movement BOT = Movement();
GameResources gameResources = GameResources();
AxisCalculation axisCalculation = AxisCalculation(gameResources);
MathTrigonometry *mathTrigonometry = new MathTrigonometry(gameResources);

float destX = -2001;
float destY = -285;

void move() {
    float distance = axisCalculation.GetDistanceTo(destX, destY);
    MovingDirection movingTo = axisCalculation.GetDirectionTo(destX, destY);
    string direction = movingTo == FORWARD ? "forward" : (movingTo == LEFT) ? "left" : "right";
    printf("Moving to %s\n", direction.c_str());

    if (distance >= 10) {
        BOT.MoveForward();
    } else {
        BOT.StopMovingForward();
    }

    if (movingTo == FORWARD) {
        BOT.StopMovingLeft();
        BOT.StopMovingRight();
    } else if (movingTo == LEFT) {
        BOT.StopMovingRight();
        BOT.MoveLeft();
    } else {
        BOT.StopMovingLeft();
        BOT.MoveRight();
    }
}


void drive() {
    Sleep(10);
    if (!gameResources.IsInCar()) {
        printf("Player is not in a car.\n");
        Sleep(500);
        return;
    }

    float distance = axisCalculation.GetDistanceTo(destX, destY);
    if (distance <= 1) {
        printf("Destination point too close.\n");
        BOT.StopMovingForward();
        BOT.StopMovingLeft();
        BOT.StopMovingRight();
        return;
    }
    if (distance >= 100) printf("Destination point too far.\n");

    move();
}

int main() {
    while (true) {
        drive();
    }
}