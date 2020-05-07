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
    
    for(int i = 5; i >0; i--){
       
        Player newPlayer("Player" +std::to_string(i),500);
        playerList.insert(newPlayer);
        
        if( i == 1)playerList.head->player.badge =  dealer;
        else if( i == 2)playerList.head->player.badge = smallBlind;
        else if( i == 3)playerList.head->player.badge = bigBlind;
        else playerList.head->player.badge = regular;
        
    }

}

