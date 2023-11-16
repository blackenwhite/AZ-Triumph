/*
 Multiple people are entering and exiting a room that has a light switch. You are writing a computer
program to model the people in this situation as threads in an application. You must fill in the
functions onEnter() and onExit() that are invoked by a thread/person when the person
enters and exits a room respectively. We require that the first person entering a room must turn
on the light switch by invoking the function turnOnSwitch(), while the last person leaving
the room must turn off the switch by invoking turnOffSwitch(). You must invoke these
functions suitably in your code below. You may use any synchronization primitives of your choice
to achieve this desired goal. You may also use any variables required in your solution, which are
shared across all threads/persons.
(a) Variables and initial values
(b) Code onEnter() to be run by thread/person entering
(c) Code onExit() to be run by thread/person exiting

*/

package com.nabjo;

public class Room {

    private int cnt;
    private final Object lock = new Object();

    public Room() {
        cnt = 0;
    }

    public void onEnter(Runnable turnOnSwitch) {
        synchronized(lock) {
            System.out.println(Thread.currentThread().getName() + " entering the room");
            if(cnt==0) {
                turnOnSwitch.run();
            }
            cnt++;
        }
    }

    public void onExit(Runnable turnOffSwitch) {
        synchronized (lock) {
            cnt--;
            System.out.println(Thread.currentThread().getName() + " exiting the room");
            if(cnt==0) {
                turnOffSwitch.run();
            }

        }
    }
}
