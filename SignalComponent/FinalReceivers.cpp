#include "FinalReceivers.h"
#include <iostream>

void HmiReceiver::processSignal(const std::string& signal) {
    std::cout << "HMI processed: " << signal << std::endl;
}