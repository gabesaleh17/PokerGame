//
//  Deck.cpp
//  Poker
//
//  Created by Gabe Saleh on 4/27/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Deck.h"
#include <cmath>
#include <time.h>

Deck::Deck()
{
    //setting suits and values
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            m_deck[j+(13*i)].setSuit(static_cast<SuitType>(i));
            m_deck[j+(13*i)].setValue(static_cast<ValueType>(j));
            
            
        }
        m_deckSize++;
    }
    
}

void Deck::swapCards(Card& card1, Card& card2)
{
    Card tempCard;
    tempCard = card1;
    card1 = card2;
    card2 = tempCard;
    
}

void Deck::showCard(int index)
{
    
}

void Deck::shuffle()
{
    srand(time(NULL));
    
    for (int i = 0; i < 51; i++)
    {
        
        int randomNum = rand() % 52;
        swapCards(m_deck[i], m_deck[randomNum]);
        
    }
    
    
}
