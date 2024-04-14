// MENU
// --------------------
// 1. Admit new Student
// 2. Migrate a Student
// 3. Display
// 4. Exit
// --------------------
// Enter Your Choice : 1
// Enter Student name : Pritam
// Enter Registration Number : 2160006
// Enter Elective Subject : Cloud Computing
// Enter Hostel Name : Modern Boys Hostel
// Enter No of room : 8
// Enter Hostel Location : Anandapur
// Enter Department Name : CSBS
// Enter Department Head : JDH
// Enter Avg Marks : 74
// --------------------
// Enter Your Choice : 2
// Enter Registration no :
// 2160006
// Enter new Department Name : ME
// Enter new Department Head : SBM
// --------------------
// Enter Your Choice : 3
// Enter Registration no :
// 2160006
// Student name : Pritam
// Student Registration No : 2160006
// Elective Subject : Cloud Computing
// Average Marks : 74
// Department Name : ME
// Department Head : SBM
// Name Of the Hostel : Modern Boys Hostel
// Hostel Location:Anandapur
// Total Room: 8
// --------------------
// Enter Your Choice : 4

import java.util.*;
interface Department	{
	public void getDetpName();
	public void getDetpHead();
}

class Hostel
{	
	protected String hostelName, hostelLocation;
	int noOfRooms;
	void getHostelName() {
		System.out.println("Name Of the Hostel : " + hostelName);
	}
	void getHostelLocation() {
		System.out.println("Hostel Location:" + hostelLocation);
	}
	void getnoOfRooms() {
		System.out.println("Total Room: " + noOfRooms);
	}
}
	
class Student extends Hostel implements Department 
{
	Scanner sc= new Scanner(System.in);
	String sName, regno,elecSubj;
	String deptName, deptHead;
	int avgMarks;
	void getStudentName() {
		System.out.println("Student name : " + sName);
	}
	String getStudentRegNo() {
		return regno;
	}
	void getElectiveSubject() {
		System.out.println("Elective Subject : " + elecSubj);
	}
	void getAvgMarks() {
		System.out.println("Average Marks : " + avgMarks);
	}
	public void getDetpName() {
		System.out.println("Department Name : " + deptName);
	}
	public void getDetpHead() {
		System.out.println("Department Head : " + deptHead);
	}
	void addStudent()	{
		System.out.print("Enter Student name : ");
		sName=sc.nextLine();
		System.out.print("Enter Registration Number : ");
		regno=sc.nextLine();
		System.out.print("Enter Elective Subject : ");
		elecSubj=sc.nextLine();
		System.out.print("Enter Hostel Name : ");
		hostelName=sc.nextLine();
		System.out.print("Enter No of room : ");
		noOfRooms=sc.nextInt();
		sc.nextLine();
		System.out.print("Enter Hostel Location : ");
		hostelLocation=sc.nextLine();
		System.out.print("Enter Department Name : ");
		deptName=sc.nextLine();
		System.out.print("Enter Department Head : ");
		deptHead=sc.nextLine();
		System.out.print("Enter Avg Marks : ");
		avgMarks=sc.nextInt();
		sc.nextLine();
	}
	void migrate()	{
		System.out.print("Enter new Department Name : ");
		deptName=sc.nextLine();
		System.out.print("Enter new Department Head : ");
		deptHead=sc.nextLine();
	}
	void display(){
		getStudentName();
		System.out.println("Student Registration No : " + getStudentRegNo());
		getElectiveSubject();
		getAvgMarks();
		getDetpName();
		getDetpHead();
		getHostelName();
		getHostelLocation();
		getnoOfRooms();
		
	}
}

class StudentManagement
{
	public static void main(String []args)	{
		Scanner sc= new Scanner(System.in);
		Student[] st=new Student[100];
		int noOfStudents=0;
		System.out.println("\tMENU\n--------------------\n1. Admit new Student\n2. Migrate a Student\n3. Display\n4. Exit");
		while(true)	{
			System.out.print("--------------------\nEnter Your Choice : ");
			int ch=sc.nextInt();
			sc.nextLine();
			switch(ch)	{
				case 1:
					st[noOfStudents]=new Student();
					st[noOfStudents++].addStudent();
					break;
				case 2:
					System.out.println("Enter Registration no : ");
					String rno=sc.nextLine();
					boolean b=false;
					for(int i=0;i<noOfStudents;i++)
					{
						String x=st[i].getStudentRegNo();
						if(x.equals(rno))
						{
							st[i].migrate();
							b=true;
							break;
						}
					}
					if(b==false)
						System.out.println("Student Not Found");
					break;
				case 3:
					System.out.println("Enter Registration no : ");
					String rno1=sc.nextLine();
					boolean bx=false;
					for(int i=0;i<noOfStudents;i++){
						if(st[i].getStudentRegNo().equals(rno1)){
							bx=true;
							st[i].display();
							break;
						}
					}
					if(bx==false)
						System.out.println("Student Not Found");
					break;
				case 4:
					System.exit(0);
				default:
					System.out.println("Invalid Input!");
			}
		}
	}
}