#ifndef HAND_H
#define HAND_H

/**
 * @file Hand.h
 * @brief Contains the declaration of the Hand class used to represent a
 * player's hand in the card game.
 */

#include "Card.h"
#include <cstdlib>
#include <list>
#include <queue>
#include <sstream>

class CardFactory;

/**
 * @class Hand
 * @brief Manages a player's hand of cards.
 *
 * The Hand class represents the cards a player holds. It provides
 * functionalities to add cards, play the top card, access cards by position,
 * and save/load the hand from a file. Internally, it uses a queue to manage the
 * order of cards.
 */
class Hand
{
private:
  // The queue to store pointers to the card objects representing the player's
  // hand
  std::queue<Card *, std::list<Card *>> pHand;

  /**
   * @brief Clears all cards from the hand.
   *
   * This function empties the pHand queue, removing all cards.
   */
  void clearHand()
  {
    while (!pHand.empty())
    {
      delete pHand.front();
      pHand.pop();
    }
  }

public:
  /**
   * @brief Default constructor for the Hand class.
   */
  Hand() {};

  /**
   * @brief Constructs a Hand object from an input stream.
   * Reconstructs the Hand from saved data.
   * @param input The input stream to read from.
   * @param cf Pointer to the CardFactory (currently unused).
   *
   * This constructor reads card data from the input stream, creates
   * corresponding Card objects, and adds them to the hand.
   */
  Hand(std::istream &input, const CardFactory *cf);

  /**
   * @brief Destructor for the Hand class.
   *
   * Deletes all Card pointers stored in the hand to prevent memory leaks.
   */
  ~Hand();

  /**
   * @brief Adds a card to the player's hand.
   * @param card Pointer to the Card to add.
   * @return Reference to the updated Hand object.
   */
  Hand &operator+=(Card *card);

  /**
   * @brief Returns and removes the top card from the player's hand.
   * @return Pointer to the Card played.
   */
  Card *play();

  /**
   * @brief Returns but does not remove the top card from the player's hand.
   * @return Pointer to the top Card.
   */
  Card *top();

  /**
   * @brief Returns the Card at a given index without removing it.
   * @param pos The position of the Card in the hand.
   * @return Pointer to the Card at the specified position.
   *
   * Throws an exception if the position is invalid.
   */
  Card *getCard(int pos);

  /**
   * @brief Returns and removes the Card at a given index.
   * @param pos The position of the Card to remove.
   * @return Pointer to the removed Card.
   *
   * Throws an exception if the position is invalid.
   */
  Card *operator[](int pos);

  /**
   * @brief Returns the number of cards in the player's hand.
   * @return The number of cards.
   */
  int numCards();

  /**
   * @brief Overloaded insertion operator to display the hand.
   * @param output The output stream.
   * @param hand The Hand object to print.
   * @return Reference to the output stream.
   */
  friend std::ostream &operator<<(std::ostream &output, Hand &hand);

  /**
   * @brief Saves the hand to a file.
   * @param filename The output file stream to write to.
   */
  void saveHand(std::ofstream &filename);

  /**
   * @brief Returns a pointer to the internal queue of cards.
   * @return Pointer to the queue of Card pointers.
   */
  std::queue<Card *, std::list<Card *>> *getListOfCards();
};

#endif // HAND_H
