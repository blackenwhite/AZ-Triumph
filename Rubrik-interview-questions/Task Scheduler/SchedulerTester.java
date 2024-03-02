package org.example.task.scheduler;

public class SchedulerTester {
    public static void main(String[] args) throws InterruptedException {
        final MyScheduler taskScheduler = new MyScheduler();

        new Thread(()-> {
            try {
                taskScheduler.schedule(new Task("1", 10, 10));
                taskScheduler.schedule(new Task("2", 11, 1));
                taskScheduler.schedule(new Task("3", 9, 6));
                taskScheduler.schedule(new Task("4", 12, 4));
                taskScheduler.schedule(new Task("3", 8, 7));
            } catch (InterruptedException e){
                e.printStackTrace();
            }
        }).start();

        new Thread(()->{
            try {
                taskScheduler.start();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }, "SchedulerThread").start();
        System.out.println("exiting main thread");
    }
}
