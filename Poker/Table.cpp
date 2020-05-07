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
    setUpBadges();
    
}

void Table::setUpBadges(){
    
    if(isFirstRound == true){
        
        isFirstRound = false;
        
        playerList.head->player.badge = dealer;
        playerList.head = playerList.head->next;
        playerList.head->player.badge = smallBlind;
        playerList.head = playerList.head->next;
        playerList.head->player.badge = bigBlind;
        playerList.head = playerList.head->next;
       
        while(playerList.head->player.badge != dealer){
            
            playerList.head->player.badge = regular;
            playerList.head = playerList.head->next;
        }
    
    }
    
    else{
        
        while(playerList.head->player.badge != dealer){
                   playerList.head = playerList.head->next;
        }
        
        playerList.head->player.badge = regular;
        playerList.head = playerList.head->next;
        playerList.head->player.badge = dealer;
        playerList.head = playerList.head->next;
        playerList.head->player.badge = smallBlind;
        playerList.head = playerList.head->next;
        playerList.head->player.badge = bigBlind;
        
    }
}
