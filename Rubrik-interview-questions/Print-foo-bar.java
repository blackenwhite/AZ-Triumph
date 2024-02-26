class FooBar {
    private int n;
    private int fooN;
    private int barN;

    private final Object lock = new Object();

    public FooBar(int n) {
        this.n = n;
        this.fooN = 0;
        this.barN = 0;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        synchronized (lock) {
            for(int i=0;i<n;i++) {
                while(fooN!=barN){
                    lock.wait();
                }
                printFoo.run();
                fooN++;
                lock.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        synchronized (lock) {
            for(int i=0;i<n;i++){
                while(fooN<=barN){
                    lock.wait();
                }
                printBar.run();
                barN++;
                lock.notifyAll();
            }
        }
    }
}
