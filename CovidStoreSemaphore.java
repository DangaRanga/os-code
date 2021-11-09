import java.util.concurrent.Semaphore;

public class CovidStoreSemaphore {
     //This example with use semaphore to access a store during the covid pandemic
     // Each thread will need to call acquire to access the resource.
     // When thread is done, it must call release
	//Constrant: max 4 people
	static Semaphore semaphore = new Semaphore(4);
    static String shopping = " is shopping at aisle: ";

	static class StoreThread extends Thread {

		String name = "";

		StoreThread(String name) {
			this.name = name;
		}

		public void run() {
			try {
				System.out.println(name + " : is going in to shop now (locking resource)...");
				System.out.println(name + " : Store (semaphore) now permits: " + semaphore.availablePermits());

				semaphore.acquire();
				System.out.println(name + " : I have now acquired the lock !");

                // simulating shopping
				try {
					for (int i = 1; i <= 5; i++) {
						System.out.println(name + shopping + i
								+ ", the total persons allowed : "
								+ semaphore.availablePermits());
						// sleep 2 second
						Thread.sleep(2000);
					}
				} finally {

					// calling release() after a successful acquire()
					System.out.println(name + " : Finished shopping. So leaving by bye   (releasing lock)");
					semaphore.release();
					System.out.println(name + " : Now the total persons allowed is:  "+ semaphore.availablePermits());
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}//End run()
	}//End StoreThread

	public static void main(String[] args) {

		System.out.println("As a result of the pandemic, the total persons allowed is : " + semaphore.availablePermits());

		StoreThread t1 = new StoreThread("Shopper 1");
		t1.start();

		StoreThread t2 = new StoreThread("Shopper 2");
		t2.start();

		StoreThread t3 = new StoreThread("Shopper 3");
		t3.start();

		StoreThread t4 = new StoreThread("Shopper 4");
		t4.start();

		StoreThread t5 = new StoreThread("Shopper 5");
		t5.start();

		StoreThread t6 = new StoreThread("Shopper 6");
		t6.start();

	}
}
