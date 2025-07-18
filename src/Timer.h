#pragma once

#include <chrono>
#include <lvgl.h>

class Timer {
public:
    Timer();
    ~Timer();

    // Register the button press callback.
    // Called separately from the constructor because it relies on the address of this,
    // Which may be moved after the constructor.
    void registerOnPress();

    void update();
    void start();
    void stop();
    bool isRunning() const { return running; }
    float getElapsedSeconds() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::steady_clock::duration elapsedTime;
    bool running = false;

public:
    lv_obj_t* btn;
    lv_obj_t* label;
};
