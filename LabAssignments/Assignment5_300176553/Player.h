#ifndef PLAYER_H
#define PLAYER_H

#include "CardsSet.h"
#include <iostream>

class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer(isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();
};

int Player::play(){
	
	char choicePicked;
	int totalScore = 0;
	
	
	do{
		Card card = packet.take();
		inHand.put(card);
		
		std::cout<< "You get Card: ";
		card.write();
		totalScore = countPoints();
		std::cout<< "\nYour score is " << totalScore << " points\n";
		
		if (totalScore > 21){
			std::cout<< "You lost!\n";
			break;
		}
		
		if(!computer){
			std::cout<< "Any additional Card? (y/n) ";
			std::cin >> choicePicked;
		} else {
			choicePicked = (totalScore < 17) ? 'y' : 'n';
		}
	} while (choicePicked == 'y' || choicePicked == 'Y');
	
	return totalScore;
}

int Player::countPoints(){
	
	int totalPoints = 0;
	int aceCounter = 0;
	
	for (int t = 0; t < inHand.numCards(); t++){
		Card card = inHand.lookIn(t + 1);
		int value = card.value();
		
		if(value == 1){
			aceCounter++;
			totalPoints = totalPoints + 14;
		} else if(value >= 11 && value <= 13){
			totalPoints = totalPoints + 10;
		} else {
			totalPoints = totalPoints + value;
		}
	}
	
	while(totalPoints > 21 && aceCounter > 0){
		totalPoints = totalPoints - 13;
		aceCounter--;
	}
	
	return totalPoints;
}

#endif //PLAYER_H
