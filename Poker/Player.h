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

struct playerID
{
    bool regular;
    bool bigBlind;
    bool smallBlind;
    bool dealer;
    
};


class Player: public Card
{
  public:
    std::string playerName;
    std::deque<Card> hand;
    int chips;
    struct playerID id;
    bool playerFold;
    int currentBet;
    
    Player(std::string name, int money);
    void Bet(int wager);
    void Check();
    void Fold();
    
    
};

#endif /* Player_h */
