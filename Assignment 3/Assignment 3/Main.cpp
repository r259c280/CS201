// Ryan W. Charles
// CS 201
// Assignment 3
// 27Feb2018
#include <iostream>
#include <fstream>
#include "Members.h"
#include "Faculty.h"
#include "Student.h"
using namespace std;
int main()
{
	Faculty f; //Object declaration of faculty class
	Student s; //Object declaration of student class
			   //Input file opening
	ifstream inFile("input.txt");
	if (!inFile.is_open())
	{
		cout << "Input file opening failed...Terminate program....";
		system("PAUSE");
		return -1;
	}
	//Output file opening for faculty
	ofstream outFileFaculty("FacultyOutput.txt");
	if (!outFileFaculty.is_open())
	{
		cout << "Output file for faculty opening failed...Terminate program....";
		system("PAUSE");
		return -1;
	}
	//Output file opening for student
	ofstream outFileStd("StudentOutput.txt");
	if (!outFileStd.is_open())
	{
		cout << "Output file for student opening failed...Terminate program....";
		system("PAUSE");
		return -1;
	}
	//Calling readWriteMembers function of faculty object
	f.readWriteMembers(inFile, outFileFaculty);
	//returning to the beginning of fstream
	inFile.clear();
	inFile.seekg(0, ios::beg);
	//Calling readWriteMembers function of student object
	s.readWriteMembers(inFile, outFileStd);
	//Close all opened files
	inFile.close();
	outFileFaculty.close();
	outFileStd.close();
	system("PAUSE");
	return 0;
}