#include "../include/Player.h"
#include "../include/CardFactory.h"

// Constructor with player name
Player::Player(const std::string& playerName) : name(playerName) {}

// Constructor to reconstruct player from file
Player::Player(std::istream& in, const CardFactory* factory) {
    in >> name >> coins >> maxChains;
    // Assuming Chain types are stored in file, read them into chains
    std::string chainType;
    while (in >> chainType) {
        Chain_Base* chain = factory->createChain(chainType, in);  // Hypothetical factory method
        chains.push_back(chain);
    }
    hand = Hand(in, factory);
}

// Get player's name
std::string Player::getName() const {
    return name;
}

// Get number of coins
int Player::getNumCoins() const {
    return coins;
}

// Add coins
Player& Player::operator+=(int coinsToAdd) {
    coins += coinsToAdd;
    return *this;
}

// Get maximum number of chains
int Player::getMaxNumChains() const {
    return maxChains;
}

// Get current number of chains
int Player::getNumChains() const {
    return chains.size();
}

// Access chain at a given index
Chain_Base& Player::operator[](int i) {
    if (i < 0 || i >= chains.size()) {
        throw std::out_of_range("Chain index out of range.");
    }
    return *chains[i];
}

// Buy a third chain
void Player::buyThirdChain() {
    if (coins < 3) {
        throw NotEnoughCoins();
    }
    if (maxChains < 3) {
        maxChains = 3;
        coins -= 3;
        chains.push_back(nullptr); // Placeholder for a new chain
    }
}

// Print the player's hand
void Player::printHand(std::ostream& out, bool showAll) const {
    if (showAll) {
        out << hand;  // Print entire hand
    } else {
        Card* topCard = hand.top();
        if (topCard) {
            out << *topCard;  // Print only the top card
        }
    }
}

// Friend function to print player info
std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.name << " " << player.coins << " coins\n";
    for (const auto& chain : player.chains) {
        if (chain) {
            chain->print(out);  // Print each chain
            out << "\n";
        }
    }
    return out;
}

// Destructor to clean up dynamically allocated chains
Player::~Player() {
    for (auto chain : chains) {
        delete chain;
    }
}
