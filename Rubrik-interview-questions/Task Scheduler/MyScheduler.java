package org.example.task.scheduler;

import java.util.concurrent.Semaphore;

public class MyScheduler {
    private final ThreadSafeQueue pq = new ThreadSafeQueue(10);
    private int count = 0;
    private Semaphore mutex = new Semaphore(1);
    private volatile boolean isRunning = true;
    private final Object lock = new Object();

    public void schedule(Task t) throws InterruptedException {
        synchronized (lock) {
            pq.add(t);
            lock.notify();
        }
    }

    public void start() throws InterruptedException {
        while(isRunning) {
            Task t = pq.remove();
            if(t!=null){
                new Thread(()->{t.run();}).start();
                mutex.acquire();
                count++;
                if(count==5) stop();
                mutex.release();
            }
        }
    }

    public void stop(){
        System.out.println("stopping scheduler");
        isRunning = false;
    }


}
