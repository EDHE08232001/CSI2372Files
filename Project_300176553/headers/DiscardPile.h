#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

/**
 * @file DiscardPile.h
 * @brief Contains the declaration of the DiscardPile class used in the card
 * game.
 */

#include "Card.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

class CardFactory;

/**
 * @class DiscardPile
 * @brief Represents the discard pile in the game.
 * Inherits from std::vector<Card*> to store pointers to discarded Card objects.
 *
 * The DiscardPile class manages discarded cards, providing functionalities to
 * add cards, pick up the top card, view the top card, print the pile, and
 * save/load the pile from a file.
 */
class DiscardPile : public std::vector<Card *>
{
public:
  /**
   * @brief Default constructor for the DiscardPile class.
   */
  DiscardPile() : std::vector<Card *>() {};

  /**
   * @brief Constructs a DiscardPile object from an input stream.
   * Reconstructs the DiscardPile from saved data.
   * @param input The input stream to read from.
   * @param cf Pointer to the CardFactory (currently unused).
   *
   * This constructor reads card data from the input stream, creates
   * corresponding Card objects, and adds them to the DiscardPile.
   */
  DiscardPile(std::istream &input, const CardFactory *cf);

  /**
   * @brief Adds a card to the discard pile using the operator +=.
   * @param c Pointer to the Card to add.
   * @return Reference to the updated DiscardPile.
   */
  DiscardPile &operator+=(Card *c);

  /**
   * @brief Returns and removes the top card from the discard pile.
   * @return Pointer to the top Card.
   */
  Card *pickUp();

  /**
   * @brief Returns but does not remove the top card from the discard pile.
   * @return Pointer to the top Card.
   */
  Card *top();

  /**
   * @brief Inserts all the cards in the DiscardPile to the output stream.
   * @param os The output stream to write to.
   */
  void print(std::ostream &os);

  /**
   * @brief Overloaded insertion operator to print the top card of the
   * DiscardPile.
   * @param output The output stream.
   * @param dp The DiscardPile object to print.
   * @return Reference to the output stream.
   *
   * This operator prints only the top card of the discard pile.
   */
  friend std::ostream &operator<<(std::ostream &output, const DiscardPile &dp);

  /**
   * @brief Saves the DiscardPile to a file.
   * @param filename The output file stream to write to.
   */
  void saveDiscardPile(std::ofstream &filename);

  /**
   * @brief Destructor for the DiscardPile class.
   * Deletes all Card pointers stored in the DiscardPile.
   */
  ~DiscardPile();
};

#endif // DISCARD_PILE_H
