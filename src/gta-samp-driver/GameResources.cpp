/**
 * GTA:SA Memory Addresses index
 * 'https://gtamods.com/wiki/Memory_Addresses_(SA)'
 */
#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

class GameResources {

private: HANDLE GTA;

public: GameResources() {
	FindSAMP();
}

public: void FindSAMP() {
	HWND hwnd = FindWindowW(NULL, L"GTA:SA:MP"); // Handle the windows of the game.
	if (hwnd == NULL) {
		printf("Error: %s\n", "'SAMP' process not found!"); // Message if the window cannot be found.
		Sleep(5000);
		exit(-1);
	}

	DWORD procID;
	GetWindowThreadProcessId(hwnd, &procID);
	GTA = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); // Give all access to the process.

	if (procID == NULL) {
		printf("Error: %s\n", " Can not access to 'SAMP' PID!"); // Message if the window cannot be found.
		Sleep(3000);
		exit(-1);
	}
}

private: int ReadInt(DWORD pointerAddress) {
	int response = 0;
	if (!ReadProcessMemory(GTA, (LPVOID)pointerAddress, &response, sizeof(response), NULL)) {
		cout << "ReadProcessMemory FAILED" << endl;
		return -1;
	}
	return response;
}

private: float ReadFloat(DWORD pointerAddress) {
	float response = 0;
	if (!ReadProcessMemory(GTA, (LPVOID)pointerAddress, &response, sizeof(response), NULL)) {
		cout << "ReadProcessMemory FAILED" << endl;
		return -1;
	}
	return response;
}

private: DWORD GetPed() {
	DWORD cPED;
	ReadProcessMemory(GTA, (void*)0xB6F5F0, &cPED, sizeof(cPED), NULL);
	return cPED;
}

private: DWORD GetPlayerPoistion() {
	DWORD matrixPtr = 0;
	ReadProcessMemory(GTA, (void*)(GetPed() + 0x14), &matrixPtr, sizeof(matrixPtr), NULL);
	return matrixPtr;
}

private: DWORD GetCarPoistion() {
	DWORD carAddress;
	ReadProcessMemory(GTA, (void*)(GetPed() + 0x58C), &carAddress, sizeof(carAddress), 0);
	return carAddress;
}

private: DWORD getCarRotation() {
	DWORD RotationMatrix;
	ReadProcessMemory(GTA, (void*)(GetCarPoistion() + 20), &RotationMatrix, sizeof(RotationMatrix), 0);
	return RotationMatrix;
}

public: int GetMoney() {
	return ReadInt(0xB7CE50);
}

public: float GetPlayerX() {
	float positionX = 0;
	ReadProcessMemory(GTA, (void*)(GetPlayerPoistion() + 0x30), &positionX, sizeof(positionX), NULL);
	return positionX;
}

public: float GetPlayerY() {
	float positionY = 0;
	ReadProcessMemory(GTA, (void*)(GetPlayerPoistion() + 0x34), &positionY, sizeof(positionY), NULL);
	return positionY;
}

public: float GetPlayerZ() {
	float positionZ = 0;
	ReadProcessMemory(GTA, (void*)(GetPlayerPoistion() + 0x38), &positionZ, sizeof(positionZ), NULL);
	return positionZ;
}

public: bool IsInCar() {
	uint8_t pedStatus;
	ReadProcessMemory(GTA, (void*)(GetPed() + 0x46C), &pedStatus, sizeof(pedStatus), 0);
	return pedStatus == 1;
}

public: float GetCarRotationAngle() {
	float anglex_grad, anglez_grad, anglex_look, angley_look;

	DWORD MemoryAddress = getCarRotation() + 0;
	ReadProcessMemory(GTA, (void*)MemoryAddress, &anglex_grad, sizeof(anglex_grad), 0);

	MemoryAddress = getCarRotation() + 16;
	ReadProcessMemory(GTA, (void*)MemoryAddress, &anglex_look, sizeof(anglex_look), 0);

	MemoryAddress = getCarRotation() + 20;
	ReadProcessMemory(GTA, (void*)MemoryAddress, &angley_look, sizeof(angley_look), 0);

	MemoryAddress = getCarRotation() + 8;
	ReadProcessMemory(GTA, (void*)MemoryAddress, &anglez_grad, sizeof(anglez_grad), 0);

	if ((angley_look >= 0 && anglex_look >= 0) || (angley_look < 0 && anglex_look > 0)) {
		return acos(anglex_grad / cos(asin(anglez_grad))) * 180.0 / 3.1415;
	}
	return 360 - acos(anglex_grad / cos(asin(anglez_grad))) * 180.0 / 3.1415;
}

};