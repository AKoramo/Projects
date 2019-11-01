#include <iostream>
#include <vector>
#include <random>
#include <algorithm>



struct PlayingCard 
{
    int suit = 0;
    int value = 0;

    void print()
    {
        if(value > 1 && value <= 10)
        {
            std::cout << value << " of ";
        }
        if (value == 1)
        {
            std::cout << "Ace of ";
        }
        if (value == 11)
        {
            std::cout << "Jack of ";
        }
        if (value == 12)
        {
            std::cout << "Queen of ";
        }
        if (value == 13)
        {
            std::cout << "King of ";
        }


        if(suit == 1)
        {
            std::cout << "Diamonds ";
        }
        if (suit == 2)
        {
            std::cout << "Hearts ";
        }
        if (suit == 3)
        {
            std::cout << "Spades ";
        }
        if (suit == 4)
        {
            std::cout << "Clubs ";
        }

    }

};



int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    bool game = false;
    char g;
    int playerValue = 0;
    int dealerValue = 0;

    std::vector<PlayingCard> playerHand;
    std::vector<PlayingCard> dealerHand;
    //create deck 
    std::vector<PlayingCard> Deck;

    for(int i = 1; i <= 4; ++i)
    {
        for(int s = 1; s <= 13; s++)
        {
            PlayingCard card;
            card.value = s;
            card.suit = i;
            Deck.emplace_back(card);
        }
    }

    //intro
   /* std::cout << "Welcome to Single deck Blackjack!" << "\n" << "Input X to start a new game!\n";
    std::cin >> g;

    if(g == "x" || g == "X")
    {
        game = true;
      
    }
 
    //game
    while(game = true)
    {
        
        bool playerTurn = false;
        bool dealerTurn = true;

        //dealerturn1
        std::shuffle(Deck.begin(), Deck.end(), gen);
        //Move 2 cards from deck to dealer hand and add their values to dealervalue 
        std::cout << "The dealer shuffles the deck!" << "\n" << "He draws one hidden card and: " << /*card2*/


        //playerturn1*/
      //  std::cout << "Your first card is: " << /****/ << "\n";

       /* playerTurn = true;
        dealerTurn = false;

        while(playerTurn == true)
        {
            char a = '';

            std::cout << "Your hand value is:" << playerValue << " and the dealer has: " << dealerValue <<"\n"; 
            std::cout << "Do you want to hit or stay? (y/n)";
            std::cin >> a;

            if(a = "y" || a = "Y")
            {
                //make function for checking value
                //add card to playerHand and check value
              //  std::cout << "You draw: " << /*card <<"\n";

              //  if(/*playerhandvalue > 21)
              /*  {
                    std::cout << "You went over 21!";
                    //losefunction
                }
              //  if(/*playerhandvalue*//* == 21)
                {
                    //win function

                }
            }

            if(a = "n" || a = "N")
            {
                playerTurn = false;
                dealerTurn = true;
            }

            else
            {
                std::cout << "Invalid input, please input Y or N \n";
            }
          
        }
    }*/


}