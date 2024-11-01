#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;
#include <cassert> //for assert()

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

/*Constructor*/
Card::Card(color c, int v)
{
    assert(v >= 1 && v <= 13); // we use a standard function void assert (int expression)
    // which indicates an error message if the expression is false.
    col = c;
    val = v;
}

void Card::write()
{
    // Display card color
    string colorName;
    switch (col)
    {
    case club:
        colorName = "Club";
        break;
    case diamond:
        colorName = "Diamond";
        break;
    case heart:
        colorName = "Heart";
        break;
    case spade:
        colorName = "Spade";
        break;
    default:
        break;
    }

    // Display card value
    string valueStr;
    if (val == 11)
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
        valueStr = to_string(val);   // this caused problems for my player.h
    }

    cout << colorName << " " << valueStr << endl;
}

#endif // CARD_H
