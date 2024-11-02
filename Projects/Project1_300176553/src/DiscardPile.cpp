#include "../include/DiscardPile.h"
#include "../include/CardFactory.h"

// Constructor to initialize DiscardPile from a file stream
DiscardPile::DiscardPile(std::istream& in, const CardFactory* factory) {
    std::string cardType;
    while (in >> cardType) {
        Card* card = factory->createCard(cardType);  // Assuming createCard is a method in CardFactory
        if (card != nullptr) {
            cards.push_back(card);
        } else {
            throw std::runtime_error("Unknown card type in file: " + cardType);
        }
    }
}

// Adds a card to the top of the DiscardPile
DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Removes and returns the top card from the discard pile
Card* DiscardPile::pickUp() {
    if (cards.empty()) {
        return nullptr;  // Return nullptr if the discard pile is empty
    }
    Card* topCard = cards.back();
    cards.pop_back();
    return topCard;
}

// Returns (without removing) the top card from the discard pile
Card* DiscardPile::top() const {
    if (cards.empty()) {
        return nullptr;
    }
    return cards.back();
}

// Prints all cards in the discard pile
void DiscardPile::print(std::ostream& out) const {
    for (const auto& card : cards) {
        if (card) {
            out << *card << " ";  // Prints each card using the Card class's operator<<
        }
    }
}

// Insertion operator to print only the top card of the discard pile
std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile) {
    if (!discardPile.cards.empty()) {
        out << *(discardPile.cards.back());  // Print only the top card
    }
    return out;
}

// Destructor
DiscardPile::~DiscardPile() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}

