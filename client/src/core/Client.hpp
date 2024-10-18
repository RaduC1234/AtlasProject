#pragma once

#include "Atlas.hpp"

#include "glm/glm.hpp"

class Client {
public:
    Client();
    ~Client() = default;
    void run();
private:
    Scope<Window> window;
};
