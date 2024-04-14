// Enter the size of A : 5
// Enter the elements of A in ascending order:
// 1 2 4 3 5
// The elements are not in ascending order
// Enter the elements of A in ascending order:
// 1 2 3 4 5
// Enter the size of B : 4
// Enter the elements of B in ascending order:
// 4 5 7 8
// The elements in C are:
// 1 2 3 4 4 5 5 7 8

import java.util.Scanner;
public class MergeArray {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int A[]= input(sc, "A");
		int nA= A.length;
		int B[]= input(sc, "B");
		int nB= B.length;
		int C[]=new int[nA+nB], m=0, n=0, p=0;

		while (m < nA && n < nB)
			if (A[m] <= B[n])
				C[p++]=A[m++];
			else
				C[p++]=B[n++];

		while (m < nA)
			C[p++]=A[m++];
		while (n < nB)
			C[p++]=B[n++];

		System.out.println("The elements in C are:");
		for (int i=0; i<p; i++)
			System.out.print(C[i] + " ");
		System.out.println();
	}

	public static int[] input (Scanner sc, String arrayName)	{
		System.out.print("Enter the size of "+arrayName+" : ");
		int n= sc.nextInt(), k=0;
		int array[]= new int[n];
		do
		{
			System.out.println("Enter the elements of "+arrayName+" in ascending order:");
			k=0;
			array[0]= sc.nextInt();
			for (int i=1; i<n; i++) {
				array[i]= sc.nextInt();
				if (array[i] < array[i-1])	k=1;
			}
			if (k==1)
				System.out.println("The elements are not in ascending order");
		}
		while (k==1);
		return array;
	}
}