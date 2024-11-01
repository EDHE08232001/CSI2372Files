#include <iostream>
using namespace std;

#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

int main()
{
	CardsSet packet;
	Player you(packet, false); // Initialize player (user)
	Player me(packet, true);   // Initialize player (computer)
	char answer[3];
	bool continuous = true;

	cout << "Hello!" << endl;
	while (continuous)
	{
		cout << "A new game? (y/n) ";
		cin >> answer;
		continuous = answer[0] == 'y' || answer[0] == 'Y';
		if (continuous)
		{
			// Initialize and shuffle the packet of cards
			packet.novSet();
			packet.shuffle();

			int p1 = you.play(); // User plays

			if (p1 > 21)
			{
				cout << "You lost!" << endl;
			}
			else if (p1 == 21)
			{
				cout << "You won!" << endl;
			}
			else // Computer's turn
			{
				int p2 = me.play(); // Computer plays

				if (p2 <= 21 && p2 >= p1)
				{
					cout << "You lost!" << endl;
				}
				else
				{
					cout << "You won!" << endl;
				}
			}
		}
	}
	return 0;
}
