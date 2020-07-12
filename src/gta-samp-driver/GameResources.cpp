/**
 * GTA:SA Memory Addresses index
 * 'https://gtamods.com/wiki/Memory_Addresses_(SA)'
 */
#include <Windows.h>
#include <iostream>
#include <cmath>
#include "MemoryReader.cpp"

using namespace std;

class GameResources {

private:
    MemoryReader memoryReader = MemoryReader("GTA:SA:MP");

public:
    GameResources() {

    }

private:
    DWORD GetPed() {
        return memoryReader.ReadDWORD(0xB6F5F0);
    }

private:
    DWORD GetPlayerPoistion() {
        return memoryReader.ReadDWORD((GetPed() + 0x14));
    }

private:
    DWORD GetCarPoistion() {
        return memoryReader.ReadDWORD((GetPed() + 0x58C));
    }

private:
    DWORD getCarRotation() {
        return memoryReader.ReadDWORD(GetCarPoistion() + 20);
    }

public:
    int GetMoney() {
        return memoryReader.ReadInt(0xB7CE50);
    }

public:
    float GetPlayerX() {
        return memoryReader.ReadFloat(GetPlayerPoistion() + 0x30);
    }

public:
    float GetPlayerY() {
        return memoryReader.ReadFloat(GetPlayerPoistion() + 0x34);
    }

public:
    float GetPlayerZ() {
        return memoryReader.ReadFloat(GetPlayerPoistion() + 0x38);
    }

public:
    bool IsInCar() {
        uint8_t pedStatus = memoryReader.ReadUint8((DWORD) (GetPed() + 0x46C));
        return pedStatus == 1; // 1 = IN CAR
    }

public:
    float GetCarRotationAngle() {
        float anglexGrad = memoryReader.ReadFloat(getCarRotation() + 0);
        float anglexLook = memoryReader.ReadFloat(getCarRotation() + 16);
        float angleyLook = memoryReader.ReadFloat(getCarRotation() + 20);
        float anglezGrad = memoryReader.ReadFloat(getCarRotation() + 8);

        if ((angleyLook >= 0 && anglexLook >= 0) || (angleyLook < 0 && anglexLook > 0)) {
            return acos(anglexGrad / cos(asin(anglezGrad))) * 180.0 / 3.1415;
        }
        return 360 - acos(anglexGrad / cos(asin(anglezGrad))) * 180.0 / 3.1415;
    }

};