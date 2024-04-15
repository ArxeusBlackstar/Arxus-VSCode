import java.util.Scanner;

public class Mainrunner {
    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);

        while (true) {
            System.out.println(
                    "Enter \n 1 for Trapezoid \n 2 for Parallelogram \n 3 for Rectangle \n 4 for Square \n 5 to GTFO");
            int ch = aa.nextInt();
            int x[] = new int[4];
            int y[] = new int[4];

            for (int i = 0; i < 4; i++) {

                System.out.print("Enter x" + (i+1) + " ");
                x[i] = aa.nextInt();
                System.out.print("Enter y" + (i+1) + " ");
                y[i] = aa.nextInt();

                System.out.println();

            }
        }
    }
}
