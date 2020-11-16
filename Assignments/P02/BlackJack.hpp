#pragma once
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

class BlackJack
{
private:
  Deck CardDeck;
  Player* player;
  Dealer* dealer;
  char playerOutput;
  bool Quit;
  int Activity;
  bool playerMoveOn;
  bool showDealerSum;
public:
BlackJack(int decks);
void Deal();
void resetGame();
void playerTurn();
void dealerTurn();
void noBust();
bool quit();
void Print();
void PrintBeginning();
};

 BlackJack :: BlackJack(int decks): CardDeck(decks * 52)
  {
    dealer = new Dealer(CardDeck.remove(), CardDeck.remove());
		player = new Player(CardDeck.remove(), CardDeck.remove());
    Activity = 3;
    playerMoveOn = false;
    showDealerSum = false;
    Quit = false;
  }
  void BlackJack :: Deal()
  {
    if(player->Bankrupt())
    {
      cout << "\n\nYou Are Out Of Money!!!\nGoodBye!";
      Quit = true;
    }

    else{
    //Player starts game
    player->Bet();
    Print();
    //Check for BlackJack
     if(player->BlackJack())
          {
          Print();
          cout << "BLACKJACK!!!!\n";
          Activity = 0;
          }
    //If no BlackJack then continue playing until everyone is finished with hand
    while(Activity > 0)
    {    
      if(player->isActive())
        playerTurn();
        //Dealer's turn
      if(dealer->isActive() && Activity > 1)
      {
        chrono::milliseconds dura( 1000 );
        this_thread::sleep_for( dura );
        dealerTurn();
      }

      if(Activity == 1) //Both Player and Dealer have Stood/ No Bust
          noBust();

    }//if Not bankrupt and Still Active loop    
  }
    resetGame();
}
void BlackJack :: resetGame()
{
    delete dealer;
    delete player;
    Activity = 3;
    dealer = new Dealer(CardDeck.remove(), CardDeck.remove());
		player = new Player(CardDeck.remove(), CardDeck.remove());
    showDealerSum = false;
    playerMoveOn = false;
}
void BlackJack :: playerTurn()
{
          while(!playerMoveOn)
          {
          player->DoubleDown();
          cout << "H: Hit | S: Stand | R: Show Deck | Q: Quit | A: Sort Hand" << endl;
          cin >> playerOutput;
          switch(playerOutput)
          {
            case 'D': case 'd':
            player->chooseDD();
            Print();
             break;
            case 'H': case 'h': 
            player->Hit(CardDeck.remove());
            Print();
            playerMoveOn = true;
            break;
            case 'S': case 's':
            player->Stand();
            Activity--;
            playerMoveOn = true;
            break;
            case 'A': case 'a':
             player->sortHand();
             Print();
            break;
            case 'R': case 'r':
            CardDeck.PrintDeck();
            cout << "Press enter any key and hit enter to return to game\n";
            cin >> playerOutput;
            Print();
            break;
            case 'Q': case 'q':
            Activity = 0;
            Quit = true;
            playerMoveOn = true;
            break;
          }//end of switch(playerOutput)
          }//player has made choice
           if(player->Bust())
          {
          player->Stand();
          Activity=0;
          cout << "\nYou Busted!\tYou Lose!\n";
          }
          else
          {
            if(!Quit)
            Print();
            if(dealer->isActive())
            cout << "Dealer is Playing. . .\n";
            else
            cout << "Your Move.\n";
          }
          playerMoveOn = false;
}
void BlackJack :: dealerTurn()
{
      if(!dealer->Bust())
      {
         if(dealer->underHit())
          {
            dealer->Hit(CardDeck.remove());
            if(dealer->Bust())
            {
            player->Win();
            showDealerSum = true;
            dealer->revealBlank(); //Flip over the first card
            Print();   //Show Full Dealer Hand
            cout << "Dealer Busts!\t You Win!\n";
            Activity = 0;
            }
            else
            {
             Print(); 
            }
          }
        else
        {
          Print();
          cout << "Dealer has Stood.\n";
          dealer->Stand();
          Activity--;
        }
      }
      else{
            player->Win();
            showDealerSum = true;
            dealer->revealBlank(); //Flip over the first card
            Print();   //Show Full Dealer Hand
            cout << "Dealer Busts!\t You Win!\n";
            Activity = 0;
      }
}
void BlackJack :: noBust()
{
  showDealerSum = true;
        dealer->revealBlank(); //Flip over the first card
        if(player->sum() > dealer->sum())// Player Wins
        {
          player->Win();
          Print();
          cout<< "YOU WIN!\n";
        }
        else if(player->sum() == dealer->sum()) //It's a tie
        {
          player->Tie();
          Print();
          cout << "It's a Tie!\n";

        }
        else //Player lost
        {
          Print();
          cout << "Dealer Was Highest!\tYou Lose!\n";
        }
        Activity--;
}
bool BlackJack:: quit()
{
  return Quit;
}
    
  
  void BlackJack :: Print()
  {
//Print out beginning of game
cout << "\n\n\n\n\n\n\n\n\n";
cout << "██████  ██       █████   ██████ ██   ██      ██  █████   ██████ ██   ██\n";
cout << "██   ██ ██      ██   ██ ██      ██  ██       ██ ██   ██ ██      ██  ██\n";
cout << "██████  ██      ███████ ██      █████        ██ ███████ ██      █████\n";
cout << "██   ██ ██      ██   ██ ██      ██  ██  ██   ██ ██   ██ ██      ██  ██\n";
cout << "██████  ███████ ██   ██  ██████ ██   ██  █████  ██   ██  ██████ ██   ██\n"; 
cout << endl;
cout << "  ___  ___   _   _    ___ ___\n";
cout << " |   \\| __| /_\\ | |  | __| _ \\\n";
cout << " | |) | _| / _ \\| |__| _||   /\n";
cout << " |___/|___/_/ \\_\\____|___|_|_\\\n";
cout << endl;
dealer->printHand();
if(showDealerSum)
cout << "\t\tDealer Total: " << dealer->sum();
cout << endl;
cout << endl;
cout << "  ___ _      ___   _____ ___\n";
cout << " | _ \\ |    /_\\ \\ / / __| _ \\\n";
cout << " |  _/ |__ / _ \\ V /| _||   /\n";
cout << " |_| |____/_/ \\_\\_| |___|_|_\\\n";
cout << endl;
player->printHand();
cout << "\t\tPlayer Total: "<< setw(2) << player->sum();
cout << "\n\nBank: " << setw(4) << player->getBank();
cout << "\n\n";
}
void BlackJack :: PrintBeginning()
{
 cout << "██████  ██       █████   ██████ ██   ██      ██  █████   ██████ ██   ██\n";
cout << "██   ██ ██      ██   ██ ██      ██  ██       ██ ██   ██ ██      ██  ██\n";
cout << "██████  ██      ███████ ██      █████        ██ ███████ ██      █████\n";
cout << "██   ██ ██      ██   ██ ██      ██  ██  ██   ██ ██   ██ ██      ██  ██\n";
cout << "██████  ███████ ██   ██  ██████ ██   ██  █████  ██   ██  ██████ ██   ██\n"; 
cout << endl;
cout << "  ___  ___   _   _    ___ ___\n";
cout << " |   \\| __| /_\\ | |  | __| _ \\\n";
cout << " | |) | _| / _ \\| |__| _||   /\n";
cout << " |___/|___/_/ \\_\\____|___|_|_\\\n";
cout << endl;
cout << endl;
cout << "\n\n\n\n\n";
cout << endl;
cout << "  ___ _      ___   _____ ___\n";
cout << " | _ \\ |    /_\\ \\ / / __| _ \\\n";
cout << " |  _/ |__ / _ \\ V /| _||   /\n";
cout << " |_| |____/_/ \\_\\_| |___|_|_\\\n";
cout << endl;
cout << "\n\n\n\n\n";
cout<< endl;
cout << "Total: --";
cout << "\n\nBank: " << player->getBank();
cout << "\n";
cout << "\n\t\t| Press Any Key To Begin Playing |" << endl;
}