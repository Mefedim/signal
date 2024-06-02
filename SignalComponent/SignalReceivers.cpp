#include "SignalReceivers.h"
#include <iostream>

void SomeIpReceiver::receiveSignal(const std::string& signal, const std::string& channel) {
    std::cout << "SomeIpReceiver received("<< channel << "): " << signal << std::endl;
}

void HttpReceiver::receiveSignal(const std::string& signal, const std::string& channel) {
    std::cout << "HttpReceiver received("<< channel << "): " << signal << std::endl;
}

void CanReceiver::receiveSignal(const std::string& signal, const std::string& channel) {
    std::cout << "CanReceiver received("<< channel << "): " << signal << std::endl;
}