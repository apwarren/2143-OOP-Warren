#pragma once
#include <iostream>
using namespace std;
class Card
{
private:
	int value;
	int Suit;
	char Rank;
  int Position; //Where it originally was in the deck
public:
	Card(int _position)
	{
		value = 0;
		Suit = 5;
		Rank = ' ';
    Position =  _position;
	}
	
	void setValue(int val)
	{
    val++;
		if (Rank == 'A')//card is an Ace-- starting value is 11
		{
			if (value == 11) //Already in play as 11 or already set to one
				value = 1; //Change to 1
			else //Set it to 11
				value = 11;
		}
		else if (val < 10)//If card is less than 10
			value = val;
		else
			value = 10;
	}
	void setRank(int _rank)
	{
		switch (_rank)
		{
		case 0:
			Rank = 'A';
			break;
		case 9:
			Rank = '0';
			break;
		case 10:
			Rank = 'J';
			break;
		case 11:
			Rank = 'Q';
			break;
		case 12:
			Rank = 'K';
			break;
		default:
			Rank = 49 + _rank;
			break;
		}
	}
	void setSuit(int _suit)
	{
		Suit = _suit + 1;
	}
	int getValue()
	{
		return value;
	}
	char getRank()
	{
		return Rank;
	}
	int getSuit()
	{
		return Suit;
	}
  int getPosition()
  {
    return Position;
  }
	bool isAce()
	{
		if (Rank == 'A')
			return true;
		return false;
	}
	void Print()
	{
		cout << ".-----.\n";
		cout << "|" << Rank << ".-. |\n";
		switch (Suit)
		{
		case 1://Club
			cout << "| :♣: |\n";
			break;
		case 2://Diamond
			cout << "| :♦: |\n";
			break;
		case 3://Heart
			cout << "| :♥: |\n";
			break;
		case 4://Spade
			cout << "| :♠: |\n";
			break;
		default://Back side of card
			cout << "| :/: |\n";
		}//end of switch case
		cout << "| '-'" << Rank << "|\n";
		cout << "`-----'" << endl;
	}//end of Print()

	string cardMiddle(int suit)
	{
		string middle;
		switch (suit)
		{
		case 1://Club
			cout << "| :♣: |";
			break;
		case 2://Diamond
			cout << "| :♦: |";
			break;
		case 3://Heart
			cout << "| :♥: |";
			break;
		case 4://Spade
			cout << "| :♠: |";
			break;
		default://Back side of card
			cout << "| :/: |";
		}
		return middle;
	}//end of printMiddle()

};

