#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctype.h>



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

int gameStart()
{
    char g;

    std::cout << "Input S to (S)tart a new game or you can (E)xit with E";

    std::cin >> g;

    while(g != 's' || g != 'S')
    {
        if(isalpha(g) && (g == 's' || g == 'S'))
        {
            return 1;
        }
        if(isalpha(g) && (g == 'e' || g == 'E'))
        {
            return 2;
        }
        else
        {
            std::cout << "Invalid input, please input S for new game or E to exit. \n";
            std::cin >> g;
        }
    }

}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    bool game = false;

   
    

    //intro
    std::cout << "\n\n" << "Welcome to Single deck Blackjack!" << "\n\n";

    int x = gameStart();
    if(x == 1)
    {
        game = true;
    }
    if(x == 2)
    {
        return 0;
    }

    //game
    while(game = true)
    {
        std::vector<PlayingCard> Deck;
        std::vector<PlayingCard> playerHand;
        std::vector<PlayingCard> dealerHand;

        bool playerTurn = false;

        int holeValue = 0;
        int playerValue = 0;
        int dealerValue = 0;

        //Create and shuffle the deck
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

        std::shuffle(Deck.begin(), Deck.end(), gen);

        std::cout << "\n" << "The dealer shuffles the deck!" << "\n" << "He deals your first card ";

        Deck[0].print();
        playerHand.emplace_back(Deck[0]);
        playerValue += Deck[0].value;
        Deck.erase(Deck.begin());

        std::cout << "\n" << "He deals himself ";

        Deck[0].print();
        dealerHand.emplace_back(Deck[0]);
        dealerValue =+ Deck[0].value;
        Deck.erase(Deck.begin());

        std::cout << "and a hidden hole card. \n\n";

        dealerHand.emplace_back(Deck[0]);
        holeValue =+ Deck[0].value;
        Deck.erase(Deck.begin());
        

        
        for(auto w : dealerHand)
        {
            w.print();
        }
        //playerturn1
        bool playerTurn = true;
        bool stay = false;
       
        while(playerTurn == true)
        {
            char a = '';

            std::cout << "Your hand value is:" << playerValue << " and the dealer has: " << dealerValue
            <<" with the hole card hidden." <<"\n\n"; 
            std::cout << "Do you want to (H)it or (S)tay?: ";
            std::cin >> a;

            if(isalpha(a) && (a = 'h' || a = 'H'))
            {
                std::cout << "\n" << "You get ";

                Deck[0].print();
                playerHand.emplace_back(Deck[0]);
                playerValue += Deck[0].value;
                Deck.erase(Deck.begin());
                
                std::cout << " and your current hand value is " << playerValue << "\n";

                //Check value for win or lose
                if(playerValue > 21)
                {
                    std::cout << "Bust! You went over 21 and lost the game! \n";
                    break;
                }
                if(playerValue == 21)
                {
                    std::cout << "BLACKJACK!! you got 21 and won the game!";
                    break;
                }
            }
            if(isalpha(a) && (a = 's' || a = 'S'))
            {
                stay = true;
                std::cout << "You stay with your hand: ";
                for(auto c : playerHand)
                {
                    c.print();
                }
                std::cout << "\n" << "with total value of " << playerValue << "\n\n";
                break;
            }
            else
            {
                std::cout << "Invalid input, please input H or S \n";
            }
          
        }

        if(stay == true)
        {
            

            std::cout << "The dealer reveals the hole card and his hand is: ";
            for(auto d : dealerHand)
            {
                d.print();
            }
            dealerValue =+ holeValue;

            std::cout << "\n" << "with total value of " << dealerValue << "\n";

            //Dealer checks for win, lose or draws more cards
            while(true)
            {
                if(dealerValue > 21)
                {
                    std::cout << "The dealer went over 21 and lost. Congratulations!!";
                    break;
                }
                if(dealerValue == 21)
                {
                    std::cout << "The dealer got BLACKJACK with 21, you lost!"
                    break;
                }
                if((dealerValue == playerValue)
                {
                    std::cout << "The dealer wins with a tie, you lost!";
                    break;
                }

            }


        }
        else
        {
            /* code */
        }
        
    }*/


}