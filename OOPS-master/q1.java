// Enter a, b, c, d, m, n:
// 4 3 2 1 18 8
// X1: 3.0
// X2: 2.0

import java.util.Scanner;

public class q1 {
	public static void main(String[] args) {
		Scanner obj= new Scanner (System.in);
		System.out.println("Enter a, b, c, d, m, n: ");
		int a= obj.nextInt();
		int b= obj.nextInt();
		int c= obj.nextInt();
		int d= obj.nextInt();
		int m= obj.nextInt();
		int n= obj.nextInt();

		if (a*d-b*c == 0)
		{
			System.out.println("Cannot Divide by 0");
			System.exit(0);
		}
		double x1= (double) (m*d - b*n)/(a*d - b*c);
		double x2= (double) (n*a - m*c)/(a*d - b*c);
		System.out.println("X1: "+x1);
		System.out.println("X2: "+x2);
	}
}
