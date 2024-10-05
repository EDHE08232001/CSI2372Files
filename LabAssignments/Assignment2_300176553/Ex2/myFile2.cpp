/*myFile2.cpp : Ex2 a2 CSI2372A*/

#include "myFile2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size){
	//for loop iterates over every element in the array by treating it as a key that is going to be inserted into the sorted portion of this array.
	for (int t = 1; t < size; t++){  //iterating over the array, starts at t = 1 and goes till the end (t < size)
		int arrKey = a[t];   //arrKey hold the current elements value a[t] that is going to be inserted
		int m = t - 1;  //index m point to the element befor a[t], which is the last element of the sorted array
		
		
		//while loop shifts larger elements to the right of the array to make space for the key
		while (m >=0 && a[m] > arrKey){  //check if a[m] if greater than arrKey
		//if a[m] > arrKey, means that the element at position m needs to move one position to the right to make room for arrKey
		//this process continues (m = m - 1) moving to the left of the sorted portion of the array (a[0] to a[m]) 
		//this happens until we find the acceptable position for arrKey or reach the beginning of the array (m >= 0)
			a[m + 1] = a[m];
			m = m - 1;
		}
		a[m + 1] = arrKey;  //this happens when we find the correct position for arrKey, then it is insterted at position m + 1.
		
	}
}
