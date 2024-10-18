/*
#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

using EventType = std::string;

class Event {
public:
    virtual EventType getEventType() const = 0;

    virtual std::string getName() const = 0;

    virtual ~Event() = default;

    bool handled = false;

    bool operator<(const Event &other) const {
        return this->priority < other.priority;
    }

protected:
    int priority = 0;
};

using EventCallback = std::function<void(Event &)>;

class EventSystem {
public:
    EventSystem(const EventSystem &) = delete;

    EventSystem &operator=(const EventSystem &) = delete;

    */
/**
     * Adds a persistent callback listener to the event system.
     * @param eventType The event type to listen for.
     * @param callback The callback to be invoked when the event is triggered.
     *//*

    static void addListener(const EventType &eventType, const EventCallback &callback) {
        listeners[eventType].push_back(callback);
    }

    */
/**
     * Removes a callback listener.
     * @param eventType The event type associated with the callback.
     * @param callback The callback to remove.
     *//*

    static void removeListener(const EventType &eventType, const EventCallback &callback) {
        auto &callbacks = listeners[eventType];
        callbacks.erase(
                std::remove_if(callbacks.begin(), callbacks.end(), [&callback](const EventCallback &c) {
                    return c.target<void(Event &)>() == callback.target<void(Event &)>();
                }), callbacks.end()
        );
    }

    */
/* TODO: fix
     *
     * Subscribes to an event type with a temporary listener.
     * This listener will be removed after it's called once.
     * @param eventType The event type to subscribe to.
     * @param callback The callback function.
     *//*
*/
/*
    static void subscribe(const EventType &eventType, const EventCallback &callback) {
        // Define a temporary callback that will be removed after it is called
        auto tempCallback = [eventType, callback](Event &event) mutable {
            callback(event);
            removeListener(event.getEventType(), tempCallback); // This will be modified
        };

        // Store the temporary callback in the listeners vector
        listeners[eventType].push_back(tempCallback);
    }*//*


    */
/*
    * Publishes an event, adding it to the event queue for processing.
    * @param event The event to be published (must be a derived type of Event).
    *//*

    static void publish(Event &event) {
        eventQueue.push(CreateScope<Event>(event));
    }

    */
/**
     * Processes events in the queue, invoking their associated listeners.
     *//*

    static void processEvents() {
        while (!eventQueue.empty()) {

            auto it = listeners.find(eventQueue.top()->getEventType());
            if (it != listeners.end()) {
                for (auto &callback: it->second) {
                    callback(*eventQueue.top());
                    if (eventQueue.top()->handled) {
                        break; // Stop processing if the event was handled.
                    }
                }
            }
        }
        eventQueue.pop();
    }

private:
    static std::unordered_map<EventType, std::vector<EventCallback>> listeners;
    static std::priority_queue<Scope<Event>> eventQueue;
};
*/
