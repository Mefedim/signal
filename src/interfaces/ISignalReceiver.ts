import { Signal } from '../models/Signal';

export interface ISignalReceiver {
    receiveSomeIP(data: Signal): void;
    receiveHTTP(data: Signal): void;
    receiveCAN(data: Signal): void;
    receiveEthernet(data: Signal): void;
}
