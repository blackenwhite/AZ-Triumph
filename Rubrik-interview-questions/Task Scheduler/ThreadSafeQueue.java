package org.example.task.scheduler;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class ThreadSafeQueue {
    private final Queue<Task> pq;
    private int capacity;
    public ThreadSafeQueue(int capacity){
        this.capacity = capacity;
        pq = new LinkedList<>();
    }

    public boolean isEmpty(){
        synchronized (pq){
            while(pq.size()>0){
                try {
                    pq.wait();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            pq.notifyAll();
            return true;
        }
    }

    public boolean add(Task a) throws InterruptedException {
        synchronized (pq) {
            while(pq.size()==capacity){
                pq.wait();
            }
            pq.add(a);
            pq.notifyAll();
            return true;
        }
    }

    public Task remove() throws InterruptedException {
        synchronized (pq) {
            while(pq.size()==0){
                pq.wait();
            }
            Task ele = pq.poll();
            pq.notifyAll();
            return ele;
        }
    }
}
