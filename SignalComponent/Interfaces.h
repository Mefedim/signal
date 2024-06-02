#pragma once
#include <string>

class ISignalReceiver {
public:
    virtual ~ISignalReceiver() = default;
    virtual void receiveSignal(const std::string& signal, const std::string& channel) = 0;
};

class IFinalReceiver {
public:
    virtual ~IFinalReceiver() = default;
    virtual void processSignal(const std::string& signal) = 0;
};