#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

class Table {
private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

public:
    // Constructor to initialize Table from file
    Table(std::istream& in, const CardFactory* factory);

    // Checks if a player has won the game
    bool win(std::string& winnerName) const;

    // Prints the hand of each player
    void printHand(bool showAll) const;

    // Friend function to print the state of the table
    friend std::ostream& operator<<(std::ostream& out, const Table& table);
};

#endif // TABLE_H
