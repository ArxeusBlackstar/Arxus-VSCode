// PS C:\Users\Pritam\.vscode\OOPS> java University
// Enter the string:
// u
// String did not match
// PS C:\Users\Pritam\.vscode\OOPS> java University
// Enter the string:
// University
// The String matches

import java.util.*;
import io.*;

class University
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String s= i.str("Enter the string: ");
		try 
		{
			if(!s.equals("University")) 
			{
				throw new NoMatchFoundException("String did not match\n");
			} 
			else 
			{
				o.str("The String matches\n");
			}
		} 
		catch (NoMatchFoundException e) 
		{
			o.str(e.getMessage());
		}
	}
}


class NoMatchFoundException extends Exception 
{
	public NoMatchFoundException(String message) 
	{
		super(message);
	}
}

