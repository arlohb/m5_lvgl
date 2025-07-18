#pragma once

#include <mutex>
#include "State.h"
#include "StatusBar.h"

class LvglState : public State {
public:
    LvglState(const char* titleText, bool padding = true);
    ~LvglState() override;

    StateTransition loop() override;

protected:
    StatusBar statusBar;
    
    lv_obj_t* root;

    /// Mutex for the state transition.
    /// Only needs to be used when setting stateTransition from a different thread,
    std::mutex stateTransitionMutex;
    StateTransition stateTransition = std::nullopt;
};
