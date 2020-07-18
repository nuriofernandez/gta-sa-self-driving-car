#pragma once

#include <string>
#include <Windows.h>

using namespace std;

class ChatManager {

private:
    INPUT input = {0};

public:
    ChatManager() {
        input.type = INPUT_KEYBOARD;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;
    }

public:
    void Type(string msg) {
        printf("Issuing chat '%s' command/message...\n", msg.c_str());
        openChat();
        wstring msgChars = wstring(msg.begin(), msg.end());
        for (int i = 0; i < msg.size(); ++i) {
            inputKey((WORD) msgChars[i]);
        }
        enter();
    }

private:
    void enter() {
        pressKey(0x0D);
    }

private:
    void openChat() {
        inputKey((WORD) L"t"[0]);
    }


private:
    void inputKey(int key) {
        input.ki.dwFlags = KEYEVENTF_UNICODE;
        input.ki.wScan = key;
        SendInput(1, &input, sizeof(INPUT));
    }

private:
    void pressKey(int key) {
        INPUT input = {0};
        input.type = INPUT_KEYBOARD;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;
        input.ki.wVk = key;

        input.ki.dwFlags = 0; // key press
        SendInput(1, &input, sizeof(INPUT));
        Sleep(10);
        input.ki.dwFlags = KEYEVENTF_KEYUP; // key release
        SendInput(1, &input, sizeof(INPUT));
    }

};