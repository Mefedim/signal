import { ISignalReceiver } from '../interfaces/ISignalReceiver';
import { ISignalDistributor } from '../interfaces/ISignalDistributor';
import { Signal } from '../models/Signal';

export class SignalReceiverImpl implements ISignalReceiver {
    private distributor: ISignalDistributor;

    constructor(distributor: ISignalDistributor) {
        this.distributor = distributor;
    }

    receiveSomeIP(data: Signal): void {
        console.log('Received SOME/IP data:', data);
        this.distribute('channel1', data);
        this.distribute('channel2', data);
    }

    receiveHTTP(data: Signal): void {
        console.log('Received HTTP data:', data);
        this.distribute('channel1', data);
        this.distribute('channel2', data);
    }

    receiveCAN(data: Signal): void {
        console.log('Received CAN data:', data);
        this.distribute('channel1', data);
        this.distribute('channel2', data);
    }

    receiveEthernet(data: Signal): void {
        console.log('Received Ethernet data:', data);
        this.distribute('channel1', data);
        this.distribute('channel2', data);
    }

    private distribute(channel: string, data: Signal): void {
        try {
            this.distributor.distributeSignal(channel, data);
        } catch (error) {
            console.error(`Error distributing signal on ${channel}:`, error);
        }
    }
}
