#pragma once
#include "Hand.hpp"
#include <iostream>
using namespace std;
class Human
{
protected:
  Hand Cards;
  string Name;
  bool Active;
public:
  Human(Card* card1, Card* card2) : Cards(card1, card2)
  {
    Active = true;
    Bust(); //checks for two aces to not equal 22
  }
  Human(Card* card1) : Cards(card1)
  {
    Active = true; 
    Bust(); //checks for two aces to not equal 22

  }
  void Hit(Card* another) //Gives a card from deck
  {
    Cards.add(another);
    Cards.addSum(another);
    
  }
  void Stand()//Sets status to Stand
  {
    Active = false;
  }
  
  bool Bust()
  {
    if(Cards.getTotal() > 21)
    {
      Cards.changeAce();
      if(Cards.getTotal() > 21)
      {
      return true;
      }
      else //Did not bust
        return false;
      
    }
    return false;
  }
   int sum()
  {
    return Cards.getTotal();
  }
  bool isActive()//Gives the player's status
  {
    return Active;
  }
  void printHand()
  {
    Cards.PrintHand();
  }

};