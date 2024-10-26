#include "../include/Player.h"

Player::Player(const std::string &name) : name(name), coins(0), maxChains(2) {}

Player::Player(std::istream &in)
{
    in >> name >> coins >> maxChains;
    int numChains;
    in >> numChains;
    chains.resize(numChains);
    for (int i = 0; i < numChains; ++i)
    {
        Chain<Card> chain(in);
        chains[i] = chain;
    }
    hand = Hand(in);
}

std::string Player::getName() const
{
    return name;
}

int Player::getNumCoins() const
{
    return coins;
}

Player &Player::operator+=(int coins)
{
    this->coins += coins;
    return *this;
}

int Player::getMaxNumChains() const
{
    return maxChains;
}

int Player::getNumChains() const
{
    return chains.size();
}

Chain<Card> &Player::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(chains.size()))
    {
        throw std::out_of_range("Invalid chain index.");
    }
    return chains[i];
}

void Player::buyThirdChain()
{
    if (coins >= 3)
    {
        coins -= 3;
        maxChains = 3;
    }
    else
    {
        throw std::runtime_error("Not enough coins to buy a third chain.");
    }
}

void Player::printHand(std::ostream &out, bool full) const
{
    if (full)
    {
        out << hand;
    }
    else
    {
        Card *topCard = hand.top();
        if (topCard)
        {
            out << *topCard;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{
    out << player.name << " has " << player.coins << " coins" << std::endl;
    for (size_t i = 0; i < player.chains.size(); ++i)
    {
        out << "Chain " << (i + 1) << ": " << player.chains[i] << std::endl;
    }
    return out;
}