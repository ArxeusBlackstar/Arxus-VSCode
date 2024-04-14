import java.util.*;

public class armstrong {
	public static void main(String[] args) {
		Scanner obj= new Scanner (System.in);
		System.out.println("Enter a number:");
		int num= obj.nextInt();
		int numOfDigits= (int) Math.floor(Math.log10(num) + 1);
		int d, S=0, N1=num;

		while (N1>0)
		{
			d= N1 % 10;
			S+= Math.pow(d, numOfDigits);
			N1= N1 / 10;
		}

		if (S == num)
			System.out.println("Armstrong Number");
		else
			System.out.println("Not an Armstrong Number");
	}
}
