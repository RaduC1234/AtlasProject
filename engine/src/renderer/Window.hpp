#pragma once

#include "Atlas.hpp"
#include "glm/glm.hpp"
#include "KeyCode.hpp"
#include <SFML/Graphics.hpp>

class Window {
public:

    Window(const std::string& title, int width, int height, bool vSync = true);

    ~Window();

    /**
     * Method to set the callback for key press events
     * @param callback The callback function to be called when a key is pressed.
     */
    void setKeyPressCallback(const std::function<void(KeyCode code)>& callback);

    /**
     * Method to set the callback for window close events
     * @param callback The callback function to be called when the window is closed.
     */
    void setCloseCallback(const std::function<void()>& callback);

    // Method to initialize window and any required setups
    void start();

    // Method to handle the event processing and rendering in each frame
    void update();

    // Method to clear the window (background color can be customized)
    void clear(glm::vec4 clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    // Method to display the window content
    void display();

    // Method to check if the window is open
    bool isOpen() const;

    // Method to close the window manually
    void close();

    // Returns the width of the window in pixels
    int getWidth();

    // Returns the height of the window in pixels
    int getHeight();

    // Returns the native window implementation
    void* getNativeWindow();


private:
    sf::RenderWindow window;
    std::function<void(sf::Keyboard::Key)> keyPressCallback;
    std::function<void()> closeCallback;

    void processEvents();
};
