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
        Sleep(200);
        releaseKey(key);
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

};