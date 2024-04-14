import java.util.*;

public class prime {
	public static void main(String[] args) {
		Scanner obj= new Scanner (System.in);
		System.out.println("Enter a number:");
		int num= obj.nextInt();
		for (int i=2; i<Math.sqrt(num); i++)
			if (num % i == 0)
			{
				System.out.println("Composite Number");
				System.exit(0);
			}
		System.out.println("Prime Number");
	}
}