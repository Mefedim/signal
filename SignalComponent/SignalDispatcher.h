#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "Interfaces.h"

class SignalDispatcher {
public:
    void registerReceiver(const std::string& channel, const std::string& signalType, std::shared_ptr<ISignalReceiver> receiver);
    void registerIFinalReceiver(const std::string& channel, const std::string& signalType, std::shared_ptr<IFinalReceiver> IFinalReceiver);
    void dispatchSignal(const std::string& channel, const std::string& signalType, const std::string& signal);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<ISignalReceiver>>> receivers;
    std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IFinalReceiver>>> IFinalReceivers;
};
