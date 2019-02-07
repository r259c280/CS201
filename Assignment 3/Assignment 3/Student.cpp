// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#include <fstream>
#include "Student.h"
/*
* Default Constructor
* Set the member variable: major to default values
*/
Student::Student() {
	setMajor("");
}
/*
* Constructor with parameter
* Call members constructor to set the member variable: first_name, last_name, and id
* set variable major
*/
Student::Student(const string& firstName, const string& lastName, int idNum, const string& stMajor) : Members(firstName, lastName, idNum) {
	setMajor(stMajor);
}
/*
* Prints and return first name, last name, Major and the id for the calling object
*/
string Student::printMember() const {
	stringstream ss;
	ss << "Student name is: " << getFirstName() << ' '<< getLastName() << " . ID is: " << getId() << " . Major is: " << getMajor();
	cout << ss.str() << endl;
	return ss.str();
	system("PAUSE");
}
/*
* Accepts an input file object and output file object to read and write Student to file
*/
void Student::readWriteMembers(ifstream& instream, ofstream& outstream) {
	string line;
	string fname, lname, start, major;
	int id;
	while (getline(instream, line))
	{
		istringstream iss(line);
		iss >> start;
		if (start.compare("s") == 0)
		{
			iss >> fname >> lname >> id >> major;
			setFirstName(fname);
			setLastName(lname);
			setId(id);
			setMajor(major);
			outstream << printMember() << endl;
		}
	}
}
/*
* Getters and setters for the Major.
*/
const string& Student::getMajor() const
{return major;}
void Student::setMajor(const string& major)
{this->major = major;}