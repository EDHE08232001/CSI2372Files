#ifndef TABLE_H
#define TABLE_H

/**
 * @file Table.h
 * @brief Contains the declaration of the Table class used in the card game.
 */

#include "CardFactory.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
#include "TradeArea.h"

/**
 * @class Table
 * @brief Manages the overall game state, including players, deck, discard pile,
 * and trade area.
 *
 * The Table class represents the game table, holding all the components
 * necessary for gameplay. It manages two players, the deck, the discard pile,
 * the trade area, and provides methods to check for a win condition, print
 * hands, save and reload the game state, and access game components.
 */
class Table
{
  Player *p1;         /**< Pointer to Player 1 */
  Player *p2;         /**< Pointer to Player 2 */
  int currentPlayer;  /**< Index of the current player (0 or 1) */
  DiscardPile *dp;    /**< Pointer to the Discard Pile */
  TradeArea *tradeAr; /**< Pointer to the Trade Area */
  Deck *deck;         /**< Pointer to the Deck */
  CardFactory *cf;    /**< Pointer to the CardFactory */

public:
  /**
   * @brief Constructs a new Table object with given players and game
   * components.
   * @param p_one Reference to Player 1.
   * @param p_two Reference to Player 2.
   * @param d_pile Reference to the Discard Pile.
   * @param tr_arr Reference to the Trade Area.
   * @param dck Reference to the Deck.
   * @param cfactory Reference to the CardFactory.
   */
  Table(Player &p_one, Player &p_two, DiscardPile &d_pile, TradeArea &tr_arr,
        Deck &dck, CardFactory &cfactory)
  {
    p1 = &p_one;
    p2 = &p_two;
    dp = &d_pile;
    tradeAr = &tr_arr;
    deck = &dck;
    cf = &cfactory;
    currentPlayer = 0; // Initialize currentPlayer to 0 (Player 1)
  }

  /**
   * @brief Destructor for the Table class.
   *
   * Deletes all dynamically allocated game components.
   */
  ~Table()
  {
    delete p1;
    delete p2;
    delete dp;
    delete tradeAr;
    delete deck;
    // Note: Do not delete cf if it's a singleton managed elsewhere.
    // delete cf; // Uncomment if CardFactory is not a singleton.
  }

  /**
   * @brief Checks if a player has won the game.
   * @param pName Reference to a string where the winner's name will be stored.
   * @return True if a player has won, false otherwise.
   *
   * Determines the winner based on the number of coins when the deck is empty.
   */
  bool win(std::string &pName);

  /**
   * @brief Prints the hand of the current player.
   * @param allCards True to print all cards, false to print only the top card.
   */
  void printHand(bool allCards);

  /**
   * @brief Overloaded insertion operator to print the table's state.
   * @param output The output stream.
   * @param tb The Table object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output, const Table &tb);

  /**
   * @brief Saves the current game state to files.
   */
  void saveTable();

  /**
   * @brief Reloads a player from a saved file based on player ID.
   * @param p_id Player ID (1 or 2).
   */
  void reloadPlayer(int p_id);

  /**
   * @brief Reloads the deck from the saved file.
   */
  void reloadDeck();

  /**
   * @brief Reloads the discard pile from the saved file.
   */
  void reloadDiscardPile();

  /**
   * @brief Reloads the trade area from the saved file.
   */
  void reloadTradeArea();

  /**
   * @brief Returns a pointer to the deck.
   * @return Pointer to the Deck.
   */
  Deck *getDeck();

  /**
   * @brief Returns a pointer to a player based on ID.
   * @param id Player ID (0 for Player 1, 1 for Player 2).
   * @return Pointer to the Player.
   */
  Player *getPlayer(int id);

  /**
   * @brief Returns a pointer to the discard pile.
   * @return Pointer to the DiscardPile.
   */
  DiscardPile *getDiscardPile();

  /**
   * @brief Returns a pointer to the trade area.
   * @return Pointer to the TradeArea.
   */
  TradeArea *getTradeArea();
};

#endif // TABLE_H
