#pragma once
#include "Card.hpp"
#include <vector>

class Container {
protected:
	vector<Card *> cards; //Vector of all cards in the container
	unsigned int Size; //Size of all cards that can be played
public:
	Container(int numCard)
	{
		for (int i = 0; i < numCard; i++)
		{
			cards.push_back(new Card(i)); //Fills deck with uninitialized cards
		}
		Size = numCard;
	}
	void add(Card* card)
	{
		cards.push_back(card);
		Size++;
	}
	bool isEmpty()
	{
		return Size;
	}
	int size()
	{
		return Size;	//Get size of container
	}
  void Sort()
    {
       for(int i=0;i<size()-1;i++)
       {
        // Index "j"
        for(int j=i+1;j<size();j++)
        {
            //Comparing cards at position i and j 
            if(cards[i]->getPosition()%13 > cards[j]->getPosition()%13)
            {
                // standard swap 
                Card* temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
       }
    }
};