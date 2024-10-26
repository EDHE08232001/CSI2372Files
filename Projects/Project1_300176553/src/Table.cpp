#include "../include/Table.h"

Table::Table(const std::string &player1Name, const std::string &player2Name)
    : player1(player1Name), player2(player2Name) {}

Table::Table(std::istream &in) : player1(in), player2(in), deck(in), discardPile(in), tradeArea(in) {}

bool Table::win(std::string &winnerName) const
{
    if (deck.empty())
    {
        if (player1.getNumCoins() > player2.getNumCoins())
        {
            winnerName = player1.getName();
            return true;
        }
        else if (player2.getNumCoins() > player1.getNumCoins())
        {
            winnerName = player2.getName();
            return true;
        }
        else
        {
            winnerName = "Draw";
            return true;
        }
    }
    return false;
}

void Table::printHand(std::ostream &out, bool full, const Player &player) const
{
    player.printHand(out, full);
}

std::ostream &operator<<(std::ostream &out, const Table &table)
{
    out << "Table Status:\n";
    out << table.player1 << std::endl;
    out << table.player2 << std::endl;
    out << "Deck has " << table.deck.size() << " cards left." << std::endl;
    out << "Discard Pile: ";
    if (Card *topCard = table.discardPile.top())
    {
        out << *topCard << std::endl;
    }
    else
    {
        out << "Empty" << std::endl;
    }
    out << "Trade Area: " << table.tradeArea << std::endl;
    return out;
}