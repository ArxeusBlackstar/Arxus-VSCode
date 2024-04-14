// Days:    1
// Hours:   1
// Minutes: 45
// Seconds: 40

public class Time {
	int hour, min, sec;

	public Time (int hour, int min, int sec)
	{
		this.hour = hour;
		this.min = min;
		this.sec = sec;
	}

	public void add(Time otherTime)
	{
		int totalSec= (this.hour + otherTime.hour)*3600 + (this.min + otherTime.min)*60 + (this.sec + otherTime.sec);
		int resultSec= totalSec%60;
		int resultMin= (totalSec/60)%60;
		int resultHour= (totalSec/3600)%24;
		int resultDay= totalSec/86400;
		System.out.println("Days:    "+resultDay+"\nHours:   "+resultHour+"\nMinutes: "+resultMin+"\nSeconds: "+resultSec+"\n\n");
	}

	public static void main(String[] args) {
		Time Time1= new Time(24, 30, 10);
		Time Time2= new Time(1, 15, 30);

		Time1.add(Time2);
	}
}
