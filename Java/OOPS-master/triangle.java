import java.util.Scanner;

public class triangle {
	public static void main(String[] args) {
		Scanner obj= new Scanner (System.in);
		System.out.println("Enter the 3 sides of the triangle:");
		double A= obj.nextDouble();
		double B= obj.nextDouble();
		double C= obj.nextDouble();

		if (A*A== B*B + C*C || B*B== C*C + A*A || C*C == B*B + A*A)
			System.out.print("Right-angled ");

		if (A==B && B==C)
			System.out.print("Equilateral");
		else if (A==B || B==C || C==A)
			System.out.print("Isoceles");
		else
			System.out.print("Scalene");
		System.out.println(" Triangle");

		double S=(A+B+C)/2;
		double area= Math.sqrt(S*(S-A)*(S-B)*(S-C));
		System.out.println("Area: "+area+" sq.units");
	}
}
