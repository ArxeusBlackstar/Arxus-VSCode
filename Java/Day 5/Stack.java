import java.util.Scanner;

public class Stack 
{
	private int maxSize;
	private int top;
	private int[] stackArray;
	int y1 = 0, y2 = 1;

    	
	public Stack(int size) 
	{
		maxSize = size;
        	stackArray = new int[maxSize];
        	top = -1;
	}

	public void push(int value) 
	{
        	if(top == (maxSize - 1))
		{
			System.out.println("Stack Full");
		}
		else
		{
			stackArray[++top] = value;
		}
	}

	public int pop()
	{
		if(top >= 0)
		{
			return stackArray[top--];
		}
		else
		{
			System.out.println("Stack underflow");
			return -1;
		}
	}

	public boolean isEmpty()
	{
		if(top == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	public int size()
	{
		return (top + 1);
	}
	



	public static void main(String[] args) 
	{
        	Scanner scanner = new Scanner(System.in);

        	System.out.print("Enter the size of the stack 1: ");
        	int size1 = scanner.nextInt();
		
		Stack stack1 = new Stack(size1);

		System.out.print("Enter the size of the stack 2: ");
        	int size2 = scanner.nextInt();
		Stack stack2 = new Stack(size2);
		
		while (true) 
		{			
            		System.out.println("\nMenu:");
            		System.out.println("1. Push to Stack 1");
            		System.out.println("2. Pop from Stack 1");
            		System.out.println("3. Check if Stack 1 is empty");
           			System.out.println("4. Push to Stack 2");
            		System.out.println("5. Pop from Stack 2");
            		System.out.println("6. Check if Stack 2 is empty");
            		System.out.println("7. Display number of elements in each stack and exit");

            		System.out.print("Enter your choice: ");
            		int choice = scanner.nextInt();
			
			switch (choice)
			{
                			case 1:
                    			System.out.print("Enter element to push onto Stack 1: ");
                    			int element1 = scanner.nextInt();
                    			stack1.push(element1);
                    			break;

					case 2:
					int poppedElement1 = stack1.pop();
                    			if (poppedElement1 != -1) 
					{
                        			System.out.println("Popped element from Stack 1: " + poppedElement1);
                    			}
                    			break;
					
					case 3:
                    			System.out.println("Stack 1 is" + (stack1.isEmpty() ? " not " : "") + " empty.");
                    			break;

					case 4:
                    			System.out.print("Enter element to push onto Stack 2: ");
                    			int element2 = scanner.nextInt();
                    			stack2.push(element2);
                    			break;

					case 5:
					int poppedElement2 = stack2.pop();
                    			if (poppedElement2 != -1) 
					{
                        			System.out.println("Popped element from Stack 2: " + poppedElement2);
                    			}
                    			break;
					
					case 6:
                    			System.out.println("Stack 2 is" + (stack2.isEmpty() ? " not" : "") + " empty.");
                    			break;

					case 7:
                    			System.out.println("Number of elements in Stack 1: " + stack1.size());
                    			System.out.println("Number of elements in Stack 2: " + stack2.size());
                    			if (stack1.size() == stack2.size()) 
					{
                        			System.out.println("Number of elements in both stacks is equal.");
                    			}
                    			System.exit(0);

                			default:
                    			System.out.println("Invalid choice. Please enter a valid option.");
				
			}
			if(stack1.size() == stack2.size())
			{
				System.out.println("Number of elements in both stacks is equal.");
				System.out.println("Number of elements in Stack 1: " + stack1.size());
                    		System.out.println("Number of elements in Stack 2: " + stack2.size());
			}
		}
	}
}

		