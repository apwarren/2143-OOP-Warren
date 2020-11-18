#pragma once
#include "Card.hpp"
#include "Container.hpp"
#include <iostream>
using namespace std;
class Hand : public Container
{
private:
	int sum;
public:
Hand(Card* card1): Container (2) //Initialize a deck of 52 cards
	{
    Card* blank = new Card(-1); //Acts as the back side of the first card
    cards[0] = blank;
    cards[1] = card1;
    sum = card1->getValue();
	}
	Hand(Card* card1, Card* card2): Container (2) //Initialize a deck of 52 cards
	{
    cards[0] = card1;
    cards[1] = card2;
    sum = card1->getValue() + card2 -> getValue();
	}
  
    int getTotal()
    {
        return sum;
    }
    void addSum(Card* another)
    {
      sum += another->getValue();
    }
    
  void getCardFront(Card* temp)
  {
    cards[0] = temp;
  }
  int size()
  {
    return cards.size();
  }
 void changeAce()
 {
   for(int i = 0; i < cards.size(); i++)
   {
     if(cards[i]->isAce() && cards[i]->getValue() != 1)
     {
     cards[i]->setValue(1);
     sum -= 10;
     }
   }
 }
Hand operator<(const Hand &rhs)
{
  if(this->sum < rhs.sum)
    return *this;
  //else
    return rhs;
}
  void PrintHand()//Print all cards in a player's deck
    {
      int counter = 0;
      while(counter < size())
      {
      //Print out all cards by rows of 5 if player has more than 5 cards
      if(size() - counter > 4)
      {
        cout << '\t';
          for(int j = 0; j < 5; j++)
          {
                cout << ".-----. ";
          }
            cout << endl;
            cout << '\t';
          for(int j = 0; j < 5; j++)
          {
                cout << "|" << cards[j + counter]->getRank() << ".-. | ";
          }
            cout << endl;
            cout << '\t';
            for(int j = 0; j < 5; j++)
            {
                cout << cards[j + counter]->cardMiddle(cards[j + counter]->getSuit()) << ' ';
            }
            cout << endl;
            cout << '\t';     
            for(int j = 0; j < 5; j++)
            {
                cout << "| '-'" << cards[j + counter]->getRank() << "| ";
            }
            cout << endl;
            cout << '\t';
            for(int j = 0; j < 5; j++)
            {
                cout << "`-----' ";
            }
            cout<< endl;
            counter += 5;
       }
        //end of more than 5 if statement
      else
      {
        cout << '\t';
        for(int i = counter; i < size(); i++)
          {
                cout << ".-----. ";
          }
            cout << endl;
            cout << '\t';
        for(int i = counter; i < size(); i++)
          {
                cout << "|" << cards[i]->getRank() << ".-. | ";
          }
            cout << endl;
            cout << '\t';
        for(int i = counter; i < size(); i++)
            {
                cout << cards[i-1]->cardMiddle(cards[i]->getSuit()) << ' ';
            }
            cout << endl;
            cout << '\t';
        for(int i = counter; i < size(); i++)
            {
                cout << "| '-'" << cards[i]->getRank() << "| ";
            }
            cout << endl;
            cout << '\t';
        for(int i = counter; i < size(); i++)    
            {
                cout << "`-----' ";
            }
            cout<< endl;
            counter = size();
      }
    }
  }
};