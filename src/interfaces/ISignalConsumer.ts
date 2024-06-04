import { Signal } from '../models/Signal';

export interface ISignalConsumer {
    consumeSignal(channel: string, signal: Signal): void;
}
