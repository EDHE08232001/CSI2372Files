#include "../include/Card.h"

Card::Card(BeanType type) : type(type) {}

int Card::getCardsPerCoin(int coins) const
{
    switch (type)
    {
    case BeanType::Blue:
        if (coins == 1)
            return 4;
        if (coins == 2)
            return 6;
        if (coins == 3)
            return 8;
        if (coins == 4)
            return 10;
        break;
    case BeanType::Chili:
        if (coins == 1)
            return 3;
        if (coins == 2)
            return 6;
        if (coins == 3)
            return 8;
        if (coins == 4)
            return 9;
        break;
    case BeanType::Stink:
        if (coins == 1)
            return 3;
        if (coins == 2)
            return 5;
        if (coins == 3)
            return 7;
        if (coins == 4)
            return 8;
        break;
    case BeanType::Green:
        if (coins == 1)
            return 3;
        if (coins == 2)
            return 5;
        if (coins == 3)
            return 6;
        if (coins == 4)
            return 7;
        break;
    case BeanType::Soy:
        if (coins == 1)
            return 2;
        if (coins == 2)
            return 4;
        if (coins == 3)
            return 6;
        if (coins == 4)
            return 7;
        break;
    case BeanType::Black:
        if (coins == 1)
            return 2;
        if (coins == 2)
            return 4;
        if (coins == 3)
            return 5;
        if (coins == 4)
            return 6;
        break;
    case BeanType::Red:
        if (coins == 1)
            return 2;
        if (coins == 2)
            return 3;
        if (coins == 3)
            return 4;
        if (coins == 4)
            return 5;
        break;
    case BeanType::Garden:
        if (coins == 2)
            return 2;
        if (coins == 3)
            return 3;
        break;
    }
    return 0; // Default case if input is invalid
}

std::string Card::getName() const
{
    switch (type)
    {
    case BeanType::Blue:
        return "Blue";
    case BeanType::Chili:
        return "Chili";
    case BeanType::Stink:
        return "Stink";
    case BeanType::Green:
        return "Green";
    case BeanType::Soy:
        return "Soy";
    case BeanType::Black:
        return "Black";
    case BeanType::Red:
        return "Red";
    case BeanType::Garden:
        return "Garden";
    }
    return "Unknown"; // Should never reach here
}

void Card::print(std::ostream &out) const
{
    switch (type)
    {
    case BeanType::Blue:
        out << 'B';
        break;
    case BeanType::Chili:
        out << 'C';
        break;
    case BeanType::Stink:
        out << 'S';
        break;
    case BeanType::Green:
        out << 'G';
        break;
    case BeanType::Soy:
        out << 'Y';
        break;
    case BeanType::Black:
        out << 'b';
        break;
    case BeanType::Red:
        out << 'R';
        break;
    case BeanType::Garden:
        out << 'g';
        break;
    }
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
    card.print(out);
    return out;
}

Card::BeanType Card::getBeanType() const
{
    return type;
}