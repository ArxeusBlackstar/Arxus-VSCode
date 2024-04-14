package org.shapes;
public class circle
{
	double r;
	public circle(double r)
	{
		this.r = r;
	}		
	public void area()
	{
		double area = 3.14*r*r;
		System.out.println("Area of Circle : " + area);
	}
	
	public void perimeter()
	{
		double peri = 2*3.14*r;
		System.out.println("Perimeter of Circle : " + peri);
	}	
}