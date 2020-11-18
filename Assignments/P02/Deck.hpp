#pragma once
#include "Card.hpp"
#include "Container.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
class Deck : public Container
{
private:
	int OriginalSize;
public:
	Deck(): Container (52) //Initialize a deck of 52 cards
	{
    OriginalSize = 52;
		Fill();//Fill Deck with cards
    Shuffle();
	}
	Deck(int GivenSize): Container (GivenSize)
	{
    OriginalSize = GivenSize;
		Fill();//Fill Deck with cards
    Shuffle();
	}
	void Fill()
	{
		//Fill Deck with cards 
		for(int i = 0; i < size(); i++)//Fills deck with initialized cards
		{
			cards[i]->setRank(i % 13); //Sets the Rank of the Card From Ace - King
			cards[i]->setValue(i % 13); //Sets all card values from 1 - 10
			cards[i]->setSuit( (i / 13) % 4); //Sets the suit from 1-4 each representing a suit
		}
	}//end of Fill()
  
  
  Card* remove()
	{
    if(Size == 0) //Reset the deck if it has run out of cards
      reset();

		Card* temp = cards[Size - 1]; //Store card to be removed
		cards.pop_back();	//Remove card from container
		Size--;		//Decrement size of container
		return temp; //Return removed card
	}
    void reset()
    {
        Size = OriginalSize;
        for (int i = 0; i < Size; i++)
        {
			      cards.push_back(new Card(i)); //Fills deck with uninitialized cards
        } 
        Fill();
        Shuffle(); //ReShuffle the deck
    }
    void Shuffle()
    {
      int j;
      srand(time(0)); 
       for (int i=0; i<size() ;i++) 
        { 
        // Random for remaining positions. 
         j = (rand() % size()); 
        Card* temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
        } 
    }
    

    void PrintDeck()//Print 13 cards on one line
    {
       int counter = 0;
       Sort(); //Sort the deck to print
      while(counter < size())
      {
      //Print out all cards by rows of 13, each row is one suit
      if(size() - counter > 12)
      {
          for(int j = 0; j < 13; j++)
          {
                cout << ".-----. ";
          }
            cout << endl;
          for(int j = 0; j < 13; j++)
          {
                cout << "|" << cards[j + counter]->getRank() << ".-. | ";
          }
            cout << endl;
            for(int j = 0; j < 13; j++)
            {
                cout << cards[j + counter]->cardMiddle(cards[j + counter]->getSuit()) << ' ';
            }
            cout << endl;
            for(int j = 0; j < 13; j++)
            {
                cout << "| '-'" << cards[j + counter]->getRank() << "| ";
            }
            cout << endl;
            for(int j = 0; j < 13; j++)
            {
                cout << "`-----' ";
            }
            cout<< endl;
            counter += 13;
       }
        //end of more than 5 if statement
      else
      {
        for(int i = counter; i < size(); i++)
          {
                cout << ".-----. ";
          }
            cout << endl;
        for(int i = counter; i < size(); i++)
          {
                cout << "|" << cards[i]->getRank() << ".-. | ";
          }
            cout << endl;
        for(int i = counter; i < size(); i++)
            {
                cout << cards[i-1]->cardMiddle(cards[i]->getSuit()) << ' ';
            }
            cout << endl;
        for(int i = counter; i < size(); i++)
            {
                cout << "| '-'" << cards[i]->getRank() << "| ";
            }
            cout << endl;
        for(int i = counter; i < size(); i++)    
            {
                cout << "`-----' ";
            }
            cout<< endl;
            counter = size();
      }
    }
    Shuffle(); //Reshuffle the deck after printing it
  }
};