#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

class Table{
	
private:
    Player *player1;
    Player *player2;
    
    // id of the current player
	int currentPlayer; 
    DiscardPile *discardp;
    TradeArea *tradeAr;
    Deck *deck;
    CardFactory *cardf;

public:
    /**
     * @brief Construct a new Table object
     *
     * @param p_one
     * @param p_two
     * @param d_pile
     * @param tr_arr
     * @param dck
     * @param cfactory
     */
    Table(Player &p_one, Player &p_two, DiscardPile &d_pile, TradeArea &tr_arr, Deck &dck, CardFactory &cfactory)
        : player1(&p_one), player2(&p_two), discardp(&d_pile), tradeAr(&tr_arr), deck(&dck), cardf(&cfactory), currentPlayer(0) {}

    /**
     * @brief Destroy the Table object
     */
    ~Table() = default;

    /**
     * @brief Check if a player has won
     *
     * @param winnerName Name of the winning player (output)
     * @return true if a player has won, false otherwise
     */
    bool win(std::string &winnerName);

    /**
     * @brief Print the hand of the current player
     *
     * @param showAll If true, show the entire hand; if false, show only the top card
     */
    void printHand(bool showAll);

    /**
     * @brief Save the current game state to files
     */
    void saveTable();

    /**
     * @brief Reload player information from a file
     *
     * @param playerId The player ID to reload (1 or 2)
     */
    void reloadPlayer(int playerId);

    /**
     * @brief Reload the deck from a saved file
     */
    void reloadDeck();

    /**
     * @brief Reload the discard pile from a saved file
     */
    void reloadDiscardPile();

    /**
     * @brief Reload the trade area from a saved file
     */
    void reloadTradeArea();

    /**
     * @brief Get the deck
     *
     * @return Deck*
     */
    Deck *getDeck() { return deck; }

    /**
     * @brief Get a player by their ID
     *
     * @param id Player ID (0 for p1, 1 for p2)
     * @return Player*
     */
    Player *getPlayer(int pID) { return (pID == 0) ? player1 : player2; }

    /**
     * @brief Get the discard pile
     *
     * @return DiscardPile*
     */
    DiscardPile *getDiscardPile() { return discardp; }

    /**
     * @brief Get the trade area
     *
     * @return TradeArea*
     */
    TradeArea *getTradeArea() { return tradeAr; }

    /**
     * @brief Overload of the insertion operator to display table information
     *
     * @param output Output stream
     * @param tb Table object to display
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &output, const Table &tb);
};

#endif
