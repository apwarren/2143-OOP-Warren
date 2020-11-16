#pragma once
#include "Hand.hpp"
#include "Human.hpp"
#include <iostream>
using namespace std;

class Player : public Human
{
private:
  static int Bank;
  int BetAmount;
  bool DoubledDown;
public:
  Player(Card* card1, Card* card2) : Human(card1, card2)
  {
    BetAmount = 100;
    Name = "Player ";
    DoubledDown = false;
  }
  void Bet()
  {
    Bank -= BetAmount;
  }
  void Win()
  {
    Bank += 2 * BetAmount;
  }
  void Tie()
  {
    Bank += BetAmount;
  }
  bool Bankrupt()
  {
    return !(Bank >= 100);
  }
  int getBank()
  {
    return Bank;
  }
  bool BlackJack()
  {
    if(Cards.getTotal() == 21 && Cards.size() == 2)
    {
      Bank += 250;
      return true; //Ends game if player gets a BlackJack
    }
    return false;
  }
   void DoubleDown()
  {
    if(Cards.size() == 2 && (Cards.getTotal() == 10 || Cards.getTotal() == 11 ))
    {
      //Allow for DoubleDown if player has enough money and has not already done so
      if(Bank >= 50 && !DoubledDown)
      {
      cout << "| D: Double Down | ";
      }
    } 
  }
  void chooseDD()//Player chooses to do a Double Down
  {
    DoubledDown = true; //Can no longer choose to Double Down now
    BetAmount += 50;
    Bank -= 50;
  }
  void sortHand()
  {
    Cards.Sort();
  }
  
};
 int Player :: Bank = 1000;