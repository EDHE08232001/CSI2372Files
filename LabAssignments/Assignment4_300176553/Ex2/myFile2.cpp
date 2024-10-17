/*Ex2 devoir4 CSI2772A*/

#include <iostream> 
#include "myFile2.h"
using namespace std;

int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "The elements of a are :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;
    
    delete[] tab; // freeing up this pointer

    return 0;
}

// constructor with parameters: initializes the set with the elements from the given array
SetInt::SetInt(int arr[], int arrSize) {
    size = arrSize;
    elem = new int[size];
    
    for (int i = 0; i < size; i++) {
        elem[i] = arr[i];
    }
}

// destructor: deallocates the memory used by the set
SetInt::~SetInt() {
    delete[] elem;
    elem = nullptr;
    size = 0;
}

// copy constructor: creates a deep copy of another SetInt object
SetInt::SetInt(const SetInt& other) {
    size = other.size;
    if (size > 0) {
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = other.elem[i];
        }
    } else {
        elem = nullptr;
    }
}

// add method: adds a value to the set if it does not already exist
void SetInt::add(int value) {
    if (!contains(value)) {
        int* newElem = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newElem[i] = elem[i];
        }
        newElem[size] = value;
        delete[] elem;
        elem = newElem;
        size++;
    }
}

// remove method: removes a value from the set if it exists
void SetInt::remove(int value) {
    int index;
    if (containsIn(value, index)) {
        int* newElem = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                newElem[j++] = elem[i];
            }
        }
        delete[] elem;
        elem = newElem;
        size--;
    }
}

// contsina methods: check if a value exists in the set
bool SetInt::contains(int value) {
    int index;
    return containsIn(value, index);
}

// NbElem method: returns the number of elements
int SetInt::nbElem() {
    return size;
}

// TabElem method: returns a dynamically allocated array
int* SetInt::tabElem() {
    if (size == 0) {
        return nullptr;
    }

    int* tab = new int[size];

    for (int i = 0; i < size; i++) {
        tab[i] = elem[i];
    }

    return tab;
}

// ContainsIn (Auxiliary) method: check if a value exists in the set and returns its index
bool SetInt::containsIn(int value, int& index) {
    for (int i = 0; i < size; i++) {
        if (elem[i] == value) {
            index = i;
            return true;
        }
    }
    index = -1;
    return false;
}