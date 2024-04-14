import java.util.*;

public class leapYear {
	public static void main(String[] args) {
		Scanner obj= new Scanner(System.in);
		System.out.println("Enter a year:");
		int year= obj.nextInt();

		if (year%4==0 && (year%400==0 || year%100!=0))
			System.out.println("Leap Year");
		else
			System.out.println("Not a Leap Year");
	}
}
