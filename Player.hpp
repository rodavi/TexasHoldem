#include "Card.hpp"
#include <string>
#include <algorithm>

#pragma once

class Player
{
    private:
        Card m_one;
        Card m_two;
        std::vector<Card> m_cards;
        std::string m_name;

    public:
        Player(const std::string name):m_name{name}{}

        void addHand(Card one)
        {
            //m_one.setCard(one.getSuit(), one.getValue());
            //m_two.setCard(two.getSuit(), two.getValue());
            m_cards.push_back(one);
            //m_cards.push_back(two);
        }

        Card getHand(int i)
        {
            return m_cards[i];
        }

        std::string getName(){return m_name;}
        void setName(std::string name){m_name = name;}

};