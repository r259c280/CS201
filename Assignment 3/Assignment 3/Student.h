// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include "Members.h"
class Student : public Members
{
private:
	string major;
public:
	//Default constructor
	Student();
	/*
	* Constructor with parameter
	* Set the member variable: first_name, last_name, and id of Members class
	* Set "major" member variable
	*/
	Student(const string& firstName, const string& lastName, int idNum, const string& stMajor);
	/*
	* Prints first name, last name, major and the id for the calling object
	*/
	string printMember() const;
	/*
	* Accepts an input file object and output file object to read and write members to file
	*/
	void readWriteMembers(ifstream& instream, ofstream& outstream);
	/*
	* Getters and setters for the major.
	*/
	const string& getMajor() const;
	void setMajor(const string& major);
};
#endif /* STUDENT_H_ */