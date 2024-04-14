// Enter a number:
// 5
// Factorial: 120
// PS C:\Users\Pritam\.vscode\OOPS> cd "c:\Users\Pritam\.vscode\OOPS\" ; if ($?) { javac Factorial.java } ; if ($?) { java Factorial }
// Enter a number:
// 21
// Result will Overflow.
// PS C:\Users\Pritam\.vscode\OOPS> cd "c:\Users\Pritam\.vscode\OOPS\" ; if ($?) { javac Factorial.java } ; if ($?) { java Factorial }
// Enter a number:
// -1
// Value of x must be positive.

import io.*;
import java.util.*;

class Factorial {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = i.in("Enter a number: ");
		long[] fact = new long[21];
		fact[0] = 1;
		int last = 0;
		try	{
			if (x >= fact.length)
				throw new IllegalArgumentException("Result will Overflow.");
			else if (x < 0)
				throw new IllegalArgumentException("Value of x must be positive.");
			while (last < x) {
				fact[last + 1] = fact[last] * (last + 1);
				last++;
			}
			o.str("Factorial: ");
			o.lng(fact[x]);
		}
		catch (IllegalArgumentException e) 
		{
			System.out.println(e.getMessage());
		}
	}
}
