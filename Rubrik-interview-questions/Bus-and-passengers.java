package org.example;

import java.util.concurrent.Semaphore;

public class BusAndPassengers{

    private int waitingCnt, k;
    private final Semaphore mutex = new Semaphore(1);

    private final Semaphore busArrived, passengersBoarded;

    public BusAndPassengers(int k) {
        this.waitingCnt = 0;
        this.k = k;
        this.busArrived = new Semaphore(0);
        this.passengersBoarded = new Semaphore(0);
    }

    private void board() {
        System.out.println(Thread.currentThread().getName() + "has boarded the bus.");
    }

    private void depart() {
        System.out.println(Thread.currentThread().getName() + "has departed.");
    }

    public void passengerWork() throws InterruptedException {
        mutex.acquire();
        waitingCnt++;
        mutex.release();
        busArrived.acquire();
        board();
        passengersBoarded.release();
    }

    public void BusWork() throws InterruptedException {
        mutex.acquire();
        int n = Math.min(waitingCnt, k);
        for(int i=0;i<n;i++){
            busArrived.release();
            passengersBoarded.acquire();
        }
        waitingCnt = waitingCnt-n;
        System.out.println(n + " passengers have boarded");
        depart();
        mutex.release();


    }

}
