#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(CardsSet &cardPacket, bool isComputer) : packet(cardPacket), computer(isComputer) {}
    int play();

private:
    CardsSet inHand;
    CardsSet &packet;
    const bool computer;
    int countPoints();
};

#endif // PLAYER_H