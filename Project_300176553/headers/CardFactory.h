#ifndef CARDFACTORY_H
#define CARDFACTORY_H

/**
 * @file CardFactory.h
 * @brief Contains the declaration of the CardFactory class used in the card
 * game.
 */

#include "Card.h"
#include "Deck.h"
#include <algorithm>
#include <random>

/**
 * @class CardFactory
 * @brief Singleton class responsible for creating and managing all Card
 * instances.
 *
 * The CardFactory class ensures that there is only one instance of each type of
 * card in the game. It provides a method to get a shuffled deck containing all
 * the cards. It also prevents copying to maintain the singleton pattern.
 */
class CardFactory
{
private:
  Deck *deck;    /**< Pointer to the Deck containing all the cards */
  CardFactory(); /**< Private constructor for the singleton pattern */

  /**
   * @brief Deleted copy constructor to prevent copying.
   */
  CardFactory(const CardFactory &) = delete;

  /**
   * @brief Deleted assignment operator to prevent copying.
   * @return Reference to the CardFactory.
   */
  CardFactory &operator=(const CardFactory &) = delete;

public:
  static CardFactory *instance; /**< Static pointer to the singleton instance */

  /**
   * @brief Returns a pointer to the singleton CardFactory instance.
   * @return Pointer to the CardFactory instance.
   */
  static CardFactory *getFactory();

  /**
   * @brief Returns a shuffled Deck containing all the cards.
   * @return Pointer to the Deck.
   */
  Deck *getDeck();

  /**
   * @brief Destructor for the CardFactory.
   */
  ~CardFactory();
};

#endif // CARDFACTORY_H
