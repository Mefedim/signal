import { ISignalDistributor } from '../interfaces/ISignalDistributor';
import { ISignalConsumer } from '../interfaces/ISignalConsumer';
import { Signal } from '../models/Signal';

export class SignalDistributorImpl implements ISignalDistributor {
    private consumers: ISignalConsumer[];

    constructor(consumers: ISignalConsumer[]) {
        this.consumers = consumers;
    }

    distributeSignal(channel: string, signal: Signal): void {
        console.log(`Distributing signal on ${channel}:`, signal);
        this.consumers.forEach(consumer => consumer.consumeSignal(channel, signal));
    }
}
