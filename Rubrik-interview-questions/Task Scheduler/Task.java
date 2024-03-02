package org.example.task.scheduler;

class Task{
    int priority;
    private String name;
    private final int index;
    public Task(String name, int priority, int index) {
        this.name = name;
        this.priority = priority;
        this.index = index;
    }

    public void run() {
        System.out.println("task "+name+" started");
        try {
            Thread.sleep(index*60);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("task "+name+" finished");
    }
}
