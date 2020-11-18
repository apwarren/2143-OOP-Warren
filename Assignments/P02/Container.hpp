#pragma once
#include "Card.hpp"
#include <vector>

/**
 * Container
 *
 * Description:
 *      A class that creates and holds instances of cards.
 * 		Container is the parent class for both the Deck and
 * 		the Hand classes. Cards are stored through the class
 * 		using a vector and also holds all overlapping functions
 * 		needed for both the deck and all hands. This class is short
 * 		but necessary.
 *
 * Public Methods:
 *      - Container(int)
 * 		- void add(Card* )
 * 		- bool isEmpty()
 * 		- int size()
 * 		- void Sort()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *  Container(52);			//Create instance of container
 * 	CardDeck.add(card12);	//Add a card to the back of the container
 * 	!CardDeck.isEmpty();	//Check to see if there are any cards in the container
 * 	CardDeck.size();		//Return how many cards are in the container
 * 	CardDeck.Sort();		//Sort the cards in the container by rank
 *
 */
class Container {

protected:				  //Accessible to Deck and Hand class also

	vector<Card *> cards; //Vector of all cards in the container
	unsigned int Size; 	  //Size of how many cards are created

public:

	Container(int numCard);
	void add(Card* card);
	bool isEmpty();
	int size();
  	void Sort();

};  //End of Container class definition

/**
* Container:
*
*    Constructor. Create desired number of uninitialized cards
*		and set the size to how many total cards exist.
*
* Params:
*    None
*
* Returns:
*     Void
* 
*/
Container :: Container(int numCard)
{
		//Create a new card until container reaches numCard size
	for (int i = 0; i < numCard; i++)
	{
		//Fills deck with uninitialized cards
		cards.push_back(new Card(i)); 
	}

		//Set the size of the container
	Size = numCard;

}//End of Container(int)

/**
* Public: add
*
*    Constructor. Create desired number of uninitialized cards
*		and set the size to how many total cards exist.
*
* Params:
*    None
*
* Returns:
*     Void
* 
*/
void Container :: add(Card* card)
{
		//Add a card to back of container
	cards.push_back(card);
		//Increment Size
	Size++;

}//End of add()

/**
* Public: isEmpty
*
*    This function checks to see if there are any cards in the
*		container. If there are no cards and the size is 0 the
*
* Params:
*    None
*
* Returns:
*     Void
* 
*/
	bool Container :: isEmpty()
	{
		return Size;
	}
	int Container :: size()
	{
		return Size;	//Get size of container
	}
    void Container :: Sort()
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
