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

public: int GetMoney() {
	return ReadInt(0xB7CE50);
}

public: int GetPed() {
	return ReadInt(0xB6F5F0);
}

public: float GetX() {
	DWORD cPED;
	ReadProcessMemory(GTA, (void*)0xB6F5F0, &cPED, sizeof(cPED), NULL);
	DWORD matrixPtr = 0;
	ReadProcessMemory(GTA, (void*)(cPED + 0x14), &matrixPtr, sizeof(matrixPtr), NULL);
	float positionX = 2696.3816;
	ReadProcessMemory(GTA, (void*)(matrixPtr + 0x30), &positionX, sizeof(positionX), NULL);
	return positionX;
}

public: float GetY() {
	DWORD cPED;
	ReadProcessMemory(GTA, (void*)0xB6F5F0, &cPED, sizeof(cPED), NULL);
	DWORD matrixPtr = 0;
	ReadProcessMemory(GTA, (void*)(cPED + 0x14), &matrixPtr, sizeof(matrixPtr), NULL);
	float positionY = 2696.3816;
	ReadProcessMemory(GTA, (void*)(matrixPtr + 0x34), &positionY, sizeof(positionY), NULL);
	return positionY;
}

public: float GetZ() {
	DWORD cPED;
	ReadProcessMemory(GTA, (void*)0xB6F5F0, &cPED, sizeof(cPED), NULL);
	DWORD matrixPtr = 0;
	ReadProcessMemory(GTA, (void*)(cPED + 0x14), &matrixPtr, sizeof(matrixPtr), NULL);
	float positionZ = 2696.3816;
	ReadProcessMemory(GTA, (void*)(matrixPtr + 0x38), &positionZ, sizeof(positionZ), NULL);
	return positionZ;
}

};