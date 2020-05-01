//
//  Deck.h
//  Poker
//
//  Created by Gabe Saleh on 4/27/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#ifndef Deck_h
#define Deck_h

#include "Card.h"


class Deck : public Card
{
private:
    
public:
    Deck();
    void shuffle();
    int getDeckSize();
    Card m_deck[52];
    int m_deckSize = 0;
    void showCard(int index);
    void swapCards(Card& card1, Card& card2);
    
};

#endif /* Deck_h */
