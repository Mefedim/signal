import { SignalReceiverImpl } from './implementations/SignalReceiverImpl';
import { SignalDistributorImpl } from './implementations/SignalDistributorImpl';
import { HMIConsumerImpl } from './implementations/HMIConsumerImpl';
import { Signal } from './models/Signal';

// create some example signals
const someIpSignal: Signal = { id: 1, value: 'SomeIP Data', priority: 1, timestamp: new Date() };
const httpSignal: Signal = { id: 2, value: 'HTTP Data', priority: 2, timestamp: new Date() };
const canSignal: Signal = { id: 3, value: 'CAN Data', priority: 1, timestamp: new Date() };
const ethernetSignal: Signal = { id: 4, value: 'Ethernet Data', priority: 3, timestamp: new Date() };

// instantiate the consumers
const hmiConsumer = new HMIConsumerImpl();

// instantiate the distributor with consumers
const distributor = new SignalDistributorImpl([hmiConsumer]);

// instantiate the receiver with the distributor
const receiver = new SignalReceiverImpl(distributor);

// simulate receiving signals on different protocols
receiver.receiveSomeIP(someIpSignal);
receiver.receiveHTTP(httpSignal);
receiver.receiveCAN(canSignal);
receiver.receiveEthernet(ethernetSignal);
