#include "SignalDispatcher.h"

#include <iostream>

void SignalDispatcher::registerReceiver(const std::string& channel, const std::string& signalType, std::shared_ptr<ISignalReceiver> receiver) {
    receivers[channel][signalType] = receiver;
}

void SignalDispatcher::registerIFinalReceiver(const std::string& channel, const std::string& signalType, std::shared_ptr<IFinalReceiver> IFinalReceiver) {
    IFinalReceivers[channel][signalType] = IFinalReceiver;
}

void SignalDispatcher::dispatchSignal(const std::string& channel, const std::string& signalType, const std::string& signal) {
    if (receivers[channel].find(signalType) != receivers[channel].end()) {
        receivers[channel][signalType]->receiveSignal(signal, channel);
    } else {
        std::cout << "No receiver registered for signal type: " << signalType << " on channel: " << channel << std::endl;
    }

    if (IFinalReceivers[channel].find(signalType) != IFinalReceivers[channel].end()) {
        IFinalReceivers[channel][signalType]->processSignal(signal);
    } else {
        std::cout << "No final receiver registered for signal type: " << signalType << " on channel: " << channel << std::endl;
    }
}