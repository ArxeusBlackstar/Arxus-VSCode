public class Stringy 
{

	public static void main(String[] args) 
	{
		if(args.length < 1)
		{
			System.exit(0);
		}

        	String reversedString = "", revstr = "", str = "";
		
		for (int i = args.length - 1; i >= 0; i--)
		{
			str += args[i] + " ";
		}
		reversedString = rev(str);

		for (int i = 0; i < args.length; i++)
		{
			revstr = reverse(args);
		}
		System.out.println("Reversed by letter :- " + reversedString.trim());
		System.out.println("Reversed by word :- " + revstr.trim());
        	
	}

	public static String reverse(String[] string)
	{
		String reversedString = "";
		for (int i = string.length - 1; i >= 0; i--) 
		{

        	    reversedString += string[i] + " ";
        	}
		return reversedString;
	}

	public static String rev(String string)
	{
		String reversedString = "";
		for (int i = string.length() - 1; i >= 0; i--) 
		{

        	    reversedString += string.charAt(i);
        	}
		return reversedString;
	}
}