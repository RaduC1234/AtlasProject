#include "LibraryMain.hpp"
#include "levels/main_menu/MainMenuScene.hpp"

EXTERN_C const Scene *getLevel(const std::string& levelName) {
    if(levelName == "main_menu")
        return new MainMenuScene();

    return nullptr;
}
