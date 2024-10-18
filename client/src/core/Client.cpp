#include "Client.hpp"
#include "utils/Time.hpp"
#include <SFML/Graphics.hpp>

Client::Client() {
    Log::init();
}

void Client::run() {

    AT_INFO("Hello from Client");


    this->window = CreateScope<Window>("Atlas Window", 1000, 200);

    this->window->setCloseCallback([&]() {
        this->window->close();
    });

    this->window->display();

    while (window->isOpen()) {

        float beginTime = Time::getTime();
        float endTime;
        float dt = -1.0f;


        sf::Event event;
        while (reinterpret_cast<sf::RenderWindow *>(window->getNativeWindow())->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }


        endTime = Time::getTime();
        dt = endTime - beginTime;
        beginTime = endTime;
    }
}
