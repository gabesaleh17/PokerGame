//
//  Player.h
//  Poker
//
//  Created by Gabe Saleh on 5/1/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Card.h"
#include <deque>

enum playerBadge{dealer,smallBlind,bigBlind,regular};


class Player: public Card
{
  public:
    Player();
    std::string playerName;
    std::deque<Card> hand;
    int chips;
    bool playerFold = false;
    int totalBetAmtRound;
    enum playerBadge badge;
    
    Player(std::string name, int money);
    void Bet(int wager);
    void Check();
    void Fold();
    
    
};

#endif /* Player_h */
