package org.shapes;
public class square
{
	double a;
	public square(double a)
	{
		this.a = a;
	}

	public void area()
	{
		double area = a*a;
		System.out.println("Area of Square : " + area);
	}
	
	public void perimeter()
	{
		double peri = 4*a;
		System.out.println("Perimeter of Square : " + peri);
	}	
}