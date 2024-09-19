#include <iostream>
#include <cmath>   // for M_PI
#include <cstdlib> // For exit()
#include "myfile2.h"

using namespace std;

// calculate the surface of a disk
double surface(double radius)
{
    return M_PI * radius * radius;
}

// calculate the volume of the cylinder
double volume(double radius, double height)
{
    return M_PI * radius * radius * height;
}

char menu(void);

int main()
{
    char choice;
    int nvolume = 0;  // Number of times the volume function has been executed
    int nsurface = 0; // Number of times the surface function has been executed
    double radius, height;

    while (1)
    {
        choice = menu();
        switch (choice)
        {
        case '1':
            cout << endl
                 << "Surface calculation" << endl;
            cout << "Enter the radius: ";
            cin >> radius;
            cout << "The surface is: " << surface(radius) << endl;
            nsurface++;
            break;

        case '2':
            cout << endl
                 << "Volume calculation" << endl;
            cout << "Enter the radius: ";
            cin >> radius;
            cout << "Enter the height: ";
            cin >> height;
            cout << "The volume is: " << volume(radius, height) << endl;
            nvolume++;
            break;

        case '3':
            cout << endl
                 << "Exit the program" << endl;
            cout << "The volume function has been executed " << nvolume << " times" << endl;
            cout << "The surface function has been executed " << nsurface << " times" << endl;
            exit(0);

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
}

char menu(void)
{
    char choice;
    cout << "What do you want to do?:" << endl;
    cout << "- Calculate the area of a disk from a radius (Press 1)" << endl;
    cout << "- Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl;
    cout << "- Exit the program (press 3)" << endl;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}