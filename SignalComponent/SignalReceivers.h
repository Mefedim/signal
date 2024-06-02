#pragma once
#include "Interfaces.h"

class SomeIpReceiver : public ISignalReceiver {
public:
    void receiveSignal(const std::string& signal, const std::string& channel) override;
};

class HttpReceiver : public ISignalReceiver {
public:
    void receiveSignal(const std::string& signal, const std::string& channel) override;
};

class CanReceiver : public ISignalReceiver {
public:
    void receiveSignal(const std::string& signal, const std::string& channel) override;
};
