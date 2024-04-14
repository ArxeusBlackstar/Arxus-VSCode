package org.shapes;
public class triangle
{
	double a;
	double b;
	double c;
	public triangle(double a , double b , double c)
	{
		this.a = a;
		this.b = b;
		this.c = c;
	}

	public void area()
	{
		double s = (a+b+c)/2;
		double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
		System.out.println("Area of Triangle : " + area);
	}
	
	public void perimeter()
	{
		double peri = a+b+c;
		System.out.println("Perimeter of Triangle : " + peri);
	}	
}