#ifndef TRADEAREA_H
#define TRADEAREA_H

/**
 * @file TradeArea.h
 * @brief Contains the declaration of the TradeArea class used in the card game.
 */

#include "Card.h"
#include <cstdlib>
#include <list>
#include <sstream>

class CardFactory;

/**
 * @class TradeArea
 * @brief Manages the trade area where cards are openly available for players to
 * chain or leave for the next player.
 *
 * The TradeArea class holds cards openly and supports insertion and removal.
 * It manages a list of Card pointers, providing functionalities to add cards,
 * check if a card can be legally added, trade (remove) a card of a specific
 * bean, and get the number of cards in the trade area.
 */
class TradeArea
{
  // List holding pointers to cards in the trade area
  std::list<Card *> tradeAr;

  const int MAX_CARDS; /**< Maximum number of cards allowed in the trade area */

public:
  /**
   * @brief Default constructor for the TradeArea class.
   */
  TradeArea() : MAX_CARDS(3) {};

  /**
   * @brief Constructs a TradeArea object from an input stream.
   * Reconstructs the TradeArea from saved data.
   * @param input The input stream to read from.
   * @param cf Pointer to the CardFactory (currently unused).
   *
   * This constructor reads card data from the input stream, creates
   * corresponding Card objects, and adds them to the TradeArea.
   */
  TradeArea(std::istream &input, const CardFactory *cf);

  /**
   * @brief Adds a card to the trade area.
   * Does not check if it is legal to place the card.
   * @param card Pointer to the Card to add.
   * @return Reference to the updated TradeArea.
   */
  TradeArea &operator+=(Card *card);

  /**
   * @brief Checks if the card can be legally added to the TradeArea.
   * A card can be legally added if a card of the same bean is already in the
   * TradeArea.
   * @param card Pointer to the Card to check.
   * @return True if the card can be legally added, false otherwise.
   */
  bool legal(Card *card);

  /**
   * @brief Removes and returns a card of the specified bean name from the trade
   * area.
   * @param cardName The name of the bean to trade.
   * @return Pointer to the Card if found, nullptr otherwise.
   */
  Card *trade(const std::string &cardName);

  /**
   * @brief Returns the number of cards currently in the trade area.
   * @return Number of cards in the trade area.
   */
  int numCards();

  /**
   * @brief Overloaded insertion operator to print the trade area.
   * @param output The output stream.
   * @param tr_arr The TradeArea object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output,
                                  const TradeArea &tr_arr);

  /**
   * @brief Saves the TradeArea to a file.
   * @param filename The output file stream to write to.
   */
  void saveTradeArea(std::ofstream &filename);

  /**
   * @brief Returns a copy of the list of cards in the trade area.
   * @return A list of Card pointers.
   */
  std::list<Card *> getListOfCards();

  /**
   * @brief Destructor for the TradeArea class.
   * Deletes all Card pointers stored in the trade area.
   */
  ~TradeArea();
};

#endif // TRADEAREA_H
