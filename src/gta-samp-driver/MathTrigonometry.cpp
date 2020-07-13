#define _USE_MATH_DEFINES

#include <math.h>
#include "GameResources.cpp"

enum PositionQuadrant {
    CENTER,         // No quadrant, on an axis line.
    PLUS_PLUS,      // Top right
    PLUS_MINUS,     // Down right
    MINUS_MINUS,    // Down left
    MINUS_PLUS      // Top left
};

class MathTrigonometry {

private:
    GameResources gameResources;

public:
    MathTrigonometry(GameResources gameResources) {
        this->gameResources = gameResources;
    }

public:
    float Square(float number) {
        return number * number;
    }

public:
    float Distance(float originX, float destinationX) {
        return sqrt(Square(originX - destinationX));
    }

public:
    float Distance(float originX, float originY, float destinationX, float destinationY) {
        return sqrt(Square(originX - destinationX) + Square(originY - destinationY));
    }

public:
    PositionQuadrant GetRelativeQuadrantOf(float x, float y) {
        float originX = gameResources.GetPlayerX();
        float originY = gameResources.GetPlayerY();
        if (originX == x && originY == y) return PLUS_PLUS;

        if (x >= originX && y > originY) return PLUS_PLUS;
        if (x > originX && y <= originY) return PLUS_MINUS;
        if (x < originX && y <= originY) return MINUS_MINUS;
        if (x <= originX && y != originY) return MINUS_PLUS;
        throw -1;
    }

public:
    float GetAdjacentLineValue(float x, float y) {
        float originX = gameResources.GetPlayerX();
        float originY = gameResources.GetPlayerY();
        PositionQuadrant quadrant = GetRelativeQuadrantOf(x, y);

        if (quadrant == PLUS_PLUS || quadrant == MINUS_MINUS) return this->Distance(originY, y);
        if (quadrant == PLUS_MINUS || quadrant == MINUS_PLUS) return this->Distance(originX, x);
        throw -1;
    }

public:
    float GetOppositeLineValue(float x, float y) {
        float originX = gameResources.GetPlayerX();
        float originY = gameResources.GetPlayerY();
        PositionQuadrant quadrant = GetRelativeQuadrantOf(x, y);

        if (quadrant == PLUS_PLUS || quadrant == MINUS_MINUS) return this->Distance(originX, x);
        if (quadrant == PLUS_MINUS || quadrant == MINUS_PLUS) return this->Distance(originY, y);
        throw -1;
    }

public:
    float GetHypotenuseLineValue(float destinationX, float destinationY) {
        float originX = gameResources.GetPlayerX();
        float originY = gameResources.GetPlayerY();
        return this->Distance(originX, originY, destinationX, destinationY);
    }

public:
    int GetOffSetGrades(float x, float y) {
        PositionQuadrant quadrant = GetRelativeQuadrantOf(x, y);
        if (quadrant == CENTER) return 0;
        if (quadrant == PLUS_PLUS) return 0;
        if (quadrant == PLUS_MINUS) return 90;
        if (quadrant == MINUS_MINUS) return 180;
        if (quadrant == MINUS_PLUS) return 270;
        throw -1;
    }

public:
    double GetAngleTo(float x, float y) {
        float adjacent = this->GetAdjacentLineValue(x, y);
        float hypotenuse = this->GetHypotenuseLineValue(x, y);

        double angle = acos(adjacent / hypotenuse) * 180.0 / M_PI;
        return angle + this->GetOffSetGrades(x, y);
    }

public:
    double CalculateAngleDistance(float angle1, float angle2) {
        double diff = fmod((angle2 - angle1 + 180), 360) - 180;
        return (diff < -180) ? diff + 360 : diff;
    }

};