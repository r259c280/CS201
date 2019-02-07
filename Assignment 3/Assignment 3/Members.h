// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#pragma once
#ifndef MEMBERS_H_
#define MEMBERS_H_
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Members
{
public:
	//Default constructor
	Members();
	/*Constructor with parameter Set the member variable: first_name, last_name, and id */
	Members(const string& firstName, const string& lastName, int idNum);
	/*Prints first name, last name, and the id for the calling object*/
	string printMember() const;
	/*Accepts an input file object and output file object to read and write members to file*/
	void readWriteMembers(ifstream& instream, ofstream& outstream);
	/*Getters and setters for the first name, last name, and id.*/
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	int getId() const;
	void setId(int id);
	const string& getLastName() const;
	void setLastName(const string& lastName);
private:
	string first_name;
	string last_name;
	int id;
};
#endif /* MEMBERS_H_ */