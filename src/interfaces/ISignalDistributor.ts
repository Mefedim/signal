import { Signal } from '../models/Signal';

export interface ISignalDistributor {
    distributeSignal(channel: string, signal: Signal): void;
}
