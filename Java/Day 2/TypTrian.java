import java.util.Scanner;

public class TypTrian {

    public static void main(String[] args) {
        Scanner aa = new Scanner(System.in);

        System.out.print("Enter the triangle's three sides: ");
        int a, b, c;
        a = aa.nextInt();
        b = aa.nextInt();
        c = aa.nextInt();

        if (a == b && a == c) {
            System.out.println("The triangle is an equilateral triangle. Area: " + ((a * a) * (Math.sqrt(3))) / 4);
        } else if (a == b || b == c || c == a) {
            System.out.println("The triangle is isosceles. Area: " + (a * b) / 2);
        } else {
            System.out.println("The triangle is scalene. Area: " + (0.5 * (a + b + c)));
        }
    }
}
