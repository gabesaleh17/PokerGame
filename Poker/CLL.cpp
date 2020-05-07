//
//  CLL.cpp
//  Poker
//
//  Created by Gabe Saleh on 5/5/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "CLL.h"

CLL::CLL()
{
    head = NULL;
}

void CLL::insert(Player &newPlayer)
{
    struct Node *newnode = new Node;
    struct Node *ptr = head;
    newnode->player = newPlayer;
    newnode->next = head;
    if (head!= NULL)
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
    } else
        newnode->next = newnode;
    head = newnode;
}
