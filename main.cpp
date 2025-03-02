
#include <iostream>
//#include "Card.hpp"
//#include "Deck.hpp"
#include "Game.hpp"
#include <ctime>

int main()
{
    unsigned int seed;
    seed = static_cast<unsigned int>(std::time(NULL));
    std::srand(seed);
    
    Game game(3);

    bool full{false};

    /*Deck deck;
    Card c1('H', 'A');
    full = deck.addCard(c1);
    std::cout<<(full)<<std::endl;

    Card c2('D', 'T');
    full = deck.addCard(c2);
    std::cout<<(full)<<std::endl;

    Card c3('H', 'A');
    full = deck.addCard(c3);
    std::cout<<(full)<<std::endl;*/

    return 0;
}