import java.util.*;

public class palindrome {
	public static void main(String[] args) {
		Scanner obj= new Scanner(System.in);
		System.out.println("Input to check palindrome:");
		String S1="", S= obj.next();
		S= S.toLowerCase();
		for (int i= S.length()-1; i>=0; i--)
			S1+= S.charAt(i);

		if (S.equals(S1))
			System.out.println("Palindrome");
		else
			System.out.println("Not a Palindrome");
	}
}