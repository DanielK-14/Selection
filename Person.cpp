#include "Person.h"

Person::Person(string i_ID, string i_FirstName, string i_LastName) 
	: m_ID{ i_ID }, m_FirstName{ i_FirstName }, m_LastName{ i_LastName } {
	if (!isValidID(i_ID)) throw Bad_ID;
	if (!isValidName(i_FirstName)) throw Bad_FirstName;
	if (!isValidName(i_LastName)) throw Bad_LastName;
} 

bool Person::isValidID(string i_ID) {

	bool result = true;

	if (i_ID.length() != 9) result = false;

	for (char ch : i_ID) {
		if (ch < '0' || ch > '9')
			result = false;
	}

	return result;
}

bool Person::isValidName(string i_Name) {

	return !i_Name.empty();
}