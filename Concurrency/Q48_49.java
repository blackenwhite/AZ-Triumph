/*
Consider an application that has K + 1 threads running on a Linux-like OS (K > 1). The first K
threads of an application execute a certain task T1, and the remaining one thread executes task T2.
The application logic requires that task T1 is executed N > 1 times, followed by task T2 executed
once, and this cycle of N executions of T1 followed by one execution of T2 continue indefinitely.
All K threads should be able to participate in the N executions of task T1, even though it is not
required to ensure perfect fairness amongst the threads.
Shown below is one possible set of functions executed by the threads running tasks T1 and T2.
You are told that this solution has two bugs in the code run by the thread performing task T2.
Briefly describe the bugs in the space below, and suggest small changes to the corresponding code
to fix these bugs (you may write your changes next to the code snippet). You must not change the
code corresponding to task T1 in any way. All threads share a counter count (initialized to 0), a
mutex variable m, and two condition variables t1cv, and t2cv. Here, the function signal on
a condition variable wakes up only one of the possibly many sleeping threads.




*/

package com.nabjo;

import java.util.concurrent.Semaphore;

public class Cycle {

    private int N;
    private int cnt;
    private Semaphore t1_sem;
    private Semaphore t2_sem;
    public Cycle(int N) {
        this.N = N;
        cnt = 0;
        t1_sem = new Semaphore(N);
        t2_sem = new Semaphore(0);
    }

    public void task1() {
        try {
            t1_sem.acquire(1);
            System.out.println("T1");
            cnt++;
            if(cnt==N) {
                t2_sem.release();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void task2() {
        try {
            t2_sem.acquire(1);
            System.out.println("T2");
            t1_sem.release(N);
            cnt=0;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
