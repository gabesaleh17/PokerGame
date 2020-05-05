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
#include <deque>


class Deck : public Card
{

 public:
    std::deque<Card> m_deck;
    Deck();
    void shuffle();
    void swapCards(Card& card1, Card& card2);
    Card dealCard();
    
};

#endif /* Deck_h */
