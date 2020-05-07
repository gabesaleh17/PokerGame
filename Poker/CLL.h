//
//  CLL.h
//  Poker
//
//  Created by Gabe Saleh on 5/5/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#ifndef CLL_h
#define CLL_h
#include "Player.h"

struct Node
{
    Player player;
    struct Node *next;
};

class CLL
{
public:
    Node *head;
    CLL();
    void insert(Player &newPlayer);
};



#endif /* CLL_h */
