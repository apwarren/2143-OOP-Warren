#pragma once
#include "Hand.hpp"
#include <iostream>
using namespace std;

class Dealer : public Human
{
private:
  Card* temp; //Stores the first card of the dealer
  int handSum;
public:
  Dealer(Card* card1, Card* card2) : Human(card2)
  {
    Name = "Dealer";
    temp = card1;
    Cards.addSum(card1); //Add value of card1 to sum of hand value
  }
  bool underHit()
  {
    return (Cards.getTotal() < 17);
  }
  bool BlackJack()
  {
    if(Cards.getTotal() == 21)
    {
      return true; //Ends game if player gets a BlackJack
    }
    return false;
  }
  void revealBlank()
  {
    Cards.getCardFront(temp);
  }
};