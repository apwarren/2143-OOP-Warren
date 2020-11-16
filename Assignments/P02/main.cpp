#include <iostream>
#include <chrono>
#include <thread>
#include "BlackJack.hpp"

using namespace std;

int main() {
    char playAgain;
    int decks;
    cout << "How many decks do you want to play with? ";
    cin >> decks;
    BlackJack Game(decks);
    Game.PrintBeginning();
    cin >> playAgain;
    Game.Deal();
    if(!Game.quit())
    {
    cout << "\nDo you want to play again? (y/n)\n";
    cin >> playAgain;
    }
    while((playAgain == 'y' || playAgain == 'Y') && !Game.quit())
    {
      Game.Deal();
       chrono::milliseconds dura( 1500 );
       this_thread::sleep_for( dura );
      if(!Game.quit())
      {
        cout << "Do you want to play again? (y/n)\n";
        cin >> playAgain;
      }
    }    
}
