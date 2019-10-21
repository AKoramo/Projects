#include <iostream>
#include <vector>



struct PlayingCard 
{
  
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



    }

};


int main()
{

    bool game;
    char g;

    std::vector<> playerHand;
    std::vector<> dealerHand;

    //create deck DOES NOT WORK YET
    std::vector<PlayingCard, 52> Deck;
    
    for(int i = 0; i < 52; ++i)
        {
            PlayingCard card;
            card.value = // rand between 1 - 13;
            Deck[i] = card;
        }
       

    

    //intro
    std::cout << "Welcome to Single deck Blackjack!" << "\n" << "Press X to start a new game!\n";
    std::cin >> g;

    if(g == "x" || g == "X")
    {
        game = true;
      
    }
 
    //game
    while(game = true)
    {
        int playerValue;
        int dealerValue;
        bool playerTurn = false;
        bool dealerTurn ;

        //dealerturn1
        std::cout << "The dealer shuffles the deck!" << "\n" << "He draws one hidden card and: " << /*card2*/

        //add cards to dealer deck and check value 


        //playerturn1
        std::cout << "Your first card is: " << /****/ << "\n";

        playerTurn = true;
        dealerTurn = false;

        while(playerTurn == true)
        {
            char a = "";

            std::cout << "Your hand value is:" << /*playerhandvalue*/ << " and the dealer has: " << /*dealerhandvalue*/ <<"\n"; 
            std::cout << "Do you want to hit or stay? (y/n)";
            std::cin >> a;

            if(a = "y" || a = "Y")
            {
                //add card to playerHand and check value
                std::cout << "You draw: " << /*card*/ <<"\n";

                if(/*playerhandvalue*/ > 21)
                {
                    std::cout << "You went over 21!";
                    //losefunction
                }
                if(/*playerhandvalue*/ == 21)
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
    }


}