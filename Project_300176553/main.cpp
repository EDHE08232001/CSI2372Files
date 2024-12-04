/**
 * @file main.cpp
 * @brief Main application file for the card game.
 *
 * This file contains the main function that initializes the game,
 * manages the game loop, and handles user interactions.
 */

#include "./headers/main.h"
#include <sstream>

using namespace std;

int main()
{
  // Display game and student information
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << " > CSI2372 Fall 2024 Project (Card Game)" << std::endl;
  std::cout << " > Student name : Edward He " << std::endl;
  std::cout << " > Student number: 300176553 " << std::endl;
  std::cout << " > Student name : Teodora Vukojevic " << std::endl;
  std::cout << " > Student number: 300199584 " << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std::endl;

  // Variables for player names and winner
  std::string p1_name;
  std::string p2_name;
  std::string winner_name;

  // Initialize game components
  const int MAX_NUM_PLAYER = 2;
  Player *p1 = nullptr;
  Player *p2 = nullptr;
  Player *pArr[MAX_NUM_PLAYER]; // Array of player pointers
  DiscardPile *dp = new DiscardPile();
  CardFactory *cf = CardFactory::getFactory();
  Deck *deck = nullptr;
  TradeArea *trAr = new TradeArea();
  Table *tb = nullptr;

  char user_input[2];
  bool savedGame = false;

  // Ask user if they want to reload a saved game
  std::cout << " >> Do you want to reload a saved game? (y/n)" << std::endl;
  std::cin >> user_input;

  if (user_input[0] == 'y')
  {
    // Reload game from saved files
    savedGame = true;
    tb = new Table(*p1, *p2, *dp, *trAr, *deck, *cf);

    // Reload deck
    tb->reloadDeck();
    deck = tb->getDeck();

    // Reload players
    tb->reloadPlayer(1);
    tb->reloadPlayer(2);

    p1 = tb->getPlayer(0);
    p2 = tb->getPlayer(1);

    // Reload discard pile
    tb->reloadDiscardPile();
    dp = tb->getDiscardPile();

    // Reload trade area
    tb->reloadTradeArea();
    trAr = tb->getTradeArea();
  }
  else
  {
    // Start a new game
    std::cout << std::endl;
    std::cout << " >> Enter the name of the first player: ";
    std::cin >> p1_name;
    std::cout << std::endl;
    std::cout << " >> Enter the name of the second player: ";
    std::cin >> p2_name;
    std::cout << std::endl;

    // Create new players
    p1 = new Player(p1_name);
    p2 = new Player(p2_name);

    pArr[0] = p1;
    pArr[1] = p2;

    // Initialize the table with the players and game components
    deck = cf->getDeck();
    tb = new Table(*p1, *p2, *dp, *trAr, *deck, *cf);

    dp = tb->getDiscardPile();
    trAr = tb->getTradeArea();

    std::cout << " > Initializing each player with 5 cards." << std::endl;
    std::cout << " > Current size of the deck: " << deck->size() << std::endl;

    // Deal 5 cards to each player
    for (int player = 0; player < MAX_NUM_PLAYER; player++)
    {
      for (int card = 0; card < 5; card++)
      {
        pArr[player]->takeCard(deck->draw());
      }
    }
  }

  // Game loop
  while (deck->size() != 0)
  {
    std::cout << " > -------------------------------------------" << std::endl;
    std::cout << " > Types:\nB: Blue\nC: Chili\nS: Stink\nG: Green\ns: Soy\nb: "
                 "black\nR: Red\ng: garden"
              << std::endl;

    std::cout << "Number of cards left in Deck: " << deck->size() << std::endl;
    std::cout << std::endl
              << ">>>>>>>>>>> Do you want to pause and save the game? (y/n)"
              << std::endl;
    std::cin >> user_input;
    if (user_input[0] == 'y')
    {
      // Save the game state
      tb->saveTable();
      std::cout << " > Game saved. Bye." << std::endl;
      break;
    }
    else
    {
      // Proceed with the game
      for (int i = 0; i < MAX_NUM_PLAYER; i++)
      {
        // Display table information
        std::cout << std::endl
                  << ">>>> Table information: <<<<" << std::endl
                  << std::endl
                  << *tb << std::endl;

        // Player's turn
        std::cout << std::endl;
        std::cout << ">>>> Player " << i + 1 << " turn." << std::endl;
        std::cout << std::endl;

        Player *p = tb->getPlayer(i); // Get the current player

        std::cout << " > Drawing top card from deck..." << std::endl;
        // Player draws top card from Deck
        p->takeCard(deck->draw());

        std::cout << std::endl
                  << " > Player " << i + 1 << " Hand: " << std::endl;
        p->printHand(std::cout, true);
        std::cout << std::endl;

        // Add bean cards from the TradeArea to chains or discard them
        if (trAr->numCards() > 0)
        {
          bool cardAdded = false;
          // Iterate over the cards in the trade area
          for (Card *card : trAr->getListOfCards())
          {
            cardAdded = false;
            // Check if the player has a chain that matches the card
            for (Chain_Base *chain : *(p->getChains()))
            {
              if (card->getName() == chain->getChainType())
              {
                *chain += trAr->trade(card->getName());
                cardAdded = true;
                break;
              }
            }

            // Discard the card to the discard pile if it was not added
            if (!cardAdded)
            {
              std::cout << " >> Card: ";
              card->print(std::cout);
              std::cout << " added to the discard pile." << std::endl;
              *dp += trAr->trade(card->getName());
            }
          }
        }

        // Play topmost card from Hand
        if (p->getHand()->numCards() > 0)
        {
          std::cout << std::endl
                    << " > Playing topmost card from Hand ("
                    << p->getHand()->top()->getName()[0] << ")" << std::endl;
          p->playCard();

          std::cout << std::endl
                    << *p << std::endl;

          std::cout << std::endl
                    << " > Player " << i + 1 << " Hand: " << std::endl;
          p->printHand(std::cout, true);
          std::cout << std::endl;
        }

        std::cout
            << std::endl
            << " >> Play topmost card? (y) or Discard card to Discard Pile? (n)"
            << std::endl;

        std::cin >> user_input;

        if (user_input[0] == 'y')
        {
          if (p->getHand()->numCards() > 0)
          {
            std::cout << " > Playing topmost card from Hand ("
                      << p->getHand()->top()->getName()[0] << ")" << std::endl;
            p->playCard();

            std::cout << std::endl
                      << *p << std::endl;

            std::cout << std::endl
                      << " > Player " << i + 1 << " Hand: " << std::endl;
            p->printHand(std::cout, true);
            std::cout << std::endl;
          }
          else
          {
            std::cout << " > No cards left in hand to play." << std::endl;
          }
        }
        else
        {
          int idx;
          Card *card = nullptr;
          // Show the player's full hand
          std::cout << std::endl
                    << " > Player " << i + 1 << " Hand: " << std::endl;
          p->printHand(std::cout, true);

          std::cout << " > Current size of the hand: " << p->getNumCards()
                    << std::endl;
          std::cout
              << " >> Enter the index of the card you would like to remove: "
              << std::endl;
          std::cin >> idx;

          // Remove the specified card from the hand
          try
          {
            card = p->removeCard(idx);
          }
          catch (const std::out_of_range &e)
          {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
          }

          // Add the card to the discard pile
          if (card != nullptr)
          {
            std::cout << " >> Card: ";
            card->print(std::cout);
            std::cout << " added to the discard pile." << std::endl;
            *dp += card;
          }
        }

        // Draw three cards from the deck and place them in the trade area
        std::cout << std::endl
                  << ">>>> Drawing three cards from the deck to the trade area."
                  << std::endl
                  << std::endl;
        for (int drw = 0; drw < 3; drw++)
        {
          if (deck->size() > 0)
            *trAr += (deck->draw());
        }

        std::cout << " > Trade Area: " << *trAr << std::endl;

        // Move matching cards from the discard pile to the trade area
        if (dp->size() > 0)
        {
          while (trAr->legal(dp->top()))
          {
            // Draw the top-most card from the discard pile and place it in the
            // trade area
            *trAr += (dp->pickUp());
          }
        }

        std::cout << std::endl;

        // Allow the player to add cards from the trade area to their chains
        std::list<Card *> tradeCards = trAr->getListOfCards();
        for (auto it = tradeCards.begin(); it != tradeCards.end();)
        {
          Card *card = *it;
          std::cout << std::endl
                    << " >> Do you want to chain the card [";
          card->print(std::cout);
          std::cout << "]? (y/n)" << std::endl;
          std::cin >> user_input;

          if (user_input[0] == 'y')
          {
            // Chain the card
            p->playCard(trAr->trade(card->getName()), true);

            std::cout << std::endl
                      << *p << std::endl;

            std::cout << std::endl
                      << " > Player " << i + 1 << " Hand: " << std::endl;
            p->printHand(std::cout, true);
            std::cout << std::endl;

            it = tradeCards.erase(it);
          }
          else
          {
            std::cout << std::endl
                      << " > Card left in the trade area." << std::endl;
            ++it;
          }
        }

        // Draw two cards from the deck and add them to the player's hand
        for (int j = 0; j < 2; j++)
        {
          if (deck->size() > 0)
            p->takeCard(deck->draw());
        }

        std::cout << std::endl
                  << "> Player " << i + 1 << " Hand: " << std::endl;
        p->printHand(std::cout, true);
        std::cout << std::endl;

        std::cout << std::endl
                  << "> Discard Pile all cards: ";
        dp->print(std::cout);
        std::cout << std::endl;
      }
    }
  } // End of game loop

  if (deck->size() == 0)
  {
    // Display final table information and determine the winner
    std::cout << std::endl
              << ">>>> Table information: <<<<" << std::endl
              << std::endl
              << *tb << std::endl;
    std::cout << "> No cards left in deck. Deck size = " << deck->size()
              << std::endl;
    if (tb->win(winner_name))
    {
      std::cout << std::endl
                << "> The winner is: " << winner_name << std::endl;
    }
    else
    {
      std::cout << std::endl
                << "> The game is a draw." << std::endl;
    }

    std::cout << "Game Ends" << std::endl;
  }

  // Clean up dynamically allocated memory
  delete dp;
  delete trAr;
  delete deck;
  delete tb;

  if (!savedGame)
  {
    delete p1;
    delete p2;
  }

  return 0;
}
