import { ISignalConsumer } from '../interfaces/ISignalConsumer';
import { Signal } from '../models/Signal';

export class HMIConsumerImpl implements ISignalConsumer {
    consumeSignal(channel: string, signal: Signal): void {
        console.log(`HMI consuming signal on ${channel}:`, signal);
    }
}
