#include "Students.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Open files for input/output
	ifstream Students;
	ifstream checkouts;
	ifstream checkins;
	ofstream Studentsout;

	Students.open("students.txt");
	checkouts.open("checkOUT.txt");
	checkins.open("checkIN.txt");
	Studentsout.open("Updated_Students.txt");


	int studentcount;
	string ignore;
	Students >> ignore >> studentcount;

	// Initalize Array to size of number of Students
	Student *studentArray = new Student[studentcount];

	// Store each entry in Students.txt into Students objects
	for (int i = 0; i < studentcount; i++) {
		Students >> studentArray[i];
	}

	// Read through checkouts and checkout equipment to person's ID
	checkouts >> ignore >> ignore;
	int id;
	string equipment;
	while (checkouts.eof() != true) {
		checkouts >> id >> equipment;
		for (int i = 0; i < studentcount; i++)/* {
			if (id == studentArray[i].GetID()) /*{
				try {
					studentArray[i] += equipment;
				}
				catch (StudentsException e) {
					cout << "Error checking out " << equipment << ": " << e.What() << endl;
				}
			}
		}
	}*/

	// Checkin equipment to the people who checked them out
			checkins >> ignore;
		while (checkins.eof() != true) {
			checkins >> equipment;
			for (int i = 0; i < studentcount; i++)/* {
				if (studentArray[i].HasCheckedOut(equipment)) {
					try {
						studentArray[i].CheckIn(equipment);
					}
					catch (StudentsException e) {
						cout << "Error checking out " << equipment << ": " << e.What() << endl;

					}
				}
			}*/

			// Output the current Students with their checked out equipment
				Studentsout << "STUDENT_COUNT " << studentcount << endl;
			Studentsout << endl;
			for (int i = 0; i < studentcount; i++) {
				Studentsout << studentArray[i];
			}

			// Close files
			Students.close();
			checkouts.close();
			checkins.close();
			Studentsout.close();
		}
		return 0;
	}

}