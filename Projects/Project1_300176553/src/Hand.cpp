#include "../include/Hand.h"
#include "../include/CardFactory.h"

// Constructor to initialize Hand from a file stream
Hand::Hand(std::istream& in, const CardFactory* factory) {
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

// Adds a card to the rear of the hand
Hand& Hand::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Removes and returns the top card from the hand
Card* Hand::play() {
    if (cards.empty()) {
        return nullptr;  // Return nullptr if the hand is empty
    }
    Card* topCard = cards.front();
    cards.pop_front();
    return topCard;
}

// Returns (without removing) the top card from the hand
Card* Hand::top() const {
    if (cards.empty()) {
        return nullptr;
    }
    return cards.front();
}

// Returns and removes the card at the given index
Card* Hand::operator[](int index) {
    if (index < 0 || index >= cards.size()) {
        return nullptr;  // Return nullptr if index is out of bounds
    }
    auto it = cards.begin() + index;
    Card* card = *it;
    cards.erase(it);  // Remove the card at the specified index
    return card;
}

// Prints all cards in the hand in order
std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    for (const auto& card : hand.cards) {
        if (card) {
            out << *card << " ";  // Prints each card using the Card class's operator<<
        }
    }
    return out;
}

// Destructor
Hand::~Hand() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}
