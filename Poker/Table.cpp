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
        
        if( i == 1)playerList.head->player.type =  dealer;
        else if( i == 2)playerList.head->player.type = smallBlind;
        else if( i == 3)playerList.head->player.type = bigBlind;
        else playerList.head->player.type = regular;
        
    }

}

void Table::StartRound(){
    
    
}
