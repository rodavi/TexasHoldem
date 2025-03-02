#include <vector>
#include "Player.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include "Deck.hpp"
#include <map>

#pragma once

class Game
{
    private:
        int m_n_players;
        std::vector<Player> m_players;
        std::map<std::string, std::vector<Card>> m_hands;
        Deck m_deck;

        bool addPlayer(std::string& name)
        {
            for(Player temp_player:m_players)
            {
                if(temp_player.getName()==name){return false;}
            }
            m_players.push_back(Player(name));
            return true;
        }

        Card dealCard()
        {
            bool state{false};

            int suit = std::rand()%4;
            int value = std::rand()%14;
            
            Card t_card(suit, value);
            //std::cout<<"-"<<suit<<value<<"\n";
            state = m_deck.isCard(t_card);
            while(state)
            {
                //std::cout<<"-"<<suit<<value<<" is repeated\n";
                int suit = std::rand()%4;
                int value = std::rand()%14;
                
                t_card.setCard(suit, value);
                state = m_deck.isCard(t_card);
            }
            m_deck.addCard(t_card);
            //std::cout<<"Added: "<<(int)t_card.getSuit()<<(int)t_card.getValue()<<"\n";
            return t_card;
        }

        void showHands()
        {
            for(int i=0;i<m_n_players;i++)
            {
                std::cout<<m_players[i].getName()<<" has an "<<m_players[i].getHand(0).getSuit()<<m_players[i].getHand(0).getValue()<<" and "<<m_players[i].getHand(1).getSuit()<<m_players[i].getHand(1).getValue()<<"\n";
            }
        }

    public:

        Game(int n_players):m_n_players{n_players}
        {
            std::string t_name;
            bool isCorrect{false};
            for(int i=0;i<m_n_players;i++)
            {
                std::cout<<"Player "<<i+1<<" name: ";
                std::cin>>t_name;
                isCorrect = addPlayer(t_name);
                while(!isCorrect)
                {
                    std::cout<<"Name is duplicated\n";
                    std::cout<<"Player "<<i+1<<" name: ";
                    std::cin>>t_name;
                    isCorrect = addPlayer(t_name);
                }
            }

            std::cout<<"The Game is about to start...\n";
            for(int i=0;i<m_n_players;i++)
            {
                m_players[i].addHand(dealCard());
                m_players[i].addHand(dealCard());
                //dealCard();
            }
            std::cout<<m_deck.getSize()<<"\n";

            showHands();
        }

        
};