#include "Server.hpp"
#include "LibraryLoader.hpp"

void Server::run() {

    Log::init();

    const char *dllPath = "scene_builder.dll";
    DLLLoader loader(dllPath);

    // Load the initial DLL
    if (!loader.Load()) {
        exit(1);
    }

    // Call the function from the DLL for the first time
    std::cout << loader.CallGetMessage() << std::endl;

    // Continuous loop to check if the DLL has changed
    while (true) {
        // Sleep for a short time (e.g., 1 second) before checking again
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Check if the DLL needs to be reloaded
        if (loader.CheckAndReload()) {
            // Call the function from the reloaded DLL
            std::cout << loader.CallGetMessage() << std::endl;
        }

        // Check for user input to exit the loop
        if (GetAsyncKeyState(VK_ESCAPE)) {
            break; // Exit the loop if the user presses the "Esc" key
        }
    }

}
