import java.util.Scanner;

public class Leap {
    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);

        System.out.print("Enter a year: ");
        int year = aa.nextInt();

        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    System.out.println("It's a leap year");
                } else {
                    System.out.println("It's not a leap year");
                }
            } else {
                System.out.println("It's a leap year");
            }
        } else {
            System.out.println("It's not a leap year");
        }
    }
}
