import java.util.Scanner;

public class Time 
{
	int hour;
	int min;
	int sec;


	public Time(int hour, int min, int sec) 
	{
		this.hour = hour;
		this.min = min;
		this.sec = sec;
	}
	
	public void add(Time t) 
	{
		int newHour = this.hour + t.hour;
		int newMin = this.min + t.min;
        	int newSec = this.sec + t.sec;
		int newDay = 0;
	
        	if (newSec >= 60) 
		{
        		newMin += newSec / 60;
        		newSec %= 60;
        	}
        	if (newMin >= 60) 
		{
        		newHour += newMin / 60;
       	 		newMin %= 60;
        	}
        	if (newHour >= 24) 
		{
			newDay += newHour / 24;
        		newHour %= 24;
        	}

		if(newDay >= 0)
		{
			System.out.print(newDay + " Days ");
		}

        	System.out.println( newHour + " hours " + newMin + " minutes " + newSec + " seconds");
    	}

   	public static void main(String[] args) 
	{

        	Scanner aa = new Scanner(System.in);

        	System.out.println("Enter hour");
        	int hour1 = aa.nextInt();
        	System.out.println("Enter min");
        	int minute1 = aa.nextInt();
        	System.out.println("Enter sec");
        	int sec1 = aa.nextInt();
        	Time time1 = new Time(hour1, minute1, sec1);

        	System.out.println("Enter hour");
        	int hour2 = aa.nextInt();
        	System.out.println("Enter min");
        	int minute2 = aa.nextInt();
        	System.out.println("Enter sec");
        	int sec2 = aa.nextInt();
        	Time time2 = new Time(hour2, minute2, sec2);

        	time1.add(time2);

	
    	}
}
