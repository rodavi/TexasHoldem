
#pragma once

class Card
{
    public:
        Card(){};
        Card(char suit, char value):
        m_suit{suit}, m_value{value}{m_card[0]=m_suit; m_card[1]=m_value; m_card[2]='\0';}

        char* get(){return m_card;}
        char getSuit(){return m_suit;}
        char getValue(){return m_value;}

        void setCard(char suit, char value)
        {
            m_suit=suit; 
            m_value=value;
            

            m_card[0]=m_suit;
            m_card[1]=m_value;
            m_card[2]='\0';

        }

    private:

        char m_suit;
        char m_value;
        char m_card[3];
};