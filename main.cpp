#include <stdlib.h>
#include <iostream>
#include <vector>
//#include "BSTree.h"
#include "Person.h"
#include "Selection.h"
#include <time.h>

using namespace std;

void FreeArray(Person** arr,int size);
Person** getDataFromFile(string fname,int& size, int& val);

//const Person& RandSelection(Person A[],int size,int k,int& NumComp);    ///(1)
//const Person& selectHeap(Person arr[],int size,int k,int& NumComp);     ///(2)
//const Person BST(vector<Person> people, int k, int &NumComp);			///(3)

//const Person& Selection(Person A[],int left,int right,int i,int& NumComp);
//int Partition(Person A[], int left, int right,int& NumComp);

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        srand(time(nullptr));
        string fname;
        cin >> fname;
        int size,val;
        Person** arr = getDataFromFile(fname,size, val);
        Selection selection(size,arr,val);
        cout << "\n(" << i << ")";
        selection.selectHeap();     //selectHeap
		selection.BST();            //BST
		selection.BST();			//BST
        selection.RandSelection();  //RandSelection1
        selection.RandSelection();  //RandSelection2
        selection.RandSelection();  //RandSelection3
        selection.RandSelection();  //RandSelection4
        FreeArray(arr,size);
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    }

//    Person p[10];
//
//    Person p1("100000000","Dan","Kalmykov");
//    Person p2("200000000","a","b");
//    Person p3("300000000","a","b");
//    Person p4("400000000","a","b");
//    Person p5("500000000","a","b");
//    Person p6("600000000","a","b");
//    Person p7("700000000","a","b");
//    Person p8("800000000","a","b");
//    Person p9("900000000","a","b");
//    Person p10("910000000","a","b");
//
//    p[0] = p9;
//    p[1] = p8;
//    p[2] = p10;
//    p[3] = p7;
//    p[4] = p6;
//    p[5] = p2;
//    p[6] = p1;
//    p[7] = p3;
//    p[8] = p4;
//    p[9] = p5;
//
//	vector<Person> people(p, p + 10);
//
//	Selection select(10,p,10);
//	select.RandSelection();
//	select.selectHeap();

//    int numHeap = 0;
//    int numRandSelection = 0;
//	int numBST = 0;
//    Person resRandSelection = RandSelection(p,(sizeof(p)/ sizeof(Person)),2,numRandSelection);  //Check for (1)
//	Person resBST = BST(people, 2, numBST);														//Check for (2)
	//Person res = selectHeap(p,(sizeof(p)/ sizeof(Person)),2,numHeap);                         //Check for (3)

//    cout << "\n(RAND SELECTION) The person ID is: " << resRandSelection.ID() << endl;
//    cout << "(RAND SELECTION) Num of compares: " << numRandSelection << endl;
//
//	cout << "\n(BST) The person ID is: " << resBST.ID() << endl;
//	cout << "(BST) Num of compares: " << numBST << endl;

    //cout << "(HEAP) The person ID is: " << res.ID() << endl;
    //cout << "(HEAP) Num of compares: " << numHeap << endl;

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
//
//	return 0;

}

//const Person selectHeap(Person arr[],int size,int k,int& NumComp)
//{
//    Heap heap(arr,size,NumComp);
//    Person person;
//
//    // Deletes all the k-1 minimum values
//    for(int i = 0 ; i < k-1; i++)
//        person = heap.DeleteMin(NumComp);
//
//    // Deletes from the heap the k value of its size and returns it.
//    return heap.DeleteMin(NumComp);
//}

//const Person& RandSelection(Person A[],int size,int k,int& NumComp)
//{
//    return Selection(A,0,size-1,k,NumComp);
//}
//
//const Person& Selection(Person A[],int left,int right,int i,int& NumComp)
//{
//    // In case the requested value was not found till the point we were left with 1 value for check after all
//    // partitions made inan even size of A[].
//    if(right == left)
//        return A[right];
//
//    // Generate a random number in between left and right
//    srand(time(nullptr));
//    int pivot = left + rand() % (right - left);
//
//    // Swap A[pivot] with A[right]
//    Person::Swap(A[pivot], A[right]);
//
//    // Gets pivot's correct location after partition.
//    pivot = Partition(A, left, right,NumComp);
//
//    // Amount of values on the left side of the pivot and it self, in the bordered array we have sent.
//    int leftPart = pivot-left+1;
//
//    if(i == leftPart)
//        return A[pivot];
//    if(i < leftPart)
//        return Selection(A,left,pivot-1,i,NumComp);
//    else
//        return Selection(A,pivot+1,right,i-leftPart,NumComp);
//}
//
//int Partition(Person A[], int left, int right,int& NumComp)
//{
//    Person pivot = A[right]; // pivot
//    int i = left;
//
//    for (int j = left; j < right; j++)
//    {
//        // If current element is smaller than pivot
//        if (A[j] < pivot)
//        {
//            swap(A[i], A[j]);
//            i++; // increment index of next place for smaller values
//        }
//        NumComp++;
//    }
//    swap(A[i], A[right]);
//    return (i);
//}

//const Person BST(vector<Person> people, int k, int &NumComp) {
//
//	BSTree * peopleBinarySearchTree = new BSTree();
//
//	for (Person person : people) {
//		peopleBinarySearchTree->Insert(person.ID(), person, NumComp);
//	}
//
//	vector<Person> PeopleInOrder;
//	peopleBinarySearchTree->Inorder(PeopleInOrder);
//
//	return	PeopleInOrder[k];
//}

Person** getDataFromFile(string fname,int& size,int& val)
{
    ifstream inFile(fname);
    inFile >> size;
    Person** PArray = new Person*[size];
    for (int i = 0; i < size; i++)
    {
        PArray[i] = new Person(inFile);
    }
    inFile >> val;
    inFile.close();
    return PArray;
}

void FreeArray(Person** arr,int size)
{
    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;
}