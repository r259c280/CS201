// Ryan Charles
// Assignment 7
// 5/4/2018

#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// define maximum number of patients in a queue
#define MAXPATIENTS 100

// define structure for patient data
struct patient
{
	char FirstName[50];
	char LastName[50];
	char ID[20];
};

// define class for queue
class queue
{
public:
	queue(void);
	int AddPatientAtEnd(patient p);
	int AddPatientAtBeginning(patient p);
	patient GetNextPatient(void);
	int CancelPatient(patient * p);
	void OutputList(void);
	char DepartmentName[50];
private:
	int NumberOfPatients;
	patient List[MAXPATIENTS];
};

// declare member functions for queue

queue::queue()
{
// constructor
	NumberOfPatients = 0;
}

int queue::AddPatientAtEnd(patient p)
{
// adds a normal patient to the end of the queue. Returns 1 if successful, 0 if queue is full.
	if (NumberOfPatients >= MAXPATIENTS)
	{
// queue is full
		return 0;
	}
// put in new patient
	else
		List[NumberOfPatients] = p;  NumberOfPatients++;
	return 1;
}

int queue::AddPatientAtBeginning(patient p)
{
// adds a critically ill patient to the beginning of the queue. Returns 1 if successful, 0 if queue is full.
	int i;
	if (NumberOfPatients >= MAXPATIENTS)
	{
// queue is full
		return 0;
	}
// move all patients one position back in queue
	for (i = NumberOfPatients - 1; i >= 0; i--)
	{
		List[i + 1] = List[i];
	}
// put in new patient
	List[0] = p;  NumberOfPatients++;
	return 1;
}

patient queue::GetNextPatient(void)
{
// gets the patient that is first in the queue. Returns patient with no ID if queue is empty
	int i;  patient p;
	if (NumberOfPatients == 0) {
// queue is empty
		strcpy_s(p.ID, "");
		return p;
	}
// get first patient
	p = List[0];
// move all remaining patients one position forward in queue
	NumberOfPatients--;
	for (i = 0; i<NumberOfPatients; i++)
	{
		List[i] = List[i + 1];
	}
// return patient
	return p;
}

int queue::CancelPatient(patient * p)
{
// removes a patient from queue. Returns 1 if successful, 0 if patient not found
	int i, j, found = 0;
// search for patient
	for (i = 0; i<NumberOfPatients; i++)
	{
		if (_stricmp(List[i].ID, p->ID) == 0)
		{
// patient found in queue
			*p = List[i];  found = 1;
// move all following patients one position forward in queue
			NumberOfPatients--;
			for (j = i; j<NumberOfPatients; j++)
			{
				List[j] = List[j + 1];
			}
		}
	}
	return found;
}

void queue::OutputList(void)
{
// lists entire queue on screen
	int i;
	if (NumberOfPatients == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{

		for (i = 0; i<NumberOfPatients; i++)
		{

			cout << " " << List[i].FirstName;
			cout << " " << List[i].LastName;
			cout << " " << List[i].ID;
		}
	}
}
// declare functions used by main:

patient InputPatient(void)
{
	// this function asks user for patient data.
	patient p;
	cout << " " << endl;
	cout << "Please enter data for new patient" << endl;
	cout << " " << endl;
	cout << "First name : ";
	cin.getline(p.FirstName, sizeof(p.FirstName));
	cout << "Last name : ";
	cin.getline(p.LastName, sizeof(p.LastName));
	cout << "Social security number : ";
	cin.getline(p.ID, sizeof(p.ID));
	// check if data valid
	if (p.FirstName[0] == 0 || p.LastName[0] == 0 || p.ID[0] == 0)
	{
		// rejected
		strcpy_s(p.ID, "");
		cout << "Error: Data not valid. Operation cancelled." << endl;
		_getch();
	}
	return p;
}

void OutputPatient(patient * p)
{
// this function outputs patient data to the screen
	if (p == NULL || p->ID[0] == 0)
	{
		cout << "No patient" << endl;
		return;
	}
	else
	cout << "Patient data : " << endl;
	cout << "First name : " << p->FirstName << endl;
	cout << "Last name : " << p->LastName << endl;
	cout << "Social security number : " << p->ID << endl;
}

int ReadNumber()
{
// this function reads an integer number from the keyboard.
	char buffer[20];
	cin.getline(buffer, sizeof(buffer));
	return atoi(buffer);
}

void DepartmentMenu(queue * q)
{
// this function defines the user interface with menu for one department
		int choice = 0, success;  patient p;
	while (choice != 6)
	{
// clear screen
		system("CLS");
// print menu
		cout << "Welcome to department : " << q->DepartmentName << endl;
		cout << "1 : Add patient" << endl;
		cout << "2 : Add critically ill patient" << endl;
		cout << "3 : Take out patient for operation" << endl;
		cout << "4 : Cancel Patient" << endl;
		cout << "5 : List the queue of patients" << endl;
		cout << "6 : Change department or exit" << endl;
		cout << "Please enter your choice : ";
// get user choice
		choice = ReadNumber();
// do indicated action
		switch (choice)
		{
// Add normal patient
		case 1:   
			p = InputPatient();
			if (p.ID[0])
			{
				success = q->AddPatientAtEnd(p);
				system("CLS");
				if (success)
				{
					cout << "Patient added:" << endl;

				}
				else
				{
// error
					cout << "Error: The queue is full.Cannot add patient : ";
				}
				OutputPatient(&p);
				cout << "Press any key";
				_getch();
			}
			break;

// Add critically ill patient
		case 2:   
			p = InputPatient();
			if (p.ID[0])
			{
				success = q->AddPatientAtBeginning(p);
				system("CLS");
				if (success)
				{
					cout << "Patient added :";
				}
				else
				{
// error
					cout << "Error: The queue is full.Cannot add patient : ";
				}

				OutputPatient(&p);
				cout << "Press any key";
				_getch();
			}
			break;

// Take out patient for operation
		case 3:   
			p = q->GetNextPatient();
			system("CLS");
			if (p.ID[0])
			{
				cout << "Patient to operate :";
				OutputPatient(&p);
			}
			else
			{
				cout << "There is no patient to operate." << endl;
			}
			cout << "Press any key" << endl;
			_getch();
			break;

// Remove patient 
		case 4:   
			p = InputPatient();
			if (p.ID[0])
			{
				success = q->CancelPatient(&p);
				system("CLS");
				if (success)
				{
					cout << "Patient removed :";
				}
				else
				{
// error
					cout << "Error: Cannot find patient :" << endl;
				}
				OutputPatient(&p);
				cout << "Press any key" << endl;
				_getch();
			}
			break;

//List queue
		case 5:   
			system("CLS");
			q->OutputList();
			cout << " " << endl;
			cout << "Press any key" << endl;
			_getch();  break;
		}
	}
}

// main function defining queues and main menu
int main()
{
	int i, MenuChoice = 0;
// define three queues
	queue departments[3];
// set department names
	strcpy_s(departments[0].DepartmentName, "Heart clinic");
	strcpy_s(departments[1].DepartmentName, "Lung clinic");
	strcpy_s(departments[2].DepartmentName, "Plastic surgery");

	while (MenuChoice != 4)
	{
		// clear screen
		system("CLS");
		// print menu
		{
		cout << setw(53) << "Welcome to Starling City Hospital" << endl;
	}
			for (i = 0; i < 3; i++)
			{
// write menu item for department i
				cout << " " << (i + 1) << ":  " << departments[i].DepartmentName << endl;
			}
			cout << " 4:  Exit" << endl;
			cout << " Please enter your choice : " << endl;
// get user choice
			MenuChoice = ReadNumber();
		if (MenuChoice >= 1 && MenuChoice <= 3)
		{
//submenu for department
			DepartmentMenu(departments + (MenuChoice - 1));
		}
	}
}