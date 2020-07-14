#include <iostream>
#include <Windows.h>

class CaptchaCube {

public:
    int x;
    int y;

public:
    CaptchaCube(int x, int y) {
        this->x = x;
        this->y = y;
    }

public:
    bool IsEmpty() {
        HWND desktop = GetDesktopWindow();
        HDC desktopHdc = GetDC(desktop);
        COLORREF pixel = GetPixel(desktopHdc, x, y);
        int red = GetRValue(pixel);
        int green = GetGValue(pixel);
        int blue = GetBValue(pixel);
        printf("Captcha ( %d , %d ) is color: ( %d , %d , %d )\n", x, y, red, green, blue);
        return red >= 10 && green >= 10 && blue >= 10;
    }

};

class CaptchaSolver {

private:
    CaptchaCube *topLeft = new CaptchaCube(734, 529);
    CaptchaCube *topRight = new CaptchaCube(1003, 529);
    CaptchaCube *botLeft = new CaptchaCube(734, 760);
    CaptchaCube *botRight = new CaptchaCube(1003, 760);

public:
    CaptchaSolver() {

    }

public:
    void Solve() {
        CaptchaCube correct = getCorrect();
        SetCursorPos(correct.x, correct.y);
        Sleep(100);
        click();
        Sleep(100);
    }

private:
    CaptchaCube getCorrect() {
        if (topLeft->IsEmpty()) return *topLeft;
        if (topRight->IsEmpty()) return *topRight;
        if (botLeft->IsEmpty()) return *botLeft;
        if (botRight->IsEmpty()) return *botRight;
    }

private:
    void click() {
        INPUT input = {};
        input.type = INPUT_MOUSE;
        input.mi.time = 0;
        input.mi.dwExtraInfo = 0;
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &input, sizeof(INPUT));

        Sleep(100);
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &input, sizeof(INPUT));
    }

};