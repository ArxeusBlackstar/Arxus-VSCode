import org.shapes.*;
import io.*;
class Main
{
	public static void main(String[] args)
	{
		o.str("\tMENU\n------------------\n1 Square\n2 Triangle\n3 Circle \n4 Exit");
		while(true)
		{
			int n = i.in("\n------------------\nEnter your choice - ");
			switch (n)
			{
			case 1:
				double a = i.db("Enter the side of square - ");
				square s = new square(a);
				s.area();
				s.perimeter();
				break;
			case 2:
				double a1 = i.db("Enter the 1st side of triangle - ");
				double b1 = i.db("Enter the 2nd side of triangle - ");
				double c1 = i.db("Enter the 3rd side of triangle - ");
				triangle t = new triangle(a1 , b1 , c1);
				t.area();
				t.perimeter();
				break;
			case 3:
				double r = i.db("Enter the radius of circle - ");
				circle c = new circle(r);
				c.area();
				c.perimeter();
				break;
			case 4:
				System.exit(0);
			default:
				o.str("Invalid Choice!");
			}
		}
	}
}