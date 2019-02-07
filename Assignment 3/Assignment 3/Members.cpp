// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#include <fstream>
#include "Members.h"
/*
* Default Constructor
* Set the member variable: first_name, last_name, and id to default values
*/
Members::Members() {
	setFirstName("");
	setLastName("");
	setId(0);
}
/*
* Constructor with parameter
* Set the member variable: first_name, last_name, and id
*/
Members::Members(const string& firstName, const string& lastName, int idNum) {
	setFirstName(firstName);
	setLastName(lastName);
	setId(idNum);
}
/*
* Prints and return first name, last name, and the id for the calling object
*/
string Members::printMember() const {
	stringstream ss;
	ss << "Id : " << getId() << ", First Name : " << getFirstName() << ", Last Name : " << getLastName();
	//cout << ss.str() << endl;
	return ss.str();
}
/*
* Accepts an input file object and output file object to read and write members to file
*/

void Members::readWriteMembers(ifstream& instream, ofstream& outstream) {
	string line;
	string fname, lname, noUse;
	int id;
	while (getline(instream, line))
	{
		istringstream iss(line);
		iss >> noUse;
		iss >> fname >> lname >> id;
		iss >> noUse;
		setFirstName(fname);
		setLastName(lname);
		setId(id);
		outstream << printMember() << endl;
	}
}
/*
* Getters and setters for the first name, last name, and id.
*/
const string& Members::getFirstName() const {
	return first_name;
}
void Members::setFirstName(const string& firstName) {

	first_name = firstName;
}
int Members::getId() const {
	return id;
}
void Members::setId(int id) {
	this->id = id;
}
const string& Members::getLastName() const {
	return last_name;
}
void Members::setLastName(const string& lastName) {
	last_name = lastName;
}