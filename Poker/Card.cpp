//
//  Card.cpp
//  Poker
//
//  Created by Gabe Saleh on 4/26/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Card.h"
#include <string>

Card::Card()
{
}

void Card::setSuit(SuitType suit)
{
    m_suit = suit;
}

void Card::setValue(ValueType value)
{
    m_value = value;
}

SuitType Card::getSuit()
{
    return m_suit;
}

ValueType Card::getValue()
{
    return m_value;
}

void Card::showCard()
{
    std::string outputString = "[";
    
    switch(m_value)
    {
        case 0: outputString += "Ace of ";
                break;
        case 1: outputString += "Two of ";
                break;
        case 2: outputString += "Three of ";
                break;
        case 3: outputString += "Four of ";
                break;
        case 4: outputString += "Five of ";
                break;
        case 5: outputString += "Six of ";
                break;
        case 6: outputString += "Seven of ";
                break;
        case 7: outputString += "Eight of ";
                break;
        case 8: outputString += "Nine of ";
                break;
        case 9: outputString += "Ten of ";
                break;
        case 10: outputString += "Jack of ";
                 break;
        case 11: outputString += "Queen of ";
                 break;
        case 12: outputString += "King of ";
                 break;
    }
    
    switch(m_suit)
    {
        case 0: outputString += "Hearts]";
                break;
        case 1: outputString += "Diamonds]";
                break;
        case 2: outputString += "Spades]";
                break;
        case 3: outputString += "Clubs]";
                break;
    }
    
    std::cout << outputString << std::endl;
}
