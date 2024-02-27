package org.example;

public class RollerCoasterRide {
    private int waitingCount;
    private int K;
    private final Object lock = new Object();

    public RollerCoasterRide(int K) {
        waitingCount = 0;
        this.K = K;
    }
    
    public void childwork(Runnable arrive) throws InterruptedException {
        synchronized (lock) {
            while(waitingCount==K) {
                lock.wait();
            }
            
            arrive.run();
            waitingCount++;
            if(waitingCount==K)
                lock.notifyAll();
        }
    }
    
    public void MachineGuyWork(Runnable runTheWheel) throws InterruptedException {
        synchronized (lock) {
            while(waitingCount!=K) {
                lock.wait();
            }
            runTheWheel.run();
            waitingCount = 0;
            lock.notifyAll();
        }
    }
}
