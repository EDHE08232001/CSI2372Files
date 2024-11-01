#ifndef PLAYER_H
#define PLAYER_H

#include "CardsSet.h"
#include <iostream>

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

/* Play method: player draws cards and decides whether to continue */
int Player::play()
{
	// **Change:** Clear the player's hand at the start of each game
	inHand.empty();

	char choicePicked;
	int totalScore = 0;

	do
	{
		// Take a card from the packet and put it in hand
		Card card = packet.take();
		inHand.put(card);

		if (!computer)
		{
			// If it's the user, display the card drawn
			std::cout << "You get Card: ";
			card.write();
			totalScore = countPoints();
			std::cout << "Your score is " << totalScore << " points" << std::endl;

			// Check if user has lost
			if (totalScore > 21)
			{
				break;
			}

			// Ask user if they want another card
			std::cout << "Any additional Card? (y/n) ";
			std::cin >> choicePicked;
		}
		else
		{
			// Computer's strategy: draw until score is at least 17
			totalScore = countPoints();

			// **Change:** Optional code to display computer's cards and score
			// Uncomment the following lines if you want to display computer's cards and scores during play
			/*
			std::cout << "Computer gets Card: ";
			card.write();
			std::cout << "Computer's score is " << totalScore << " points." << std::endl;
			*/

			if (totalScore > 21)
			{
				break;
			}
			choicePicked = (totalScore < 17) ? 'y' : 'n';
		}

	} while (choicePicked == 'y' || choicePicked == 'Y');

	return totalScore;
}

/* countPoints method: calculate the total points in hand */
int Player::countPoints()
{
	int totalPoints = 0;
	int aceCounter = 0;

	// **Change:** Adjusted loop indexing to match the corrected CardsSet::lookIn method
	// Loop through all cards in hand
	for (int t = 1; t <= inHand.numCards(); t++)
	{
		// **Change:** Corrected the indexing to start from 1
		Card card = inHand.lookIn(t);
		int value = card.value();

		if (value == 1)
		{
			aceCounter++;
			totalPoints += 14; // Initially count Ace as 14
		}
		else if (value >= 11 && value <= 13)
		{
			totalPoints += 10; // Face cards are worth 10 points
		}
		else
		{
			totalPoints += value; // Other cards are worth their face value
		}
	}

	// Adjust Aces from 14 to 1 if total points exceed 21
	while (totalPoints > 21 && aceCounter > 0)
	{
		totalPoints -= 13; // Change Ace from 14 to 1
		aceCounter--;
	}

	return totalPoints;
}

#endif // PLAYER_H
