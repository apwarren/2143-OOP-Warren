## Program 02 - Blackjack
This program implements a game of BlackJack by encapsulating several different classes representing different aspects of the game such as cards, players, and 
a deck. The user can play against a dealer and other players with a starting amount of $1000 and play until they choose to quit or go bankrupt.

### Class Designs

#### Class Card
  - Description:
    - A class containing the type and value of a specific card. Each card gets assigned its identity of a value, rank, and suit. 
    - A default card is the "back side" of a card.
- Private:
   - Data: 
     - Value: How much the card is worth
     - Suit:  Heart, Spade, Diamond, Clover
     - Rank:  Numbers 2-9, Jack, Queen, King, Ace
- Public:
  - Methods:
     - SetValue:  Sets value of card
     - SetRank:   Gives the card its rank
     - SetSuit:   Sets the suit of the card
     - GetValue:  Returns value of card
     - isAce:     Returns true if card rank is Ace
     - Print:     Prints out card to screen
     - Operator<: Compares two card values
#### Class Deck
  - Description:
    - A class containing all instances of a card. 
    - It is in charge of shuffling and keeping track of all undealed cards.
  - Protected:
    - Data:
      - Cards:       An array containing all cards contained inside the deck as well as one extra card representing the back of a card.
      - DeckSize:    How many total cards are in deck + 1 extra
      - CurrentSize: How many cards are currently left in the deck
  - Public:
    - Methods:
      - Fill: Fills and intializes Cards in Deck
      - Shuffle: Places cards in random order
      - Deal:  Removes a card from the deck
      - IsEmpty: checks if deck is empty
      - Reset:  replaces deck with a new, completely filled	deck
      - cardBack: returns the card class representing back of a card
#### Class Hand
  - Description:
    - A class containing all instances of cards currently obtained by a specific player.
    - A subclass that inherits from the Deck class and is composed in the Player class.
  - Private:
    - Data:
      - Total: Sum of all card values within the hand
      - Cards: Array containing all cards the player has
      - Size: How many cards Player has
  - Public:
    - Methods:
      - getTotal: Returns Total sum of cards
      - Discard:  Removes a specific card
      - Sort:  Places cards in a specific order
      - Operator<: Compares Hand total to other Hands
      - Operator<<: Prints out all cards in Hand
 #### Class Player
   - Description:
     - A class containing the rules and behavior of a single player.
   - Private
     - Data:
       - Bank: How much money the player has
       - BetAmount: How much money the player is betting
     - Methods:
       - Win: Adds 2X Final Bet Amount to bank
       - Bet: Subtracts bet amount from bank
       - Bankrupt: Returns true if player bank is 0
       - DoubleDown: If Player intial hand total is 10 or 11, allows player chance to bet an extra $50
       - BlackJack:  If Player's initial hand total is 21, they automatically win 2.5X initial bet amount
   - Protected:
     - Data:
       - Hand: instance of all cards the player currently has
       - Name: Identifies the player
       - Active: Flag to determine if player is still playing current game or has called Stand
   - Public:
     - Methods:
       - Hit: Adds card to player hand
       - Bust: Player hand total is over 21. Player loses
       - Stand: Sets Active to false. Player is finished with hand
       - isActive: Returns Active. Gives the player's status
       - PrintHand:  Prints out all the cards that are in the player's hand
 #### Class Dealer
   - Description:
     - A subclass of a player with additional, exclusive rules. Acts as the game's dealer
     - The dealer only shows one of its initial cards and must keep hitting until its hand is above a certain value 
     - Does not have a bank
   - Private:
     - Data:
       - Name: Identifies the dealer
       - Hand: Instance of all the dealer's cards
       - Active: Determines current player status.
   - Public:
     - Methods:
       - Hit: Adds Card to Dealer's hand
       - UnderHit: Checks if hand total is under 17
       - Bust: Dealer hand goes over 21
       - BlackJack: If dealer gets a blackjack then all player's lose and next round begins
       - PrintDHand: Prints out all  current cards in dealer's hand except the first one. The first one prints out the "back" side of the card
       - PrintHand: Prints out all cards in dealer's hand. Reveals and prints dealer hand total.
      
 #### Class BlackJack_Game
   - Description:
     - A class in charge of implementing the rules of the BlackJack. 
     - It manages all Players (including the Dealer) and the deck. 
     - It determines the winner of each game and distributes winnings.
   - Private:
     - Data:
       - Deck: Sets how many cards can be played
       - Players: Array containing all players. The first index is always the Dealer
       - Quit: Flag to determine if user is done playing
       - Winner: Contains player with highest total under 22
       - Still: Keeps track of all players still in play and have not hit Stand. 
   - Public:
     - Methods:
       - Deal: Deals out cards for current round
       - Print: Prints out current state of game to console
       - nextRound: Issues all final tallies to the players and begins a new game when Still reaches 0
 #### Diagram
<img src="https://i.imgur.com/97LgO6j.png" width="900">
