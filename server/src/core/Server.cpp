//
// Created by Radu on 06-Oct-24.
//

#include "Server.hpp"

void Server::run() {

    Log::init();

    while(isRunning) {
        AT_CORE_INFO("Server is running");
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
