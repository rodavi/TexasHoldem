#include "Card.hpp"
#include <string>
#include <algorithm>

#pragma once

class Player
{
    private:
        Card m_one;
        Card m_two;

        std::string m_name;

    public:
        Player(const std::string name):m_name{name}{}

        void addHand(Card one, Card two)
        {
            m_one.setCard(one.getSuit(), one.getValue());
            m_two.setCard(two.getSuit(), two.getValue());
        }

        Card getHand(int i)
        {
            if(i==1){return m_one;}
            else if(i==2){return m_two;}
            else{return Card('N', 'N');}
        }

        std::string getName(){return m_name;}
        void setName(std::string name){m_name = name;}

};