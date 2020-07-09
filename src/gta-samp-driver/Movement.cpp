#include <Windows.h>

class Movement {

private: INPUT input;

public: Movement() {
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0; // hardware scan code for key
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
}

public: void LongPressKey(int key) {
	PressKey(key);
	Sleep(200);
	ReleaseKey(key);
}

public: void PressKey(int key) {
	input.ki.wVk = key; // virtual-key code for the key
	input.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &input, sizeof(INPUT));
}

public:	void ReleaseKey(int key) {
	input.ki.wVk = key; // virtual-key code.
	input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &input, sizeof(INPUT));
}

public: void MoveLeft() {
	PressKey(0x41);
}

public: void StopMovingLeft() {
	ReleaseKey(0x41);
}

public: void MoveRight() {
	PressKey(0x44);
}

public:	void StopMovingRight() {
	ReleaseKey(0x44);
}

public:	void MoveBack() {
	PressKey(0x53);
}

public:	void StopMovingBack() {
	ReleaseKey(0x53);
}

public:	void MoveForward() {
	PressKey(0x57);
}

public:	void StopMovingForward() {
	ReleaseKey(0x57);
}

};