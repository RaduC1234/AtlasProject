#pragma once

#include "core/Core.hpp"

class ATLAS_API Scene {
public:

    Scene() = default;

    virtual ~Scene() = default;

    virtual void onCreate() =0;

    virtual void onStart() = 0;

    virtual void onUpdate(float deltaTime) = 0;

    virtual void onRender(int screenWidth, int screenHeight) = 0;

    virtual void onDestroy() = 0;

protected:

    //LayerStack layers;
    //Registry registry;
    //ResourceBundle *resourceBundle;
};
