#include "SignalReceivers.h"
#include "FinalReceivers.h"
#include "SignalDispatcher.h"

class SignalComponent {
public:
    SignalComponent(SignalDispatcher& dispatcher, const std::string& channel) 
        : dispatcher(dispatcher), channel(channel) {}
    
    void receiveSignal(const std::string& signalType, const std::string& signal) {
        dispatcher.dispatchSignal(channel, signalType, signal);
    }

private:
    SignalDispatcher& dispatcher;
    std::string channel;
};

class SignalSetup {
public:
    static void setupAndRun() {
        SignalDispatcher dispatcher;
        registerReceivers(dispatcher);

        SignalComponent component1(dispatcher, "Channel1");
        SignalComponent component2(dispatcher, "Channel2");

        std::string someIpSignal = "SomeIp Test Signal";
        std::string httpSignal = "Http Test Signal";
        std::string canSignal = "Can Test Signal";

        component1.receiveSignal("SOME/IP", someIpSignal);
        component1.receiveSignal("HTTP", httpSignal);
        component1.receiveSignal("CAN", canSignal);

        component2.receiveSignal("SOME/IP", someIpSignal);
        component2.receiveSignal("HTTP", httpSignal);
        component2.receiveSignal("CAN", canSignal);

        component1.receiveSignal("UNKNOWN", "Unknown Test Signal");
        component2.receiveSignal("UNKNOWN", "Unknown Test Signal");
    }

private:
    static void registerReceivers(SignalDispatcher& dispatcher) {
        auto someIpReceiver1 = std::make_shared<SomeIpReceiver>();
        auto httpReceiver1 = std::make_shared<HttpReceiver>();
        auto canReceiver1 = std::make_shared<CanReceiver>();
        auto hmiReceiver1 = std::make_shared<HmiReceiver>();

        dispatcher.registerReceiver("Channel1", "SOME/IP", someIpReceiver1);
        dispatcher.registerReceiver("Channel1", "HTTP", httpReceiver1);
        dispatcher.registerReceiver("Channel1", "CAN", canReceiver1);
        dispatcher.registerIFinalReceiver("Channel1", "SOME/IP", hmiReceiver1);
        dispatcher.registerIFinalReceiver("Channel1", "HTTP", hmiReceiver1);
        dispatcher.registerIFinalReceiver("Channel1", "CAN", hmiReceiver1);

        auto someIpReceiver2 = std::make_shared<SomeIpReceiver>();
        auto httpReceiver2 = std::make_shared<HttpReceiver>();
        auto canReceiver2 = std::make_shared<CanReceiver>();
        auto hmiReceiver2 = std::make_shared<HmiReceiver>();

        dispatcher.registerReceiver("Channel2", "SOME/IP", someIpReceiver2);
        dispatcher.registerReceiver("Channel2", "HTTP", httpReceiver2);
        dispatcher.registerReceiver("Channel2", "CAN", canReceiver2);
        dispatcher.registerIFinalReceiver("Channel2", "SOME/IP", hmiReceiver2);
        dispatcher.registerIFinalReceiver("Channel2", "HTTP", hmiReceiver2);
        dispatcher.registerIFinalReceiver("Channel2", "CAN", hmiReceiver2);
    }
};

int main() {
    SignalSetup::setupAndRun();
    
    return 0;
}