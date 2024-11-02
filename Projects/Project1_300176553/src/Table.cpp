#include "../include/Table.h"

// Constructor to initialize Table from a file stream
Table::Table(std::istream& in, const CardFactory* factory)
    : player1(in, factory), player2(in, factory), deck(in, factory),
      discardPile(in, factory), tradeArea(in, factory) {}

// Checks if a player has won the game
bool Table::win(std::string& winnerName) const {
    if (deck.empty()) {
        if (player1.getNumCoins() > player2.getNumCoins()) {
            winnerName = player1.getName();
            return true;
        } else if (player2.getNumCoins() > player1.getNumCoins()) {
            winnerName = player2.getName();
            return true;
        } else {
            winnerName = "Tie";
            return true;
        }
    }
    return false;
}

// Prints the hand of each player
void Table::printHand(bool showAll) const {
    std::cout << player1.getName() << "'s hand: ";
    player1.printHand(std::cout, showAll);
    std::cout << "\n";

    std::cout << player2.getName() << "'s hand: ";
    player2.printHand(std::cout, showAll);
    std::cout << "\n";
}

// Friend function to print the state of the table
std::ostream& operator<<(std::ostream& out, const Table& table) {
    out << table.player1.getName() << " has " << table.player1.getNumCoins() << " coins\n";
    out << table.player1;

    out << table.player2.getName() << " has " << table.player2.getNumCoins() << " coins\n";
    out << table.player2;

    out << "Discard Pile: ";
    out << table.discardPile;  // Assuming DiscardPile has operator<<

    out << "\nTrade Area: ";
    out << table.tradeArea;  // Assuming TradeArea has operator<<

    return out;
}
