#pragma once

class Checkpoint {

private:
    float x, y;

public:
    Checkpoint(float x, float y) {
        this->x = x;
        this->y = y;
    }

public:
    float getX() {
        return x;
    }

public:
    float getY() {
        return y;
    }

};
