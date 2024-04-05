import java.util.Scanner;

public class Marcos2
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of students ");
        int length1 = sc.nextInt();

        int[] rollno = new int[length1];
        int[] sub1 = new int[length1];
        int[] sub2 = new int[length1];
        int[] sub3 = new int[length1];

        for (int i = 0; i < length1; i++) 
        {
            System.out.println("Enter the roll number ");
            rollno[i] = sc.nextInt();
           
            if (rollno[i] < 0 || rollno[i] > 100) 
            {
                 System.exit(0);
            }
        

            System.out.println("Enter sub1 ");
            sub1[i] = sc.nextInt();
            
            if (sub1[i] < 0 || sub1[i] > 100) 
            {
                 System.exit(0);
            } 

            System.out.println("Enter sub2 ");
            sub2[i] = sc.nextInt();
            
            if (sub2[i] < 0 || sub2[i] > 100) 
            {
                 System.exit(0);
            } 

            System.out.println("Enter sub3 ");
            sub3[i] = sc.nextInt();
            
            if (sub3[i] < 0 || sub3[i] > 100) 
            {
                 System.exit(0);
            } 

            System.out.println();
            System.out.println();
        }

        System.out.println("Total marks: ");
        int[] tm = new int[length1];
        for (int i = 0; i < length1; i++) 
        {
            tm[i] = (sub1[i] + sub2[i] + sub3[i]);
            System.out.println("Roll number " + rollno[i] + " :- " + tm[i]);
        }

        System.out.println("High marks: ");
        for (int i = 0; i < length1; i++) 
        {
            int a = 0;

            if (sub1[i] > sub2[i]) 
            {
                if (sub1[i] > sub3[i]) 
                {
                    a = sub1[i];
                } 
                else 
                {
                    a = sub3[i];
                }
            } 
            else 
            {
                if (sub2[i] > sub3[i]) 
                {
                    a = sub2[i];
                } 
                else 
                {
                    a = sub3[i];
                }
            }
            System.out.println("Roll number " + rollno[i] + " :- " + a);
        }
        
        int a = 0, b = tm[0];
        
        for (int i = 0; i < length1; i++) 
        {
            if(tm[i] > b)
            {
                b = tm[i];
                a = i;
            }
        }
        
        System.out.println("Highest is roll no " + rollno[a] + " with Marcos " + b);
    }
}