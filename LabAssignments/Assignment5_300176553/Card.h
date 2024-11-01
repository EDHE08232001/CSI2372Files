#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string> // Include string header for std::string
using namespace std;
#include <cassert> // for assert()

// Enum for card colors/suits
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

/* write() method to display card information */
void Card::write()
{
    // Display card color/suit
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
    }

    // Display card value
    string valueNames[] = {"", "Ace", "2", "3", "4", "5", "6", "7",
                           "8", "9", "10", "Jack", "Queen", "King"};
    string valueStr = valueNames[val];

    cout << valueStr << " of " << colorName << endl;
}

#endif // CARD_H
