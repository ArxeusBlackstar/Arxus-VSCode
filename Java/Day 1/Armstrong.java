import java.util.Scanner;

public class Armstrong
{
    public static void main()
    {
        Scanner aa = new Scanner(System.in);
        
        System.out.println("Enter a number");
        int num = aa.nextInt();
        int numofDigits = (int) Math.floor(Math.log10(num)+1);
        int d, S = 0, N1 = num;
        
        while(N1 > 0)
        {
            d = N1 % 10;
            S += Math.pow(d,numofDigits);
            N1 = N1 / 10;
        }
        
        if(S == num)
        {
            System.out.println("Armstrong");
        }
        else
        {
            System.out.println("Not Armstrong");
        }
    }
}