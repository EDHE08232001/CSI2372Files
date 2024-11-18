#ifndef DECK_H
#define DECK_H

/**
 * @file Deck.h
 * @brief Contains the declaration of the Deck class used in the card game.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Card.h"

class CardFactory;

/**
 * @class Deck
 * @brief Represents the deck of cards in the game.
 * Inherits from std::vector<Card*> to store pointers to Card objects.
 *
 * The Deck class manages a collection of Card pointers, providing functionalities
 * to draw cards, save the deck, and load it from a file. It uses polymorphism
 * to handle different types of bean cards derived from the Card base class.
 */
class Deck : public std::vector<Card *>
{
public:
    /**
     * @brief Default constructor for the Deck class.
     */
    Deck() : std::vector<Card *>() {};

    /**
     * @brief Constructs a Deck object from an input stream.
     * Reconstructs the Deck from saved data.
     * @param input The input stream to read from.
     * @param cf Pointer to the CardFactory (currently unused).
     *
     * This constructor reads card data from a file to reconstruct the Deck.
     */
    Deck(std::istream &input, const CardFactory *cf);

    /**
     * @brief Copy constructor for the Deck class.
     * Creates a copy of the Deck.
     * @param d The Deck object to copy from.
     *
     * Performs a shallow copy of the Deck. Note that this may lead to issues
     * if cards are deleted elsewhere, as multiple Decks may point to the same cards.
     */
    Deck(const Deck &d);

    /**
     * @brief Destructor for the Deck class.
     * Deletes all Card pointers stored in the Deck.
     */
    ~Deck();

    /**
     * @brief Draws and removes the top card from the Deck.
     * @return Pointer to the drawn Card.
     */
    Card *draw();

    /**
     * @brief Assignment operator for the Deck class.
     * Copies the contents of one Deck to another.
     * @param d The Deck object to assign from.
     * @return Reference to the assigned Deck.
     *
     * Performs a shallow copy of the Deck's contents.
     */
    Deck &operator=(const Deck &d);

    /**
     * @brief Overloaded insertion operator to print the Deck.
     * Prints all cards in the Deck to the output stream.
     * @param output The output stream.
     * @param d The Deck object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &output, const Deck &d);

    /**
     * @brief Saves the Deck to a file.
     * @param filename The output file stream to write to.
     */
    void saveDeck(std::ofstream &filename);
};

#endif // DECK_H
