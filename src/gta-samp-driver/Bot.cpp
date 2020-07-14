#include <iostream>
#include "routes/DolphinFisherman.cpp"

int main() {
    printf("Starting dolphin fisherman route...\n");
    Sleep(5000);
    auto dolphinFisher = new DolphinFisherman();
    dolphinFisher->Start();
}