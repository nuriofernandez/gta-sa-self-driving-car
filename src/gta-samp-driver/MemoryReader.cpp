#include <Windows.h>
#include <iostream>

using namespace std;

class MemoryReader {

private:
    HANDLE process;
    string processName;
    LPCWSTR processNameLP;

public:
    MemoryReader(string processName) {
        // Obtain a long pointer to the process name string.
        wstring tempName = wstring(processName.begin(), processName.end());
        this->processNameLP = tempName.c_str();
        this->processName = processName;

        // Find process with that name.
        FindProcess();
    }

private:
    void FindProcess() {
        printf("Searching for process '%s'...\n", processName.c_str());
        bool hasHooked = HookToProcess();
        if (!hasHooked) {
            printf("Process '%s' not found. Retrying in 2 seconds...\n", processName.c_str());
            Sleep(2000);
            FindProcess();
        }
    }

private:
    bool HookToProcess() {
        // Find windows process with provided name.
        HWND hwnd = FindWindowW(NULL, processNameLP); // Handle the windows of the game/process.
        if (hwnd == NULL) {
            printf("Error: '%s' window process not found!\n", processName.c_str());
            return false;
        }

        // Find windows process with provided name.
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); // Give all access to the process.
        if (procID == NULL) {
            printf("Error: '%s' window process found but we can not access to process PID!\n", processName.c_str());
            return false;
        }

        // Process found, we can continue. :)
        return true;
    }

public:
    int ReadInt(DWORD pointerAddress) {
        int response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a int from '%s' memory address\n", &pointerAddress);
            FindProcess();
            throw -1;
        }
        return response;
    }

public:
    float ReadFloat(DWORD pointerAddress) {
        float response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a float from '%s' memory address\n", &pointerAddress);
            FindProcess();
            throw -1;
        }
        return response;
    }

public:
    DWORD ReadDWORD(DWORD pointerAddress) {
        DWORD response;
        if (!ReadProcessMemory(process, (void *) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a DWORD from '%s' memory address\n", &pointerAddress);
            FindProcess();
            throw -1;
        }
        return response;
    }

public:
    uint8_t ReadUint8(DWORD pointerAddress) {
        uint8_t response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), 0)) {
            printf("Error: Failed to read a int8 from '%s' memory address\n", &pointerAddress);
            FindProcess();
            throw -1;
        }
        return response;
    }

};

