#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>

// Typedef for the function pointer
typedef const char* (*GetMessageFunc)();

class DLLLoader {
public:
    DLLLoader(const std::string& dllPath) : originalDLLPath(dllPath), hModule(nullptr) {
        lastWriteTime = GetLastWriteTime(dllPath.c_str());
    }

    ~DLLLoader() {
        if (hModule) {
            FreeLibrary(hModule);
        }
        if (!tempDLLPath.empty()) {
            DeleteFile(tempDLLPath.c_str());
        }
    }

    // Load the initial DLL
    bool Load() {
        tempDLLPath = CopyDLLToTemp();
        if (tempDLLPath.empty()) return false;

        hModule = LoadLibrary(tempDLLPath.c_str());
        if (!hModule) {
            std::cerr << "Could not load the copied DLL!" << std::endl;
            return false;
        }

        GetMessage = (GetMessageFunc)GetProcAddress(hModule, "GetMessage");
        if (!GetMessage) {
            std::cerr << "Could not locate the GetMessage function!" << std::endl;
            FreeLibrary(hModule);
            hModule = nullptr;
            return false;
        }

        return true;
    }

    // Check if the original DLL has changed, and reload if necessary
    bool CheckAndReload() {
        FILETIME currentWriteTime = GetLastWriteTime(originalDLLPath.c_str());
        if (CompareFileTime(&currentWriteTime, &lastWriteTime) != 0) {
            // DLL has been modified, unload the current DLL and delete the old copy
            if (hModule) {
                FreeLibrary(hModule);
            }
            if (!tempDLLPath.empty()) {
                DeleteFile(tempDLLPath.c_str());
            }

            // Update the last known write time
            lastWriteTime = currentWriteTime;

            // Copy the DLL to a temporary location again and reload it
            tempDLLPath = CopyDLLToTemp();
            if (tempDLLPath.empty()) return false;

            hModule = LoadLibrary(tempDLLPath.c_str());
            if (!hModule) {
                std::cerr << "Could not reload the copied DLL!" << std::endl;
                return false;
            }

            // Get the address of the GetMessage function again
            GetMessage = (GetMessageFunc)GetProcAddress(hModule, "GetMessage");
            if (!GetMessage) {
                std::cerr << "Could not locate the GetMessage function in the updated DLL!" << std::endl;
                FreeLibrary(hModule);
                hModule = nullptr;
                return false;
            }
            return true;
        }
        return false;
    }

    // Call the GetMessage function
    const char* CallGetMessage() {
        if (GetMessage) {
            return GetMessage();
        }
        return "Function not available.";
    }

private:
    std::string originalDLLPath;
    std::string tempDLLPath;
    HMODULE hModule;
    GetMessageFunc GetMessage;
    FILETIME lastWriteTime;

    // Helper function to get the last modification time of the DLL
    FILETIME GetLastWriteTime(const char* dllPath) {
        WIN32_FILE_ATTRIBUTE_DATA fileInfo;
        if (GetFileAttributesEx(dllPath, GetFileExInfoStandard, &fileInfo)) {
            return fileInfo.ftLastWriteTime;
        }

        FILETIME defaultTime = {0, 0};
        return defaultTime;
    }

    // Helper function to copy the DLL to a temporary location
    std::string CopyDLLToTemp() {
        std::string tempDLLPath = "MyDLL_temp.dll";
        if (!CopyFile(originalDLLPath.c_str(), tempDLLPath.c_str(), FALSE)) {
            std::cerr << "Failed to copy DLL to temp location." << std::endl;
            return "";
        }
        return tempDLLPath;
    }
};
