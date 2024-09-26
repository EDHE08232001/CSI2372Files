/* myFile4.cpp : Ex4 a2 CSI2372A */

#include "myFile4.h"

int main()
{
	int i;
	char *chain[nb_ch]; // array of pointers to char
	char choice;		// variable for the choice entered in menu()

	cout << endl
		 << "Enter the 5 character strings ending with a tab and a line return" << endl;

	for (i = 0; i < nb_ch; i++)
	{
		chain[i] = new char[size_ch]; // memory allocation
		cout << "Enter string " << i << ": ";
		cin.getline(chain[i], size_ch);
	}

	display(chain, nb_ch);

	while (1)
	{
		choice = menu();

		switch (choice)
		{
		case '1':
			display(chain, nb_ch);
			break;
		case '2':
			replace(chain, nb_ch, size_ch);
			break;
		case '3':
			sort(chain, nb_ch);
			break;
		case '4':
			// Free memory before exiting
			for (int i = 0; i < nb_ch; ++i)
			{
				delete[] chain[i];
			}
			exit(0);
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}

/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice  */
/********************************************************************************/

char menu(void)
{
	string line;
	char choice;

	cout << endl
		 << endl
		 << "\t\tMenu" << endl
		 << endl;
	cout << "1) Strings display." << endl;
	cout << "2) Replacement of a string by another one" << endl;
	cout << "3) Sorting strings" << endl;
	cout << "4) Exit of the program" << endl
		 << endl;
	cout << "Your choice: ";
	getline(cin, line);

	if (line.length() > 0)
		choice = line[0];
	else
		choice = '\0'; // Assign a null character if no input

	return (choice);
}

/********************************************************************************/
/* Function display which displays the strings */
/********************************************************************************/
void display(char *tab[], int const &nbre)
{
	for (int i = 0; i < nbre; ++i)
	{
		cout << "The string " << i << " is : " << tab[i] << endl;
	}
}

/********************************************************************************
 *
 * The replace function that replaces one string by another.
 * It takes as arguments an array of pointers to the strings "tab",
 * the number of elements of this array of pointers "nbre" and
 * the maximum size of the strings "size"
 *
 ********************************************************************************/

void replace(char *tab[], int const &nbre, int const &size)
{
	int numero; // the string to modify

	cout << endl
		 << "Enter the string number to modify: ";

	// Read the line and parse the integer
	string line;
	getline(cin, line);
	istringstream iss(line);
	if (!(iss >> numero))
	{
		cout << "Invalid input." << endl;
		return;
	}

	if (numero < 0 || numero >= nbre)
	{
		cout << "Invalid string number." << endl;
		return;
	}

	cout << "Enter the new string: ";

	// Read the new string
	char *newString = new char[size];
	cin.getline(newString, size);

	// Delete the old string
	delete[] tab[numero];

	// Assign the new string
	tab[numero] = newString;
}

/********************************************************************************/
/* Function sort to sort strings */
/********************************************************************************/
void sort(char *tab[], int const &nbre)
{
	int i, j;
	for (i = 1; i < nbre; ++i)
	{
		char *key = tab[i];
		j = i - 1;

		// Move elements of tab[0..i-1], that are greater than key, to one position ahead
		while (j >= 0 && strcmp(tab[j], key) > 0)
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = key;
	}
}
