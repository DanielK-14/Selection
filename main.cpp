#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Selection.h"
#include <time.h>

using namespace std;

void FreeArray(Person** arr,int size);
Person** getData(int& size, int& val);

int main()
{
    srand(time(nullptr));
    int size;
    int val;
    cin >> size;
    cin.ignore();

    Person** arr = getData(size, val);
    Selection selection(size,arr,val);
    selection.selectHeap();     //selectHeap
    selection.RandSelection();  //RandSelection
    selection.BST();            //BST
    FreeArray(arr,size);
}

Person** getData(int& size, int& val)
{
    string name;
    string id;
    Person** PArray = new Person*[size];
    for (int i = 0; i < size; i++)
    {
        cin >> id;
        cin.ignore();
        getline(cin,name);
        try {
            Person* person = new Person(id,name);
            if(i != 0)
            {
                for (int j = 0; j < i; j++)
                {
                    if(PArray[j]->ID() == stol(id))
                    {
                        string ex = "bad";
                        throw ex;
                    }
                }
            }
            PArray[i] = person;
        }
        catch(string ex) {
            cout << "invalid input" << endl;
            FreeArray(PArray,i);
            exit(1);
        }
    }
    cin >> val;
    return PArray;
}

void FreeArray(Person** arr,int size)
{
    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;
}