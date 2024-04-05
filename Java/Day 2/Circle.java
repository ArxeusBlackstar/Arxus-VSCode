import java.util.Scanner;

public class Circle {

    public static void main(String[] args) {

        Scanner aa = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = aa.nextDouble();

        double circumference = 2 * Math.PI * radius;
        double area = Math.PI * Math.pow(radius, 2);

        System.out.println("The circumference of the circle is " + circumference + " units.");
        System.out.println("The area of the circle is " + area + " units^2.");
    }
}
