#pragma once

#include <lvgl.h>
#include "LvglState.h"
#include "Timer.h"
#include "StatusBar.h"
#include "../scales/ScalesTask.h"

class BrewState : public LvglState {
public:
    BrewState(
        const std::string& selectedCoffee,
        float inWeight,
        float ratio = 2.5f
    );
    ~BrewState() override = default;

    StateTransition loop() override;

private:
    Timer timer;
    
    ScalesTask scales;
    
    std::string selectedCoffee;
    float inWeight;
    float ratio;
    float targetWeight;
    
    lv_obj_t* weightLabel;
};
