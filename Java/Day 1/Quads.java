import java.util.Scanner;

public class Quads {
    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);

        int a, b, c, d, m, n;
        float x1 = 0, x2 = 0;

        System.out.println("Enter a ");
        a = aa.nextInt();
        System.out.println("Enter b ");
        b = aa.nextInt();
        System.out.println("Enter c ");
        c = aa.nextInt();
        System.out.println("Enter d ");
        d = aa.nextInt();
        System.out.println("Enter m ");
        m = aa.nextInt();
        System.out.println("Enter n ");
        n = aa.nextInt();

        if ((a * d) - (b * c) != 0) {
            x1 = (((m * d) - (n * b)) / ((a * d) - (b * c)));
            x2 = (((n * a) - (m * c)) / ((a * d) - (b * c)));
            System.out.println("X1 :- " + x1 + "\nX2 :- " + x2);
        }

        else {
            System.out.println("No pussibal");
        }
    }
}