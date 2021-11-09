public class Shopping {
    private String buying;
    private boolean isDoing;

    public synchronized void putItem(String item) {
        while (isDoing) {
            try {
                wait();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } // endwhile
        isDoing = true;
        this.buying = item; 
        notify();
    }// end putItem

    public synchronized String buyItem() {
        while (!isDoing) {
            try {
                wait();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        isDoing = false;
        notify();
        return "Buying " + buying + " at time: " + System.nanoTime();
    }// end
}// end shopping
