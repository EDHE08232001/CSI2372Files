#include "../include/Deck.h"
#include "../include/CardFactory.h"

// Constructor to initialize Deck from a file stream
Deck::Deck(std::istream& in, const CardFactory* factory) {
    std::string cardType;
    while (in >> cardType) {
        Card* card = factory->createCard(cardType);  // Assuming createCard is a method in CardFactory
        if (card != nullptr) {
            push_back(card);
        } else {
            throw std::runtime_error("Unknown card type in file: " + cardType);
        }
    }
}

// Draws and removes the top card from the deck
Card* Deck::draw() {
    if (empty()) {
        return nullptr;  // Return nullptr if the deck is empty
    }
    Card* topCard = back();
    pop_back();
    return topCard;
}

// Insertion operator to print all cards in the deck
std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (const auto& card : deck) {
        if (card) {
            out << *card << " ";  // Prints each card using the Card class's operator<<
        }
    }
    return out;
}

// Destructor
Deck::~Deck() {
    for (Card* card : *this) {
        delete card;
    }
    this->clear();
}
