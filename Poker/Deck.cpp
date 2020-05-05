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
            Card newCard;
            newCard.setSuit(static_cast<SuitType>(i));
            newCard.setValue(static_cast<ValueType>(j));
            m_deck.push_back(newCard);
            
            
        }
        
    }
    
}

void Deck::swapCards(Card& card1, Card& card2)
{
    Card tempCard;
    tempCard = card1;
    card1 = card2;
    card2 = tempCard;
    
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

Card Deck::dealCard()
{
    Card topCard;
    topCard = m_deck[0];
    m_deck.pop_front();
    return topCard;
}
