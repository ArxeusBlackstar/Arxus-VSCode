import java.util.Scanner;

public class circle {
	public static void main(String[] args) {
		Scanner obj= new Scanner (System.in);
		System.out.println("Enter radius:");
		int r= obj.nextInt();
		double area= Math.PI * r * r;
		double circumference= 2 * Math.PI * r;
		System.out.println("Area: "+area+" sq. units");
		System.out.println("Circumference: "+circumference+" units");
	}
}
