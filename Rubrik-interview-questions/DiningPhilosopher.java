package org.example;

import java.util.concurrent.Semaphore;

class Philosopher extends Thread{
    private int id;
    private Semaphore leftFork;
    private Semaphore rightFork;

    public Philosopher(int id, Semaphore leftFork, Semaphore rightFork) {
        this.id = id;
        this.leftFork = leftFork;
        this.rightFork = rightFork;
    }

    public void run() {
        int n = 3;
        try {
            while (n>0) {
                // starting with think is important, otherwise leads to deadlock
                think();
                eat();
                n--;
            }
        } catch(InterruptedException e){
            System.out.println("Philosopher " + id + " is interrupted");
        }
    }

    private void think() throws InterruptedException {
        System.out.println("Philosopher "+id + " is thinking");
        Thread.sleep((long)(Math.random()*1000));
    }

    private void eat() throws InterruptedException{
//        mutex.acquire();
        leftFork.acquire();
        System.out.println("Philosopher " + id + " has acquired leftFork");
        rightFork.acquire();
//        mutex.release();
        System.out.println("Philosopher " + id + " has acquired rightFork");
        System.out.println("Philosopher " + id + " has started eating");
        Thread.sleep((long)(Math.random()*1000));
        System.out.println("Philosopher " + id + " has finished eating");
        leftFork.release();
        rightFork.release();
    }



}

public class DiningPhilosopherSimul {


    public static final int n = 5;
    public static void main(String[] args) {
        Semaphore[] forks = new Semaphore[n];
        for(int i=0;i<n;i++){
            forks[i] = new Semaphore(1);
        }

        Philosopher[] philosophers = new Philosopher[n];
        for(int i=0;i<n;i++){
            philosophers[i] = new Philosopher(i,forks[i], forks[(i+1)%n]);
            philosophers[i].start();
        }



    }
}
