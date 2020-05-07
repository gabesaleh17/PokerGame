//
//  Table.cpp
//  Poker
//
//  Created by Nectarios Ouzounidis on 5/5/20.
//  Copyright © 2020 Nectarios Ouzounidis. All rights reserved.
//

#include <stdio.h>
#include "Table.h"
#include "CLL.h"
Table::Table()
{
    
}

void Table::StartGame()
{
    Deck deckOfCards;
    deckOfCards.shuffle();
    
    for(int i = 1; i <= 5; i++)
    {
       
        Player newPlayer("Player" +std::to_string(i),500);
        playerList.insert(newPlayer);
        playerList.head = playerList.head->next;
        
        
        
    }
   //std::cout << playerList.head->player.playerName << std::endl;
}

void Table::StartRound()
{
    
        playerList.head->player.badge =  dealer;
        playerList.head->next->player.badge = smallBlind;
        playerList.head->player.badge = regular;
    
}

