public class CovidStore {

    public static void main(String[] args){
        final Shopping shop = new Shopping(); 

        Thread shelvingThread = new Thread(){
            @Override
            public void run(){
                System.out.println("Shelving thread started ...");
                String [] items = {"Onions", "Beans", "Carrots","Apples"};
                for(int i = 0; i < items.length; i++){
                    shop.putItem(items[i]);
                    System.out.println("Placing "+items[i]+" on shelf at time: " + System.nanoTime());
                }
            }//endrun
        };//end shelvingThread


        Thread buyingThread1 = new Thread(){
            @Override
            public void run(){
                System.out.println("Buying Thread 1 started ...");
                for(int i=1; i<=2; i++){
                    System.out.println(" Thread 1 Buying " + shop.buyItem());
                }
            }//endrun
        };//end buyingThread1




        Thread buyingThread2 = new Thread(){
            @Override
            public void run(){
                System.out.println("Buying Thread 2 started ...");
                for(int i=1; i<=3; i++){
                    System.out.println("Thread 2 Buying " + shop.buyItem());
                }
            }//endrun
        };//end buyingThread2




        buyingThread1.start();
        buyingThread2.start();
        shelvingThread.start();

    }//endmain
}//endCovidStore
  