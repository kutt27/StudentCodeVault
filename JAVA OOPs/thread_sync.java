class Display{  
    public synchronized void print(String msg){  
        System.out.print("["+msg);  
        try{  
            Thread.sleep(1000);  
        }  
        catch(Exception e){  
            System.out.println(e.getMessage());  
        }  
        System.out.println("]");  
    }  
}  
class ThreadSyncDemo extends Thread{  
    private Display d;  
    private String msg;  
    public ThreadSyncDemo(Display d, String msg){  
        this.d = d;  
        this.msg = msg;  
    }  
    public void run(){  
        d.print(msg);  
    }  
}  
 class ThreadSync{  
     public static void main(String[] args) {  
         Display d = new Display();  
         ThreadSyncDemo t1 = new ThreadSyncDemo(d, "Hello");  
         ThreadSyncDemo t2 = new ThreadSyncDemo(d, "Jave");  
         t1.start();  
         t2.start();  
     }  
 }
