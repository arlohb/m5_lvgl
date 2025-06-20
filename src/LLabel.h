#pragma once

#include "LObject.h"

class LLabel : public LObject {
public:
    LLabel() = default;
    LLabel(LObject& parent);

    char* getText();
    void setText(std::string text);
};

