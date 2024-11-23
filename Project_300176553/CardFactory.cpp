#include "headers/CardFactory.h"

/**
 * @brief Initializes the static instance pointer to nullptr.
 */
CardFactory *CardFactory::instance =
    nullptr; // Initialize the instance to nullptr

/**
 * @brief Returns a pointer to the singleton CardFactory instance.
 *
 * If the instance does not exist, it creates a new one.
 * @return Pointer to the CardFactory instance.
 */
CardFactory *CardFactory::getFactory()
{
    if (!instance)
        instance = new CardFactory();
    return instance;
}

/**
 * @brief Returns a shuffled Deck containing all the cards.
 *
 * The deck is shuffled each time this method is called using a random seed.
 * @return Pointer to the Deck.
 */
Deck *CardFactory::getDeck()
{
    // Seed with a real random value, if available
    std::random_device rd;
    // Random number generator
    std::default_random_engine rng(rd());
    // Shuffle the deck
    std::shuffle(deck->begin(), deck->end(), rng);
    return deck;
}

/**
 * @brief Constructs a new CardFactory object.
 *
 * Initializes the deck and creates all the cards needed for the game.
 */
CardFactory::CardFactory()
{
    // Initialize the deck
    deck = new Deck();

    // Add 20 Blue Cards
    for (int i = 0; i < 20; i++)
    {
        Blue *b = new Blue;
        deck->push_back(b);
    }
    // Add 18 Chili Cards
    for (int i = 0; i < 18; i++)
    {
        Chili *c = new Chili;
        deck->push_back(c);
    }
    // Add 16 Stink Cards
    for (int i = 0; i < 16; i++)
    {
        Stink *s = new Stink;
        deck->push_back(s);
    }
    // Add 14 Green Cards
    for (int i = 0; i < 14; i++)
    {
        Green *g = new Green;
        deck->push_back(g);
    }
    // Add 12 Soy Cards
    for (int i = 0; i < 12; i++)
    {
        soy *s = new soy;
        deck->push_back(s);
    }
    // Add 10 Black Cards
    for (int i = 0; i < 10; i++)
    {
        black *b = new black;
        deck->push_back(b);
    }
    // Add 8 Red Cards
    for (int i = 0; i < 8; i++)
    {
        Red *r = new Red;
        deck->push_back(r);
    }
    // Add 6 Garden Cards
    for (int i = 0; i < 6; i++)
    {
        garden *g = new garden;
        deck->push_back(g);
    }
}

/**
 * @brief Destructor for the CardFactory.
 *
 * Deletes the deck and all the cards in it.
 */
CardFactory::~CardFactory() { delete deck; }