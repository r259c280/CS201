// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#pragma once
#ifndef FACULTY_H_
#define FACULTY_H_
#include "Members.h"
class Faculty : public Members
{
private:
	double salary;
public:
	//Default constructor
	Faculty();
	/*
	* Constructor with parameter
	* Set the member variable: first_name, last_name, and id of Members class
	* Set salary member variable
	*/
	Faculty(const string& firstName, const string& lastName, int idNum, double salary);
	/*
	* Prints first name, last name, salary and the id for the calling object
	*/
	string printMember() const;
	/*
	* Accepts an input file object and output file object to read and write members to file
	*/
	void readWriteMembers(ifstream& instream, ofstream& outstream);
	/*
	* Getters and setters for the salary.
	*/
	double getSalary() const;
	void setSalary(double salary);
};
#endif /* FACULTY_H_ */