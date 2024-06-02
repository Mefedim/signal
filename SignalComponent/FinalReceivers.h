#pragma once
#include "Interfaces.h"

class HmiReceiver : public IFinalReceiver {
public:
    void processSignal(const std::string& signal) override;
};
