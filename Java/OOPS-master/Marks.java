// Enter the number of students:3
// Enter Roll No : -1
// Enter Roll No : 1
// Enter Marks in Subject 1 for Roll 1 : 101
// Enter Marks in Subject 1 for Roll 1 : 100
// Enter Marks in Subject 2 for Roll 1 : 50
// Enter Marks in Subject 3 for Roll 1 : 40
// Enter Roll No : 1
// ERROR: Roll No. 1 already present.
// Enter Roll No : 2
// Enter Marks in Subject 1 for Roll 2 : 50
// Enter Marks in Subject 2 for Roll 2 : 60
// Enter Marks in Subject 3 for Roll 2 : 70
// Enter Roll No : 5
// Enter Marks in Subject 1 for Roll 5 : -10
// Enter Marks in Subject 1 for Roll 5 : 20
// Enter Marks in Subject 2 for Roll 5 : 80
// Enter Marks in Subject 3 for Roll 5 : 80

// --TOTAL MARKS--
// Roll No : 1
// Total   : 190


// Roll No : 2
// Total   : 180


// Roll No : 5
// Total   : 180


// --SUBJECT 1--
// Roll No : 1
// Marks : 100


// --SUBJECT 2--
// Roll No : 5
// Marks : 80


// --SUBJECT 3--
// Roll No : 5
// Marks : 80


// --HIGHEST TOTAL MARKS--
// Roll No : 1
// Marks : 190

import java.util.Scanner;
public class Marks	{
	public static void main (String args[])	{
		Scanner sc= new Scanner (System.in);
		
		System.out.print("Enter the number of students:");
		int n= sc.nextInt(), k;
		int data[][]= new int [5][n];

		for (int i=0; i<n; i++)
		{
			do
			{
				k=0;
				System.out.print("Enter Roll No : ");
				data[0][i]= sc.nextInt();
				for (int j=0; j<i; j++)
					if (data[0][j] == data[0][i])
					{
						System.out.println("ERROR: Roll No. "+data[0][i]+" already present.");
						k=1;
					}
			}
			while (data[0][i]<1 || k==1);

			data[1][i]= inputMarks(sc, data[0][i], 1);
			data[2][i]= inputMarks(sc, data[0][i], 2);
			data[3][i]= inputMarks(sc, data[0][i], 3);
			data[4][i]= data[1][i] + data[2][i] + data[3][i];
		}

		System.out.println("\n--TOTAL MARKS--");
		for (int i=0; i<n; i++)	{
			System.out.println("Roll No : "+data[0][i]);
			System.out.println("Total   : "+data[4][i]+"\n\n");
		}
		maxMarks(data[1], data[0], n, "SUBJECT 1");
		maxMarks(data[2], data[0], n, "SUBJECT 2");
		maxMarks(data[3], data[0], n, "SUBJECT 3");
		maxMarks(data[4], data[0], n, "HIGHEST TOTAL MARKS");
		
	}

	public static void maxMarks (int marks[], int roll[],int n, String heading)	{
		int max=marks[0], maxRoll=roll[0];
		for (int i=1; i<n; i++)
			if (marks[i]>max)
			{
				max= marks[i];
				maxRoll= roll[i];
			}
		System.out.println("--" +heading+ "--");
		System.out.println("Roll No : "+maxRoll);
		System.out.println("Marks : "+max+"\n\n");
	}

	public static int inputMarks (Scanner sc, int roll, int subNo)	{
		int marks;
		do
		{
			System.out.print("Enter Marks in Subject "+subNo+" for Roll "+ roll+" : ");
			marks= sc.nextInt();
		}
		while (marks<0 || marks>100);
		return marks;
	}
}