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

int showMenu() {
	cout << " " << endl;
	cout << "1. print all Customers data" << endl;
	cout << "2. print names and IDs" << endl;
	cout << "3. print acconts total" << endl;
	cout << "4. Enter q/Q to quit" << endl;
	cout << "\n Enter your choice, or 'q' to quit: ";
	char choice;
	cin >> choice;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error: Please enter a number " << endl;
		cin >> choice;
	}
	return choice;
}

int main() {

	int id[MAX_ROW]; string first[MAX_ROW];
	string last[MAX_ROW];
	double savings_Account[MAX_ROW]; double checking_Account[MAX_ROW];
	int size = MAX_ROW;

	string input_file = "input.txt";
	ifstream ifsInputFile(input_file.c_str());
	string strLine;
	if (ifsInputFile.fail())
	{
		cout << "Error reading file " << input_file << endl;
		system("pause");
		return(1);
	}
	if (ifsInputFile.is_open()) {
		int account_index = 0;
		while (getline(ifsInputFile, strLine)) {
			// Use std::stringstream to isolate words using operator >>
			stringstream ssWordsBuf(strLine);
			ssWordsBuf >> id[account_index] >> first[account_index] >> last[account_index] >> savings_Account[account_index] >> checking_Account[account_index];
			account_index++;
		}
		ifsInputFile.close();
	}


	char choice;
	do {
		choice = showMenu();
		switch (choice) {
		case '1':
		{
			printCustomersData(id, first, last, savings_Account, checking_Account, size);
			break;
		}
		case '2':
		{
			printNames(id, first, last, size);
			break;
		}
		case '3':
		{
			printTotal(id, savings_Account, checking_Account, size);
			break;
		}
		case 'q':
		{
		}
		case 'Q':
		{
			cout << " " << endl;
			cout << "Thanks for using my program. Goodbye!!" << endl;
			cout << " " << endl;
			system("PAUSE");
			break;
		}
		default:
			while (choice != '1' || choice != '2' || choice != '3' || choice != 'q' || choice != 'Q')
			{
				cout << "" << endl;
				cout << "Wrong input. Try again..." << endl;
				cin >> choice;
			}
			break;


		}while (choice != 'q' && choice != 'Q');
			return(0);
		}