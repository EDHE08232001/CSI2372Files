#ifndef PLAYER_H
#define PLAYER_H

#include "CardsSet.h"
#include <iostream>
using namespace std;

class Player
{
public:
	Player(CardsSet &cardPacket, bool isComputer) : packet(cardPacket), computer(isComputer) {}
	int play();

private:
	CardsSet inHand;	 // The player's hand of cards
	CardsSet &packet;	 // Reference to the common packet of cards
	const bool computer; // Indicates if this player is the computer
	int countPoints();	 // Calculates the total points in hand
};

/* play() method */
int Player::play()
{
	char choicePicked;
	int totalScore = 0;

	do
	{
		Card card = packet.take(); // Take a card from the packet
		inHand.put(card);		   // Add it to the player's hand

		cout << "You get Card: ";
		card.write(); // Display the card received

		totalScore = countPoints(); // Calculate the total score
		cout << "Your score is " << totalScore << " points" << endl;

		if (totalScore > 21)
		{
			cout << "You lost!" << endl;
			break;
		}

		if (!computer)
		{
			cout << "Any additional Card? (y/n) ";
			cin >> choicePicked;
		}
		else
		{
			// Computer strategy: take another card if totalScore is less than 17
			choicePicked = (totalScore < 17) ? 'y' : 'n';
		}
	} while (choicePicked == 'y' || choicePicked == 'Y');

	return totalScore;
}

/* countPoints() method */
int Player::countPoints()
{
	int totalPoints = 0;
	int aceCounter = 0;

	// Adjusted loop index and lookIn() call to match updated CardsSet::lookIn()
	// Original code:
	// for (int t = 0; t < inHand.numCards(); t++){
	//     Card card = inHand.lookIn(t + 1);
	//     int value = card.value();
	//     ...
	// }

	// Updated code:
	for (int t = 1; t <= inHand.numCards(); t++)
	{
		Card card = inHand.lookIn(t); // 'no' parameter starts from 1 for the top card
		int value = card.value();

		if (value == 1)
		{
			aceCounter++;
			totalPoints += 14; // Count Ace as 14 initially
		}
		else if (value >= 11 && value <= 13)
		{
			totalPoints += 10; // Face cards are worth 10 points
		}
		else
		{
			totalPoints += value; // Number cards are worth their face value
		}
	}

	// Adjust totalPoints if it exceeds 21 and there are Aces counted as 14
	while (totalPoints > 21 && aceCounter > 0)
	{
		totalPoints -= 13; // Change Ace from 14 to 1 by subtracting 13
		aceCounter--;
	}

	return totalPoints;
}

#endif // PLAYER_H
