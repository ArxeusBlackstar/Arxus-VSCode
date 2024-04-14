// Enter the string:
// Pritam Shaw@1234
// Upper Case: 2
// Lower Case: 8
// Digits: 4
// Spaces: 1
// Special Characters: 1

import java.util.Scanner;

public class countChar {
	public static void main(String[] args) {
		Scanner sc= new Scanner (System.in);
		System.out.println("Enter the string:");
		String s= sc.nextLine();
		char charArr[]= s.toCharArray();
		int upperCase=0, lowerCase=0, digit=0, space=0, specialChar=0; 
		for (int i=0; i<s.length(); i++)
		{
			if (Character.isUpperCase(charArr[i]))
				upperCase++;
			else if (Character.isLowerCase(charArr[i]))
				lowerCase++;
			else if (Character.isDigit(charArr[i]))
				digit++;
			else if (Character.isWhitespace(charArr[i]))
				space++;
			else
				specialChar++;
		}
		System.out.println("Upper Case: "+upperCase);
		System.out.println("Lower Case: "+lowerCase);
		System.out.println("Digits: "+digit);
		System.out.println("Spaces: "+space);
		System.out.println("Special Characters: "+specialChar);
	}
}
