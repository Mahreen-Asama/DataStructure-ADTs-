#include "Student.h"

ostream& operator <<(ostream& out, const Student& s)	//friend function
{
	out << s.name << "," << s.rollNumber << "," << s.cgpa;
	return out;
}
					//Methods........
Student::Student()
{
	name = {};
	cgpa = rollNumber = 0;
}
Student::Student(string n, double cgpa, int roll)	//parametized constructor
{
	this->name = n;
	this->cgpa = cgpa;
	this->rollNumber = roll;
}
Student::Student(const Student& obj)				//copy constructor
{
	this->name = obj.name;
	this->cgpa = obj.cgpa;
	this->rollNumber = obj.rollNumber;
}
Student& Student::operator=(const Student& obj)		//assignment operator overloaded
{
	//cout << "\nstudent assignment operator\n";
	this->name = obj.name;
	this->cgpa = obj.cgpa;
	this->rollNumber = obj.rollNumber;
	return *this;
}
