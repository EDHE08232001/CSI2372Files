/* myFile4.h : Ex4 a2 CSI2372A */

#include <iostream>
#include <cstdlib> // for exit()
#include <cstring> // for strcmp, strcpy
#include <limits>  // for INT_MAX
#include <string>  // For string class
#include <sstream> // For istringstream
using namespace std;

const int size_ch = 20; // maximum size of a string
const int nb_ch = 5;    // Number of strings processed

void display(char *tab[], int const &nbre);                  // displays strings
char menu(void);                                             // displays a menu and return the choice
void replace(char *tab[], int const &nbre, int const &size); // replace one string by another
void sort(char *tab[], int const &nbre);                     // insertion sort
