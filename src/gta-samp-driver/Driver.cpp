#include "AxisManager.cpp"
#include "Movement.cpp"

class Driver {

private:
    Movement movement = Movement();
    GameResources gameResources = GameResources();
    AxisCalculation axisCalculation = AxisCalculation(gameResources);

public:
    void DriveToPos(float destX, float destY) {
        printf("Driving to %f, %f...\n", destX, destY);
        movement.MoveForward();
        while (axisCalculation.GetDistanceTo(destX, destY) >= 5) {
            Sleep(10);
            drive(destX, destY);
        }
        movement.StopMovingForward();
        movement.StopMovingRight();
        movement.StopMovingLeft();
    }

private:
    void drive(float destX, float destY) {
        MovingDirection movingTo = axisCalculation.GetDirectionTo(destX, destY);

        if (movingTo == FORWARD) {
            movement.StopMovingLeft();
            movement.StopMovingRight();
        } else if (movingTo == LEFT) {
            movement.StopMovingRight();
            movement.MoveLeft();
        } else {
            movement.StopMovingLeft();
            movement.MoveRight();
        }
    }

};
