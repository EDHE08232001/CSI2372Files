#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Exercise 1\n"
         << endl;

    // char size
    cout << "size of a character in bytes: " << sizeof(char) << endl;

    // int size
    cout << "size of a int in bytes: " << sizeof(int) << endl;

    // float size
    cout << "size of a float in bytes: " << sizeof(float) << endl;

    // double size
    cout << "size of a double in bytes: " << sizeof(double) << endl;

    // short int size
    cout << "size of a short int in bytes: " << sizeof(short int) << endl;

    // unsigned int size
    cout << "size of a unsigned int in bytes: " << sizeof(unsigned int) << endl;

    // Enter an integer
    cout << "Please Enter an Integer: ";

    int input_int;

    cin >> input_int;

    // print a new line
    cout << endl;

    cout << "In decimal: " << input_int << endl;

    cout << "In octal: " << oct << input_int << endl;

    cout << "In hext: " << hex << input_int << endl;

    // Reset to decimal
    cout << dec;

    // A real number
    cout << "Enter a real number: ";

    double input_num;

    cin >> input_num;

    cout << input_num << endl;

    cout << hexfloat << input_num << endl;

    // reset
    cout << defaultfloat;

    char input_char;
    cout << "Enter a cahr: ";
    cin >> input_char;
    cout << input_char << endl;
    cout << static_cast<int>(input_char) << endl;

    return 0;
}