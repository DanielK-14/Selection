#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Selection.h"
#include <time.h>

using namespace std;

void FreeArray(Person** arr,int size);
Person** getDataFromFile(string fname,int& size, int& val);

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
        selection.selectHeap();     //selectHeap
		selection.BST();            //BST
        selection.RandSelection();  //RandSelection1
        selection.RandSelection();  //RandSelection2
        selection.RandSelection();  //RandSelection3
        selection.RandSelection();  //RandSelection4
        FreeArray(arr,size);
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    }

}

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