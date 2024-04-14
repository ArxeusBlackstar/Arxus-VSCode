// java commandString
// Please provide a string as command-line argument

// java commandString Object Oriented Programming
// Programming Oriented Object
// gnimmargorP detneirO tcejbO

public class commandString {
	public static void main(String[] args) {
		if (args.length <1)
		{
			System.out.println("Please provide a string as command-line argument");
			System.exit(0);
		}
		String revChar="", revWord="", str= "";

		for (int i=args.length -1; i>=0; i--)
		{
			revWord+= args[i] + " ";
			for (int j=args[i].length() -1; j>=0; j--)
				revChar+=args[i].charAt(j);
			revChar+=" ";
		}
		System.out.println(revWord +"\n" + revChar);
	}
}
