#include "Students.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor for normal student object
Student::Student(int startId, const string& firstName, const string&
	lastName) {
	m_id = startId;
	m_firstName = firstName;
	m_lastName = lastName;
	m_borrowedEquipmentList = NULL;
	m_borrowedCount = 0;
	m_arraySize = 0;
}

// Constructor for copying other student objects
Student::Student(const Student& other) {
	*this = other;
}

Student::~Student() {
	if (m_borrowedEquipmentList != NULL) {
		delete[] m_borrowedEquipmentList;
		m_borrowedEquipmentList = NULL;
	}
}

// determine whether student has checkedout equipment
const bool Student::HasCheckedOut(const string& equipmentId) {
	for (int i = 0; i < m_borrowedCount; i++) {
		if (equipmentId == m_borrowedEquipmentList[i]) {
			return true;
		}
	}
	return false;
}

// How many equipment student has checked out
const int Student::CheckedoutCount() {
	return m_borrowedCount;
}

// Checkout out equipment to student
bool Student::CheckOut(const string& equipmentId) {
	bool checkedout;
	string equipment = equipmentId;
	checkedout = HasCheckedOut(equipmentId);
	if (checkedout) {
		return false;
	}

	if (m_borrowedEquipmentList == NULL) {
		CreateList();
	}

	if (m_borrowedCount == m_arraySize) {
		bool resize = resizeArray();
		if (!resize) {
			return false;
		}
	}

	m_borrowedEquipmentList[m_borrowedCount] = equipment;
	m_borrowedCount++;
}

// Check in equipment to student
bool Student::CheckIn(const string& equipmentId) {
	bool checkedout;
	checkedout = HasCheckedOut(equipmentId);

	/*if (!checkedout) {
		StudentsException e("Checking in an item that has not been checked out!");
		throw e;
	}*/

	for (int i = 0; i < m_borrowedCount; i++) {
		if (equipmentId == m_borrowedEquipmentList[i]) {
			m_borrowedEquipmentList[i] = m_borrowedEquipmentList[m_borrowedCount - 1];
			m_borrowedEquipmentList[m_borrowedCount - 1] = "";
			m_borrowedCount--;
			if (m_borrowedCount == 0) {
				DestroyList();
			}
		}
	}
	return true;
}

int const Student::GetID() {
	return m_id;
}
string const Student::GetFirstName() {
	return m_firstName;
}
string const Student::GetLastName() {
	return m_lastName;
}
string const Student::GetFullName() {
	string full = m_firstName + " " + m_lastName;
	return full;

}
void Student::SetFirstName(const string& first) {
	m_firstName = first;
}
void Student::SetLastName(const string& last) {
	m_lastName = last;
}
void Student::SetId(int id) {
	m_id = id;
}

// Check equality of student objects
bool const Student::operator==(const Student& rhs) {
	Student tmprhs;
	tmprhs = rhs;
	if (this->GetFullName() == tmprhs.GetFullName()) {
		return true;
	}
	else {
		return false;
	}
}

// return result of Adding a equipment to a student's checkedout list
const Student Student::operator+(const string& newItem) {
	Student result;
	result = *this;
	result.CheckOut(newItem);
	return result;
}

// add equipment to students's checked out list
void Student::operator+=(const string& rhs) {
	this->CheckOut(rhs);
}

// Output information on student and their checkouts
ostream& operator<<(ostream& out, const Student& item) {
	Student usr(item);
	out << "Student " << usr.m_id << endl;
	out << "\t " << "NAME " << usr.GetFullName() << endl;
	out << "\t " << "EQUIPMENT_COUNT " << usr.m_borrowedCount << endl;
	for (int i = 0; i < usr.m_borrowedCount; i++) {
		out << "\t\t " << usr.m_borrowedEquipmentList[i] << endl;
	}
	out << "END" << endl;
	out << endl;
	return out;
}

// Input info needed for student and their checkouts
istream& operator>>(istream& in, Student& item) {
	string ignr;
	int equipmentcount;
	string equipmentname;

	in >> ignr >> item.m_id;
	in >> ignr >> item.m_firstName >> item.m_lastName;
	in >> ignr >> equipmentcount;

	for (int i = 0; i < equipmentcount; i++) {
		in >> equipmentname;
		/*try {
			item += equipmentname;
		}
		catch (StudentsException e) {
			cerr << "Error checking the equipment " << equipmentname << ": " << e.What() << endl;
		}*/
	}
	in >> ignr;
	return in;
}

// Clear a student contact
void Student::Clear() {
	m_id = 0;
	m_firstName = "";
	m_lastName = "";
	m_borrowedCount = 0;
	m_arraySize = 0;
	if (m_borrowedEquipmentList != NULL) {
		delete[] m_borrowedEquipmentList;
		m_borrowedEquipmentList = NULL;
	}
}

// Make checkouts array larger
bool Student::resizeArray() {
	/*try*/ {
		string* tmpArray = new string[m_arraySize * 2];
		for (int i = 0; i < m_arraySize; i++) {
			tmpArray[i] = m_borrowedEquipmentList[i];
		}
		delete[] m_borrowedEquipmentList;
		m_borrowedEquipmentList = tmpArray;
		tmpArray = NULL;
		m_arraySize = m_arraySize * 2;
		return true;
	}
	// if you can't allocate memory correctly
	/*catch (exception)*/ {
		//return false;
	}

}

// Create an array to store equipment checkouts
void Student::CreateList() {
	/*try*/ {
		m_borrowedEquipmentList = new string[5];
		m_borrowedCount = 0;
		m_arraySize = 5;
	}
	/*catch (exception)*/ {
		DestroyList();
		/*throw StudentsException("Can't get memory.");*/
	}
}

// Destory the equipment checkout array
void Student::DestroyList() {
	delete[] m_borrowedEquipmentList;
	m_borrowedEquipmentList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}