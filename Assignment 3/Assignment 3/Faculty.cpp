// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#include <fstream>
#include "Faculty.h"
/*
* Default Constructor
* Set the member variable: salary to default values
*/
Faculty::Faculty() {
	setSalary(0);
}
/*
* Constructor with parameter
* Call members constructor to set the member variable: first_name, last_name, and id
* set variable salary
*/
Faculty::Faculty(const string& firstName, const string& lastName, int idNum, double salary) : Members(firstName, lastName, idNum) {
	setSalary(salary);
}
/*
* Prints and return first name, last name, Salary and the id for the calling object
*/
string Faculty::printMember() const {
	stringstream ss;
	ss << "Faculty name is: " << getFirstName()<< ' ' << getLastName() <<" . ID is: " << getId() << " . Salary is: " << getSalary();
	cout << ss.str() << endl;
	return ss.str();
}
/*
* Accepts an input file object and output file object to read and write Faculty to file
*/
void Faculty::readWriteMembers(ifstream& instream, ofstream& outstream) {
	string line;
	string fname, lname, start;
	int id;
	double salary;
	while (getline(instream, line))
	{
		istringstream iss(line);
		iss >> start;
		if (start.compare("f") == 0)
		{
			iss >> fname >> lname >> id >> salary;
			setFirstName(fname);
			setLastName(lname);
			setId(id);
			setSalary(salary);
			outstream << printMember() << endl;
		}
	}
}
/*
* Getters and setters for the Salary.
*/
double Faculty::getSalary() const
{
	return salary;
}
void Faculty::setSalary(double salary)
{
	this->salary = salary;
}