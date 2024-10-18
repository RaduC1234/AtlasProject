#include "Window.hpp"
#include "KeyCode.hpp"
#include <SFML/Window/Event.hpp>

Window::Window(const std::string& title, int width, int height, bool vSync)
        : window(sf::VideoMode(width, height), title)
{
    window.setVerticalSyncEnabled(vSync);
}

Window::~Window() {
    if (window.isOpen()) {
        window.close();
    }
}

void Window::setKeyPressCallback(const std::function<void(KeyCode)>& callback) {

    keyPressCallback = [callback](sf::Keyboard::Key sfKey) {
        auto customKey = static_cast<KeyCode>(sfKey);
        callback(customKey);
    };
}

void Window::setCloseCallback(const std::function<void()>& callback) {
    closeCallback = callback;
}

void Window::start() {

}

void Window::update() {
    processEvents();
}

void Window::clear(glm::vec4 clearColor) {

    sf::Color sfColor(
            static_cast<sf::Uint8>(clearColor.r * 255),
            static_cast<sf::Uint8>(clearColor.g * 255),
            static_cast<sf::Uint8>(clearColor.b * 255),
            static_cast<sf::Uint8>(clearColor.a * 255)
    );
    window.clear(sfColor);
}

void Window::display() {
    window.display();
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::close() {
    window.close();
}

int Window::getWidth() {
    return window.getSize().x;
}

int Window::getHeight() {
    return window.getSize().y;
}

void Window::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            if (closeCallback) {
                closeCallback();
            }
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (keyPressCallback) {
                keyPressCallback(event.key.code);
            }
        }
    }
}

void *Window::getNativeWindow() {
    return &window;
}
