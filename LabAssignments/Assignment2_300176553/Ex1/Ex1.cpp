#include <iostream>
using namespace std;

int main(void){
	int tab[10];  //declares an array of 10 integers with undefined values
	int* p;  //declare a pointer p that can point to an integer
	
	for (int t = 0; t < 10; t++){ // this loop intializes each element of the array tab with the square of its index
		tab[t] = t * t;
	}
	
	//manipulating array elements 
	tab[2] = tab[1]; // tab[2] is assigned the value of tab[1] = 1. So, tab[2] = 1
	tab[2] = *(tab + 1);  //pointer arithmetic (*(tab + 1) dereferences the address of tab[1], and assigns it to tab[2].
	*(tab + 2) = tab[1];  //equivalent to tab[2] = tab[1]
	*(tab + 2) = *(tab + 1);  //operation with pointer that sets tab[2] to the value of tab[1]. Which makes them both 1.
	p = &tab[0]; //p is now assgined the address of tab[0], so now it points to the first element of the array which equals to 0.
	p = tab + 1;  //shifting the pointer to the second element in the array (tab[1]) which equals 1.
	tab[4] = *p;  //dereferences the pointer p, which was pointing to tab[1], so now *p = 1. This assigns tab[4] to 1, replacing the value of 16.

	//Printing the values
	cout << 4 << endl;  //simply print 4 from the console
	cout << tab[1] << endl;  // prints 1
	cout << tab[2] << endl;  // prints 1
	cout << tab[4] << endl;  // prints 1
	cout << *p << endl;      // prints 1
	cout << *(tab + 1) << endl;  // prints 1 since it is equivalent to tab[1] = 1
	
	return 0;
}
