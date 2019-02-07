// Ryan W. Charles
// 18 Mar 2018
// Assignment 4

#ifndef _Students
#define _Students

#include <string>

using namespace std;

class Student {
public:
	Student(int startId = 0, const string& firstName = "", const string&
		lastName = "");
	Student(const Student& other);
	~Student();
	const bool HasCheckedOut(const string& equipementId);
	const int CheckedoutCount();
	bool CheckOut(const string& equipmentId);
	bool CheckIn(const string& equipmentId);

	int const GetID();
	const string GetFirstName();
	const string GetLastName();
	const string GetFullName();
	void SetFirstName(const string& first);
	void SetLastName(const string& last);
	void SetId(int id);

	void CreateList();
	void DestroyList();

	const bool operator==(const Student& rhs);
	const Student operator+(const string& newItem);
	void operator+=(const string& rhs);
	friend ostream& operator<<(ostream& out, const Student& item);
	friend istream& operator>>(istream& in, Student& item);

	void Clear();
private:
	unsigned int m_id;
	string m_firstName;
	string m_lastName;
	string* m_borrowedEquipmentList;
	unsigned int m_borrowedCount;
	unsigned int m_arraySize;

	bool resizeArray();
};

#endif
