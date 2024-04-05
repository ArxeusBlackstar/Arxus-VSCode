import java.util.Scanner;

public class Frequency {
    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);
        double C = 0.01, L, R, F = 1;

        System.out.println("Enter L ");
        L = aa.nextDouble();
        System.out.println("Enter R ");
        R = aa.nextDouble();

        for (int i = 1; i <= 10; i++) {

            C = i * 0.01;
            F = Math.sqrt((1 / (L * C)) - ((R * R) / (4 * C * C)));
            System.out.println("Frequency " + F + " at C " + C );
        }
    }
}
