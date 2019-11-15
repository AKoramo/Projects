#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctype.h>

struct PlayingCard 
{
    int suit = 0;
    int value = 0;
    std::vector<std::string> suits = {"Diamonds \n", "Hearts \n", "Spades \n", "Clubs \n"};

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
        std::cout << suits[suit];
    }
};

int gameStart()
{
    char g;
    std::cout << "\n" << "-------------------" << "\n";
    std::cout << "\nInput S to (S)tart a new game or you can (E)xit with E: ";
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

    //INTRO & GRAPHIC
    std::cout << "\n" << " _____ " << "\n" << "|A .  | _____" << "\n" << "| /.\\ ||A ^  | _____" << "\n" 
    << "|(_._)|| / \\ ||A _  | _____" << "\n" << "|  |  || \\ / || ( ) ||A_ _ |" << "\n" << "|____V||  .  ||(_'_)||( v )|" 
    << "\n" << "       |____V||  |  || \\ / |" << "\n" << "              |____V||  .  |" << "\n" << "                     |____V|" << "\n";

    std::cout << "\n\n" << "Welcome to Single deck Blackjack!" << "\n";

    int x = gameStart();
    if(x == 1)
    {
        game = true;
    }
    if(x == 2)
    {
        return 0;
    }

    //GAME
    while(game = true)
    {
        std::vector<PlayingCard> Deck;
        std::vector<PlayingCard> playerHand;
        std::vector<PlayingCard> dealerHand;

        int holeValue = 0;
        int playerValue = 0;
        int dealerValue = 0;

        //Create and shuffle the deck
        for(int i = 0; i <= 3; ++i)
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

        std::cout << "\n" << "-------------------" << "\n";
        std::cout << "\n" << "The dealer shuffles the deck!" << "\n" << "He deals your first card ";

        Deck[0].print();
        playerHand.emplace_back(Deck[0]);
        playerValue += Deck[0].value;
        Deck.erase(Deck.begin());

        std::cout << "\n" << "-------------------" << "\n";
        std::cout << "\n" << "He deals himself ";

        Deck[0].print();
        dealerHand.emplace_back(Deck[0]);
        dealerValue += Deck[0].value;
        Deck.erase(Deck.begin());

        std::cout << "and a hidden hole card. \n";

        dealerHand.emplace_back(Deck[0]);
        holeValue += Deck[0].value;
        Deck.erase(Deck.begin());
 
        //PLAYER'S TURN
        bool stay = false;
       
        while(true)
        {
            char a;
            std::cout << "\n" << "-------------------" << "\n\n";
            std::cout << "Your hand value is: " << playerValue << " and the dealer has: " << dealerValue
            <<" with the hole card hidden." <<"\n\n"; 
            std::cout << "Do you want to (H)it or (S)tay?: ";
            std::cin >> a;

            if(isalpha(a) && (a == 'h' || a == 'H'))
            {
                std::cout << "\n" << "-------------------" << "\n";
                std::cout << "\n" << "You get ";

                Deck[0].print();
                playerHand.emplace_back(Deck[0]);
                playerValue += Deck[0].value;
                Deck.erase(Deck.begin());

                //Check value for win or lose
                if(playerValue > 21)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "\n" << "Bust! You went over 21 and lost the game! \n";
                    break;
                }
                if(playerValue == 21)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "\n" << "BLACKJACK!! you got 21 and won the game!";
                    break;
                }
            }
            else if(isalpha(a) && (a == 's' || a == 'S'))
            {
                stay = true;
                std::cout << "\n" << "-------------------" << "\n";
                std::cout << "You stay with your hand: \n";
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
        //DEALERS TURN IF PLAYER STAYS
        if(stay == true)
        {
            
            std::cout << "The dealer reveals the hole card and his hand is: ";
            for(auto d : dealerHand)
            {
                d.print();
            }

            dealerValue += holeValue;

            std::cout << "\n" << "with total value of " << dealerValue << "\n";

            //Dealer checks for win, lose or draws more cards
            while(true)
            {
            
                if(dealerValue > 21)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "The dealer went over 21 and lost. Congratulations!!";
                    break;
                }
                if(dealerValue == 21)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "The dealer got BLACKJACK with 21, you lost!";
                    break;
                }
                if(dealerValue == playerValue)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "The dealer wins with a tie, you lost!";
                    break;
                }
                if(dealerValue > playerValue)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "The dealer wins the game with hand value of " << dealerValue << " against your " << playerValue;
                    break;
                }
                if(dealerValue < playerValue)
                {
                    std::cout << "\n" << "-------------------" << "\n";
                    std::cout << "The dealer draws ";
                    Deck[0].print();
                    std::cout << "\n";
                    dealerHand.emplace_back(Deck[0]);
                    dealerValue += Deck[0].value;
                    Deck.erase(Deck.begin());
                    
                }
            }
        }

        x = gameStart();
        if(x == 1)
        {
            continue;
        }
        if(x == 2)
        {
            break;
        }
    }

    if(x == 2)
    {
        return 0;
    }

}