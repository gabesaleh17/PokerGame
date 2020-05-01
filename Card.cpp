//
//  Card.cpp
//  Poker
//
//  Created by Gabe Saleh on 4/26/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Card.h"

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


