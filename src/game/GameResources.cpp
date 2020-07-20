/**
 * GTA:SA Memory Addresses index
 * 'https://gtamods.com/wiki/Memory_Addresses_(SA)'
 */
#pragma once

#include <Windows.h>
#include <iostream>
#include "MemoryReader.cpp"

class GameResources;

using namespace std;

class GameResources {

private:
    MemoryReader *memoryReader = new MemoryReader("GTA:SA:MP");

public:
    GameResources() {

    }

private:
    DWORD getPed() {
        return memoryReader->ReadDWORD(0xB6F5F0);
    }

private:
    DWORD getPlayerPosition() {
        return memoryReader->ReadDWORD((getPed() + 0x14));
    }

private:
    DWORD getPlayerCar() {
        return memoryReader->ReadDWORD((getPed() + 0x58C));
    }

private:
    DWORD getCarPosition() {
        return memoryReader->ReadDWORD(getPlayerCar() + 0x14);
    }

public:
    int GetMoney() {
        return memoryReader->ReadInt(0xB7CE50);
    }

public:
    float GetPlayerX() {
        return memoryReader->ReadFloat(getPlayerPosition() + 0x30);
    }

public:
    float GetPlayerY() {
        return memoryReader->ReadFloat(getPlayerPosition() + 0x34);
    }

public:
    float GetPlayerZ() {
        return memoryReader->ReadFloat(getPlayerPosition() + 0x38);
    }

public:
    uint8_t GetPedStatus() {
        return memoryReader->ReadUint8((DWORD) (getPed() + 0x46C));
    }

public:
    bool IsOnAirOrWater() {
        return GetPedStatus() == 0;
    }

public:
    bool IsInVehicle() {
        return GetPedStatus() == 1;
    }

public:
    bool IsEnteringInterior() {
        return GetPedStatus() == 2;
    }

public:
    bool IsOnFloor() {
        return GetPedStatus() == 3;
    }

public:
    double GetCarRotationAngle() {
        float anglexGrad = memoryReader->ReadFloat(getCarPosition() + 0);
        float anglexLook = memoryReader->ReadFloat(getCarPosition() + 16);
        float angleyLook = memoryReader->ReadFloat(getCarPosition() + 20);
        float anglezGrad = memoryReader->ReadFloat(getCarPosition() + 8);

        return CalculateAngleByLookAndGrad(angleyLook, anglexLook, anglexGrad, anglezGrad);
    }

public:
    double GetPlayerRotationAngle() {
        float anglexGrad = memoryReader->ReadFloat(getPlayerPosition() + 0);
        float anglexLook = memoryReader->ReadFloat(getPlayerPosition() + 16);
        float angleyLook = memoryReader->ReadFloat(getPlayerPosition() + 20);
        float anglezGrad = memoryReader->ReadFloat(getPlayerPosition() + 8);

        return CalculateAngleByLookAndGrad(angleyLook, anglexLook, anglexGrad, anglezGrad);
    }

private:
    double CalculateAngleByLookAndGrad(float angleyLook, float anglexLook, float anglexGrad, float anglezGrad) {
        if ((angleyLook >= 0 && anglexLook >= 0) || (angleyLook < 0 && anglexLook > 0)) {
            return acos(anglexGrad / cos(asin(anglezGrad))) * 180.0 / 3.1415;
        }
        return 360 - acos(anglexGrad / cos(asin(anglezGrad))) * 180.0 / 3.1415;
    }

};