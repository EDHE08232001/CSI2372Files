#include "headers/Main.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
    cout << "-------------------------------------------" << endl;
    cout << "(FALL2024) - CSI2372 -  Project (Card Game)" << endl;
    cout << " > Student name : Student 1 " << endl;
    cout << " > Student number: #1 " << endl;
    cout << " > Student name : Student 2 " << endl;
    cout << " > Student number: #2 " << endl;
    cout << "-------------------------------------------" << endl << endl;

    string player1Name, player2Name, winner_name;

    const int MAX_NUM_PLAYER = 2;
    Player *player1 = nullptr;
    Player *player2 = nullptr;
    DiscardPile *discardp = new DiscardPile;
    CardFactory *cardf = CardFactory::getFactory();
    Deck *deck = nullptr;
    TradeArea *trAr = new TradeArea;
    Table *tb = nullptr;

    char user_input[2];

    cout << "Do you want to reload a game?(y/n)" << endl;
    cin >> user_input;

    if (user_input[0] == 'y') {
        tb = new Table(*player1, *player2, *discardp, *trAr, *deck, *cardf);
        tb->reloadDeck();
        deck = tb->getDeck();
        tb->reloadPlayer(1);
        tb->reloadPlayer(2);
        player1 = tb->getPlayer(1);
        player2 = tb->getPlayer(2);
        tb->reloadDiscardPile();
        discardp = tb->getDiscardPile();
        tb->reloadTradeArea();
        trAr = tb->getTradeArea();
        
    } 
	
	else {
        cout << "Enter the name of the first player: ";
        cin >> player1Name;
        cout << "Enter the name of the second player: ";
        cin >> player2Name;

        player1 = new Player(player1Name);
        player2 = new Player(player2Name);
        tb = new Table(*player1, *player2, *discardp, *trAr, *deck, *cardf);

        deck = tb->getDeck();

        cout << "Initializing each player with 5 cards." << endl;
        
        for (int playerID = 0; playerID < MAX_NUM_PLAYER; playerID++) {
            for (int card = 0; card < 5; card++) {
                (playerID == 0 ? player1 : player2)->takeCard(deck->draw());
            }
        }
    }

    while (deck->size() != 0) {
        cout << "Number of cards left in Deck: " << deck->size() << endl;
        cout << "Do you want to pause and save the game? (y/n)" << endl;
        cin >> user_input;

        if (user_input[0] == 'y') {
            tb->saveTable();
            cout << "Game saved. Bye." << endl;
            break;
        }

        for (int t = 0; t < MAX_NUM_PLAYER; t++) {
            cout << "\n>>>> Player " << t + 1 << " turn. " << endl;
            Player *p = tb->getPlayer(i);

            cout << "> Drawing top card from deck..." << endl;
            p->takeCard(deck->draw());
            cout << "> Player " << t + 1 << " Hand: " << endl;
            p->printHand(cout, true);

            if (trAr->numCards() > 0) {
                for (Card *card : trAr->getListOfCards()) {
                    bool cardAdded = false;
                    for (Chain_Base *chain : *(p->getChains())) {
                        if (card->getName() == chain->getChainType()) {
                            *chain += trAr->trade(card->getName());
                            cardAdded = true;
                        }
                    }
                    if (!cardAdded) {
                        cout << "> Card: ";
                        card->print(cout);
                        cout << " added to the discard pile." << endl;
                        *deckp += trAr->trade(card->getName());
                    }
                }
            }

            cout << "> Playing topmost card from Hand." << endl;
            p->playCard();
            cout << "> Player " << t + 1 << " Hand: " << endl;
            p->printHand(cout, true);

            cout << "> Play topmost card? (y) or discard to Discard Pile? (n)" << endl;
            cin >> user_input;
            if (user_input[0] == 'y') {
                cout << "> Playing topmost card from Hand." << endl;
                p->playCard();
            } else {
                int idx;
                Card *card = nullptr;
                while (!card) {
                    cout << "Enter the index of the card to remove: " << endl;
                    cin >> idx;
                    card = p->removeCard(idx);
                    if (!card) {
                        cout << "Invalid index. Please try again." << endl;
                    }
                }
                cout << "> Card: ";
                card->print(cout);
                cout << " added to the discard pile." << endl;
                *discardp += card;
            }

            cout << "Drawing three cards from the deck to the trade area." << endl;
            for (int drw = 0; drw < 3; drw++) {
                *trAr += deck->draw();
            }

            cout << "> Trade Area: " << *trAr << endl;
            while (discardp->size() > 0 && trAr->legal(discardp->top())) {
                *trAr += discardp->pickUp();
            }

            for (Card *card : trAr->getListOfCards()) {
                cout << "Do you want to chain the card [";
                card->print(cout);
                cout << "]? (y/n)" << endl;
                cin >> user_input;
                if (user_input[0] == 'y') {
                    p->playCard(trAr->trade(card->getName()), true);
                } else {
                    cout << "Card left in the trade area." << endl;
                }
            }

            for (int m = 0; m < 2; m++) {
                if (deck->size() > 0)
                    p->takeCard(deck->draw());
            }
            cout << "> Player " << m + 1 << " Hand: " << endl;
            p->printHand(cout, true);
        }
    }

    if (deck->size() == 0) {
        cout << "> No cards left in deck. Deck size = " << deck->size() << endl;
        tb->win(winner_name);
        cout << "> The winner is: " << winner_name << endl;
    }

    return 0;
};
