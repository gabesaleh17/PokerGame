//
//  main.cpp
//  Poker
//
//  Created by Gabe Saleh on 4/26/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Card.h"
#include "Deck.h"

int main(int argc, const char * argv[])
{
    
    Deck newDeck;
    
    std::cout << "(" << newDeck.m_deck[0].getSuit() << "," << newDeck.m_deck[0].getValue() << ")" << std::endl;
    //std::cout << "(" << newDeck.m_deck[1].getSuit() << "," << newDeck.m_deck[1].getValue() << ")" << std::endl;
    newDeck.shuffle();
    //newDeck.swapCards(newDeck.m_deck[0], newDeck.m_deck[1]);
    
   std::cout << "(" << newDeck.m_deck[0].getSuit() << "," << newDeck.m_deck[0].getValue() << ")" << std::endl;
    //std::cout << "(" << newDeck.m_deck[1].getSuit() << "," << newDeck.m_deck[1].getValue() << ")" << std::endl;
    
}
