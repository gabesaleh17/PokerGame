//
//  Table.h
//  Poker
//
//  Created by Gabe Saleh on 5/1/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#ifndef Table_h
#define Table_h
#include "Player.h"
#include "Deck.h"
#include "CLL.h"

#include <deque>

class Table: public Player
{
  public:
    Table();
    CLL playerList;
    void StartGame();
    void StartRound();
    void setUpBadges();
    bool isFirstRound = true;
};

#endif /* Table_h */
