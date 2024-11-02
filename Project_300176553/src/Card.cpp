#include "../include/Card.h"

// Implementations for Blue
int Blue::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 4;
    case 2:
        return 6;
    case 3:
        return 8;
    case 4:
        return 10;
    default:
        return 0;
    }
}

std::string Blue::getName() const
{
    return "Blue";
}

void Blue::print(std::ostream &out) const
{
    out << "B";
}

// Implementations for Chili
int Chili::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 3;
    case 2:
        return 6;
    case 3:
        return 8;
    case 4:
        return 9;
    default:
        return 0;
    }
}

std::string Chili::getName() const
{
    return "Chili";
}

void Chili::print(std::ostream &out) const
{
    out << "C";
}

// Implementations for Stink
int Stink::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 7;
    case 4:
        return 8;
    default:
        return 0;
    }
}

std::string Stink::getName() const
{
    return "Stink";
}

void Stink::print(std::ostream &out) const
{
    out << "S";
}

// Implementations for Green
int Green::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 6;
    case 4:
        return 7;
    default:
        return 0;
    }
}

std::string Green::getName() const
{
    return "Green";
}

void Green::print(std::ostream &out) const
{
    out << "G";
}

// Implementations for Soy
int Soy::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 6;
    case 4:
        return 7;
    default:
        return 0;
    }
}

std::string Soy::getName() const
{
    return "Soy";
}

void Soy::print(std::ostream &out) const
{
    out << "s";
}

// Implementations for Black
int Black::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 2;
    case 2:
        return 4;
    case 3:
        return 5;
    case 4:
        return 6;
    default:
        return 0;
    }
}

std::string Black::getName() const
{
    return "Black";
}

void Black::print(std::ostream &out) const
{
    out << "b";
}

// Implementations for Red
int Red::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    default:
        return 0;
    }
}

std::string Red::getName() const
{
    return "Red";
}

void Red::print(std::ostream &out) const
{
    out << "R";
}

// Implementations for Garden
int Garden::getCardsPerCoin(int coins) const
{
    switch (coins)
    {
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        return 0;
    }
}

std::string Garden::getName() const
{
    return "Garden";
}

void Garden::print(std::ostream &out) const
{
    out << "g";
}
