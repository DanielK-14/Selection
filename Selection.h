#ifndef SELECTION_SELECTION_H
#define SELECTION_SELECTION_H

#include "Person.h"
#include "Heap.h"
#include "BSTree.h"
#include <time.h>
#include <fstream>

class Selection
{
private:
    int size;
    Person** Arr;
    int valueNumber;
    int numOfCompares;

public:
    Selection(int _size,Person** array, int value);

    void RandSelection();
    void selectHeap();

    Person* SelectionFunc(Person** arr,int left,int right,int k) ;
    int Partition(Person** arr,int left, int right);
    Person** MakeCopy();
    void Reset();
    bool SetNewValue(int value);
    void Print(int type,Person* person);
};

#endif //SELECTION_SELECTION_H