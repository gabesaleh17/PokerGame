//
//  Card.h
//  Poker
//
//  Created by Gabe Saleh on 4/27/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#ifndef Card_h
#define Card_h
#include <map>
#include <string>
#include <iostream>
#include <cmath>

enum SuitType {Hearts = 0, Diamonds = 1, Spades = 2, Clubs = 3};
enum ValueType {ace = 0, two = 1, three = 2, four = 3, five = 4, six = 5, seven = 6, eight = 7, nine = 8, ten = 9, jack = 10, queen = 11, king = 12};

class Card
{
public:
    Card();
    
    //getters
    SuitType getSuit();
    ValueType getValue();
    
    //setters
    void setSuit(SuitType suit);
    void setValue(ValueType value);
    
    void showCard();
    
    
private:
    SuitType m_suit;
    ValueType m_value;
    
};

#endif /* Card_h */
