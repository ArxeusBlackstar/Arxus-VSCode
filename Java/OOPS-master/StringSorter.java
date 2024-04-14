// Enter strings (type 'done' when finished):
// abc
// aaa
// cda
// bbc
// done
// Sorted list of strings:
// aaa
// abc
// bbc
// cda
// Program completed.

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class StringSorter {
    private static List<String> stringList = Collections.synchronizedList(new ArrayList<>());

    public static void main(String[] args) {
        Thread userInputThread = new Thread(new UserInputThread());
        userInputThread.start();

        try {
            userInputThread.join(); 
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        Thread sortingThread = new Thread(new SortingThread());
        Thread displayThread = new Thread(new DisplayThread());

        sortingThread.start();
        displayThread.start();

        try {
            sortingThread.join(); 
            displayThread.join(); 
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Program completed.");
    }

    static class UserInputThread implements Runnable {
        @Override
        public void run() {
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter strings (type 'done' when finished):");
            String input;
            do {
                input = scanner.nextLine();
                if (!input.equals("done")) {
                    stringList.add(input);
                }
            } while (!input.equals("done"));
        }
    }

    static class SortingThread implements Runnable {
        @Override
        public void run() {
            Collections.sort(stringList);
        }
    }

    static class DisplayThread implements Runnable {
        @Override
        public void run() {
            try {
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Sorted list of strings:");
            for (String str : stringList) {
                System.out.println(str);
            }
        }
    }
}