#include <iostream>
using namespace std;

int main(void){
	int tab[10];
	int* p;
	
	for (int t = 0; t < 10; t++){
		tab[t] = t * t;
	}
	
	tab[2] = tab[1];
	tab[2] = *(tab + 1);
	*(tab + 2) = tab[1];
	*(tab + 2) = *(tab + 1);
	p = &tab[0];
	p = tab + 1;
	tab[4] = *p;
	
	cout << 4 << endl;
	cout << tab[1] << endl;
	cout << tab[2] << endl;
	cout << tab[4] << endl;
	cout << *p << endl;
	cout << *(tab + 1) << endl;
	
	return 0;
}
