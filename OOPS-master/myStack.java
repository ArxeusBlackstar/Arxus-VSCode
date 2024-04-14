// Enter the size of Stack 1: 2
// Enter the size of Stack 2: 3
//         Menu
// ------------------------------
// 1. Push to Stack 1
// 2. Pop from Stack 1
// 3. Push to Stack 2
// 4. Pop from Stack 2
// 5. Show Stack 1
// 6. Show Stack 2
// 7. Exit
// ------------------------------
// Enter your choice: 1
// Enter a value: 10
// 10 is pushed to Stack 1
// ------------------------------
// Enter your choice: 4
// STACK 2: Stack Underflow
// ------------------------------
// Enter your choice: 1
// Enter a value: 20
// 20 is pushed to Stack 1
// ------------------------------
// Enter your choice: 1
// Enter a value: 30
// STACK 1: Stack Overflow
// ------------------------------
// Enter your choice: 5
// The elements in Stack 1 are:
// 20
// 10
// ------------------------------
// Enter your choice: 3
// Enter a value: 5
// 5 is pushed to Stack 2
// ------------------------------
// Enter your choice: 3
// Enter a value: 10
// 10 is pushed to Stack 2
// The number of elements in both stacks are same.
// No. of elements in Stack 1: 2
// No. of elements in Stack 2: 2
// ------------------------------
// Enter your choice: 2
// 20 is popped from Stack 1
// ------------------------------
// Enter your choice: 6
// The elements in Stack 2 are:
// 10
// 5
// ------------------------------
// Enter your choice: 7

import java.util.Scanner;
public class myStack
{
	int[] array;
	int top, max, num;

	public myStack (int size, int stackNo)
	{
		array= new int[size];
		top= -1;
		max= size;
		num= stackNo;
	}

	public void push(int value)
	{
		if (top < max -1)	{
			array[++top]= value;
			System.out.println(value+ " is pushed to Stack "+ this.num);
		}
		else
			System.out.println("STACK " +this.num+ ": Stack Overflow");
	}

	public boolean isEmpty ()
	{
		return top==-1;
	}

	public void pop()
	{
		if (!isEmpty())
			System.out.println(array[top--]+ " is popped from Stack "+ this.num);
		else
			System.out.println("STACK " +this.num+ ": Stack Underflow");
	}

	public void checkSize(myStack otherStack)
	{
		if (this.top == otherStack.top)
		{
			System.out.println("The number of elements in both stacks are same.");
			System.out.println("No. of elements in Stack 1: "+ (this.top+1));
			System.out.println("No. of elements in Stack 2: "+ (otherStack.top+1));
		}
	}

	public void show()
	{
		System.out.println("The elements in Stack " +this.num+ " are:");
		for (int i=top; i>=0; i--)
			System.out.println(array[i]);
	}		

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter the size of Stack 1: ");
		int nA= sc.nextInt(), value;
		myStack stack1= new myStack(nA, 1);
		System.out.print("Enter the size of Stack 2: ");
		int nB= sc.nextInt();
		myStack stack2= new myStack(nB, 2);

		System.out.println("\tMenu\n------------------------------\n1. Push to Stack 1\n2. Pop from Stack 1\n3. Push to Stack 2\n4. Pop from Stack 2\n5. Show Stack 1\n6. Show Stack 2\n7. Exit");

		while (true)
		{
			System.out.print("------------------------------\nEnter your choice: ");
			int choice= sc.nextInt();
			switch (choice) {
				case 1:
					System.out.print("Enter a value: ");
					value= sc.nextInt();
					stack1.push(value);
					stack1.checkSize(stack2);
					break;
				case 2:
					stack1.pop();
					stack1.checkSize(stack2);
					break;
				case 3:
					System.out.print("Enter a value: ");
					value= sc.nextInt();
					stack2.push(value);
					stack1.checkSize(stack2);
					break;
				case 4:
					stack2.pop();
					stack1.checkSize(stack2);
					break;
				case 5:
					stack1.show();
					break;
				case 6:
					stack2.show();
					break;
				case 7:
					System.exit(0);
				default:
					System.out.println("Invalid Choice!");
			}
		}
	}
}