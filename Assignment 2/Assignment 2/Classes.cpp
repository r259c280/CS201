// Ryan W. Charles
// Assignment #2
// 13 Feb 2018

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Header.h"

void printCustomersData(const int id[], const string first[], const string last[], const double savings_Account[], const double checking_Account[], int size)
{
	cout << left << setw(10) << setfill(' ')<< "ID" << setw(10) << setfill(' ') << "First" << setw(11) << setfill(' ') << "Last" << setw(20) 
		<< setfill(' ')<< "Savings Account" << setw(20) << setfill(' ')<< "Checking Account" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << id[i] << setw(10) << first[i] << setw(15) << last[i]
			<< setw(20) << savings_Account[i] << setw(25) << checking_Account[i] << endl;

	}

}

void printNames(const int id[], const string first[], const string last[], int size) {
	cout << setw(0) << setfill(' ') << setw(10) << setfill(' ') <<"ID" << setw(20) << setfill(' ') << "First" << setw(10) << setfill(' ') << "Last" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << id[i] << setw(20) << first[i] << setw(10) << last[i] << endl;
	}

}


void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size) {

	cout << left << setw(5) << setfill(' ') << "ID" << setw(20) << setfill(' ') << "Savings Account" << setw(30) << setfill(' ') << "Checking Account" 
		<< setw(5) << setfill(' ') << "Total" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << setfill(' ') << id[i] << setw(20) << setfill(' ') << savings_Account[i] << setw(25) << setfill(' ') << checking_Account[i]
			<< setw(5) << setfill(' ') << (savings_Account[i] + checking_Account[i]) << endl;
	}
}