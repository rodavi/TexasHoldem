#include "Card.hpp"
#include <vector>

#pragma once

class Deck
{
    public:
        Deck(){}

        bool addCard(Card card)
        {
            if(!isCard(card))
            {
                m_deck.push_back(card);
                return true;
            }
            return false;
        }

        bool isCard(Card card)
        {
            for(Card m_card : m_deck)
            {
                
                if(m_card.getSuit()==card.getSuit() && m_card.getValue()==card.getValue())
                {
                    return true;
                }
            }

            return false;
        }

        int getSize(){return m_deck.size();}
    private:
        std::vector<Card> m_deck;

};