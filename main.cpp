#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Person.h"
#include "Heap.h"

using namespace std;

const Person& selectHeap(Person arr[],int size,int k,int& NumComp);

int main()
{
    Person p[10];

    Person p1("100000000","Dan","Kalmykov");
    Person p2("200000000","a","b");
    Person p3("300000000","a","b");
    Person p4("400000000","a","b");
    Person p5("500000000","a","b");
    Person p6("600000000","a","b");
    Person p7("700000000","a","b");
    Person p8("800000000","a","b");
    Person p9("900000000","a","b");
    Person p10("910000000","a","b");

    p[0] = p9;
    p[1] = p8;
    p[2] = p10;
    p[3] = p7;
    p[4] = p6;
    p[5] = p2;
    p[6] = p1;
    p[7] = p3;
    p[8] = p4;
    p[9] = p5;

    int num = 0;
    Person res = selectHeap(p,(sizeof(p)/ sizeof(Person)),5,num);

    cout << "The person ID is: " << res.ID() << endl;
    cout << "Num of compares: " << num << endl;
//	int numberOfPepoleToSort;
//
//	cout << "This is a program to demonstrate different solutions to the selection problem and their time complexity.";
//	cout << "\nIn this program you're requested to enter personal identifiers and they will be sorted using different"
//		<< " algorithems.";
//	cout << "\nBut first please enter the number of individuals that will be sorted: " << flush;
//	cin >> numberOfPepoleToSort;
//
//	vector<Person*> people;
//
//	string id, firstName, lastName;
//	int personlNumber = 1;
//
//	do {
//
//		system("cls");
//
//		cout << "Please enter details for person number: " << personlNumber;
//		cout << "\nPlease enter ID: ";
//		cin >> id;
//		cout << "\nPlease enter first name: ";
//		cin >> firstName;
//		cout << "\nPlease enter last name: ";
//		cin >> lastName;
//
//		try {
//			people.push_back(new Person(id, firstName, lastName));
//			personlNumber++;
//		}
//
//		catch (string ex) {
//
//			char reply;
//			bool isValidReply = false;
//
//			cout << ex << endl;
//			do {
//
//				cout << "Re-enter or Quit? [r/q] ";
//				cin >> reply;
//
//				if (reply == 'q' || reply == 'r') isValidReply = true;
//
//			} while (!isValidReply);
//
//			if (reply == 'r') continue;
//
//			break;
//		}
//	} while (personlNumber <= numberOfPepoleToSort);

	return 0;
}

//void HeapSort(Person* A,int n,int& NumComp)
//{
//    Heap heap(A,n,NumComp);
//    Person person;
//
//    for(int i = 0 ; i < n; i++)
//    {
//        person = heap.DeleteMin(NumComp);
//        A[i] = person;
//    }
//}

const Person& selectHeap(Person arr[],int size,int k,int& NumComp)
{
    Heap heap(arr,size,NumComp);
    Person person;

    for(int i = 0 ; i < k-1; i++)
        person = heap.DeleteMin(NumComp);

    return heap.DeleteMin(NumComp);
}