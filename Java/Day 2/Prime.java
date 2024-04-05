import java.util.Scanner;

public class Prime {

    public static void main(String[] args) {

        Scanner aa = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        int num = aa.nextInt();

        boolean isPrime = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = false;
            }
        }

        System.out.println("The number is " + (isPrime ? "prime" : "not prime"));
    }
}
