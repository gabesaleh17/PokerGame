//
//  Table.cpp
//  Poker
//
//  Created by Gabe Saleh on 5/5/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include <stdio.h>
#include "Table.h"

Table::Table()
{
    
}

void Table::StartGame()
{
    Deck deckOfCards;
    deckOfCards.shuffle();
    
    for (int i = 1; i <= 5; i ++)
    {
        Player newPlayer("Player " + std::to_string(i), 500);
        playerList.insert(newPlayer);
    }
    
    std::cout << playerList.head->player.playerName << std::endl;
    playerList.head = playerList.head->next;
    std::cout << playerList.head->player.playerName << std::endl;
    
    
    
    
}
