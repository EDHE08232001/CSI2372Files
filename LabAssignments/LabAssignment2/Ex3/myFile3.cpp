/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int **triangleInf(int n)
{
	// YOUR CODE
	int **tab = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		tab[i] = new int[i + 1];

		tab[i][0] = 1;
		tab[i][i] = 1;

		for (int j = 1; j < i; ++j)
		{
			tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
		}
	}

	return tab;
}

int main()
{
	int **tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}