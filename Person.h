#pragma once
#include <stdlib.h>
#include <string>
#include <cstdlib>

using namespace std;

class Person {
private:
	long m_ID;
	string m_FirstName;
	string m_LastName;

	const string Bad_ID = "Bad ID";
	const string Bad_FirstName = "Bad first name";
	const string Bad_LastName = "Bad last name";

public:
	Person(string i_ID, string i_FirstName, string i_LastName);
	Person() = default;
	long ID() { return m_ID; }
	string FirstName() { return m_FirstName; }
	string LastName() { return m_LastName; }
    bool operator<(const Person& other) const;
    bool operator>(const Person& other) const;
    const Person& operator=(const Person& other);

private:
	bool isValidID(string i_ID);
	bool isValidName(string i_name);
};
