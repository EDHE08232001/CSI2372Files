#include "../include/CardFactory.h"
#include "../include/Deck.h"
#include "../include/Card.h"

CardFactory *CardFactory::getFactory()
{
    static CardFactory factory;
    return &factory;
}

CardFactory::CardFactory()
{
    // Populate the allCards vector with the appropriate number of each type of card
    for (int i = 0; i < 20; ++i)
        allCards.push_back(new Card(Card::BeanType::Blue));
    for (int i = 0; i < 18; ++i)
        allCards.push_back(new Card(Card::BeanType::Chili));
    for (int i = 0; i < 16; ++i)
        allCards.push_back(new Card(Card::BeanType::Stink));
    for (int i = 0; i < 14; ++i)
        allCards.push_back(new Card(Card::BeanType::Green));
    for (int i = 0; i < 12; ++i)
        allCards.push_back(new Card(Card::BeanType::Soy));
    for (int i = 0; i < 10; ++i)
        allCards.push_back(new Card(Card::BeanType::Black));
    for (int i = 0; i < 8; ++i)
        allCards.push_back(new Card(Card::BeanType::Red));
    for (int i = 0; i < 6; ++i)
        allCards.push_back(new Card(Card::BeanType::Garden));
}

Deck CardFactory::getDeck()
{
    // Create a deck from all the cards
    Deck deck;
    for (auto &card : allCards)
    {
        deck.push_back(card);
    }

    // Shuffle the deck
    auto rng = std::default_random_engine{std::random_device{}()};
    std::shuffle(deck.begin(), deck.end(), rng);

    return deck;
}