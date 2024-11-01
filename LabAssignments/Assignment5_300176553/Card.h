#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream> // Added for std::ostringstream
#include <cassert> // For assert()
using namespace std;

// Enum to represent card colors
enum color
{
    club,
    diamond,
    heart,
    spade
};

class Card
{
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();

private:
    color col;
    int val;
};

/* Constructor */
Card::Card(color c, int v)
{
    assert(v >= 1 && v <= 13); // Ensure the card value is between 1 and 13
    col = c;
    val = v;
}

/* write() method */
void Card::write()
{
    // Display card value
    string valueStr;
    if (val == 1)
    {
        valueStr = "Ace";
    }
    else if (val == 11)
    {
        valueStr = "Jack";
    }
    else if (val == 12)
    {
        valueStr = "Queen";
    }
    else if (val == 13)
    {
        valueStr = "King";
    }
    else
    {
        // Convert integer value to string using stringstream
        std::ostringstream oss;
        oss << val;
        valueStr = oss.str();
    }

    // Display card color
    string colorName;
    switch (col)
    {
    case club:
        colorName = "Clubs";
        break;
    case diamond:
        colorName = "Diamonds";
        break;
    case heart:
        colorName = "Hearts";
        break;
    case spade:
        colorName = "Spades";
        break;
    default:
        break;
    }

    // Output the card information
    cout << valueStr << " of " << colorName << endl;
}

#endif // CARD_H
