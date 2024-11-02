#include "../include/TradeArea.h"
#include "../include/CardFactory.h"

// Constructor to initialize TradeArea from a file stream
TradeArea::TradeArea(std::istream& in, const CardFactory* factory) {
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

// Adds a card to the trade area without checking legality
TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Checks if a card of the same bean type is already in the trade area
bool TradeArea::legal(Card* card) const {
    for (const auto& existingCard : cards) {
        if (existingCard->getName() == card->getName()) {
            return true;  // Legal to add if there's already a card of this bean type
        }
    }
    return false;
}

// Removes and returns a card of the specified bean type from the trade area
Card* TradeArea::trade(const std::string& beanName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == beanName) {
            Card* card = *it;
            cards.erase(it);  // Remove the card from the list
            return card;  // Return the removed card
        }
    }
    return nullptr;  // Return nullptr if no card of the specified type is found
}

// Returns the number of cards in the trade area
int TradeArea::numCards() const {
    return cards.size();
}

// Prints all cards in the trade area
std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    for (const auto& card : tradeArea.cards) {
        if (card) {
            out << *card << " ";  // Print each card using the Card class's operator<<
        }
    }
    return out;
}

TradeArea::~TradeArea() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}
