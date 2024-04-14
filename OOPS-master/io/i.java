package io;
import java.util.*;
public class i
{
	static Scanner sc = new Scanner(System.in);
	public static int in(String s)
	{
		System.out.println(s);
		return sc.nextInt();
	}
	
	public static double db(String s)
	{
		System.out.println(s);
		return sc.nextDouble();
	}

	public static String str(String s)
	{
		System.out.println(s);
		return sc.next();
	}
}