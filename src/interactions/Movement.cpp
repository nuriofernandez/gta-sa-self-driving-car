#pragma once

#include <Windows.h>

class Movement {

private:
    INPUT input;

public:
    Movement() {
        input.type = INPUT_KEYBOARD;
        input.ki.wScan = 0; // hardware scan code for key
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;
    }

private:
    void longPressKey(int key) {
        pressKey(key);
        Sleep(300);
        releaseKey(key);
        Sleep(50);
    }

private:
    void pressKey(int key) {
        input.ki.wVk = key; // virtual-key code for the key
        input.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &input, sizeof(INPUT));
    }

private:
    void releaseKey(int key) {
        input.ki.wVk = key; // virtual-key code.
        input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &input, sizeof(INPUT));
    }

private:
    void moveCursor(int amount) {
        INPUT input;
        input.type = INPUT_MOUSE;
        input.mi.dx = amount;
        input.mi.dy = 0;
        input.mi.mouseData = 0;
        input.mi.dwFlags = MOUSEEVENTF_MOVE_NOCOALESCE | MOUSEEVENTF_MOVE | MOUSEEVENTF_VIRTUALDESK;
        input.mi.time = 0;
        SendInput(1, &input, sizeof(input));
    }

public:
    void MoveLeft() {
        pressKey(0x41);
    }

public:
    void StopMovingLeft() {
        releaseKey(0x41);
    }

public:
    void MoveRight() {
        pressKey(0x44);
    }

public:
    void StopMovingRight() {
        releaseKey(0x44);
    }

public:
    void MoveBack() {
        pressKey(0x53);
    }

public:
    void StopMovingBack() {
        releaseKey(0x53);
    }

public:
    void StepForward() {
        longPressKey(0x57);
    }

public:
    void MoveForward() {
        pressKey(0x57);
    }

public:
    void StopMovingForward() {
        releaseKey(0x57);
    }

public:
    void Brake() {
        pressKey(0x20);
    }

public:
    void StopBraking() {
        releaseKey(0x20);
    }

public:
    void Run() {
        Brake();
    }

public:
    void StopRunning() {
        StopBraking();
    }

public:
    void JoinOrLeaveCar() {
        longPressKey(0x46);
    }

public:
    void JoinOrLeaveInterior() {
        longPressKey(0x59);
    }

public:
    void moveCursorRight() {
        moveCursor(15);
    }

public:
    void moveCursorFastRight() {
        moveCursor(30);
    }

public:
    void moveCursorLeft() {
        moveCursor(-15);
    }

public:
    void moveCursorFastLeft() {
        moveCursor(-30);
    }


public:
    void jump() {
        longPressKey(0x10);
    }

public:
    void SlowlyWalk() {
        pressKey(0x12);
    }

public:
    void StopSlowlyWalk() {
        releaseKey(0x12);
    }

public:
    void StopMoving() {
        StopMovingRight();
        StopMovingLeft();
        StopMovingBack();
        StopMovingForward();
    }

};