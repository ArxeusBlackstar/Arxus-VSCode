// PS C:\Users\Pritam\.vscode\OOPS> cd "c:\Users\Pritam\.vscode\OOPS\" ; if ($?) { javac PingPong.java } ; if ($?) { java PingPong }
// ping
// PONG
// PONG
// ping
// PONG
// ping
// PONG
// ping
// ping

import java.util.Random;

public class PingPong {
    public static void main(String[] args) {
        PingPongRunnable pingRunnable = new PingPongRunnable("ping");
        PingPongRunnable pongRunnable = new PingPongRunnable("PONG");

        Thread pingThread = new Thread(pingRunnable);
        Thread pongThread = new Thread(pongRunnable);

        pingThread.start();
        pongThread.start();
    }
}

class PingPongRunnable implements Runnable {
    private String message;
    private Random random;

    public PingPongRunnable(String message) {
        this.message = message;
        this.random = new Random();
    }

    @Override
    public void run() {
        try {
            while (true) {
                System.out.println(message);
                Thread.sleep(random.nextInt(1000) + 1000); 
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}