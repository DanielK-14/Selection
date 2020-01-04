#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Person.h"

using namespace std;

int main() {

	int numberOfPepoleToSort;

	cout << "This is a program to demonstrate different solutions to the selection problem and thiere time complexity.";
	cout << "\nIn this program you're requested to enter personal identifiers and they will be sorted using different"
		<< " algorithems.";
	cout << "\nBut first please enter the number of individuals that will be sorted: " << flush;
	cin >> numberOfPepoleToSort;

	vector<Person*> people;

	string id, firstName, lastName;
	int personlNumber = 1;

	do {

		system("cls");

		cout << "Please enter details for person number: " << personlNumber;
		cout << "\nPlease enter ID: ";
		cin >> id;
		cout << "\nPlease enter first name: ";
		cin >> firstName;
		cout << "\nPlease enter last name: ";
		cin >> lastName;
		
		try {
			people.push_back(new Person(id, firstName, lastName));
			personlNumber++;
		}

		catch (string ex) {

			char reply;
			bool isValidReply = false;

			cout << ex << endl;
			do {

				cout << "Re-enter or Quit? [r/q] ";
				cin >> reply;

				if (reply == 'q' || reply == 'r') isValidReply = true;

			} while (!isValidReply);

			if (reply == 'r') continue;

			break;
		}
	} while (personlNumber <= numberOfPepoleToSort);

	return 0;
}