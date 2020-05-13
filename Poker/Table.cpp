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

void Table::StartGame(int numPlayers, int startingChips)
{
    numOfPlayers = numPlayers;
    deckOfCards.shuffle();
    
    for(int i = 1; i <= numPlayers; i++)
    {
       
        Player newPlayer("Player" +std::to_string(i),startingChips);
        playerList.insert(newPlayer);
        playerList.head = playerList.head->next;
        
        
        
    }
   //std::cout << playerList.head->player.playerName << std::endl;
}

void Table::StartRound()
{
    setUpBadges();
    //playerList points to first regular player
    DealtoPlayersAndBlinds();
    
    //PreFlop, one time around everyone gets to make move
    for(int i = 1; i <= numOfPlayers; i++){
        playerTurn();
    }
    
    allMove = true;
    //now make sure every has equal bet
    for(int i = 1; i <= numOfPlayers; i++){
           playerTurn();
       }
    //burn card and three up
    deckOfCards.m_deck.push_back(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    communityCards.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    communityCards.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    communityCards.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    
     while(playerList.head->player.badge != dealer){
          playerList.head = playerList.head->next;
     }
    currentRaise = 0;
    allMove = false;
    playerList.head = playerList.head->next;
    //next set of betting
    for(int i = 1; i <= numOfPlayers; i++){
        playerList.head->player.totalBetAmtRound = 0;
        playerTurn();
    }
    
    allMove = true;
    //now make sure every has equal bet
    for(int i = 1; i <= numOfPlayers; i++){
           playerTurn();
       }
    
    deckOfCards.m_deck.push_back(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    communityCards.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    
    //the river
     while(playerList.head->player.badge != dealer){
          playerList.head = playerList.head->next;
     }
    currentRaise = 0;
    allMove = false;
    playerList.head = playerList.head->next;
    //next set of betting
    for(int i = 1; i <= numOfPlayers; i++){
        playerList.head->player.totalBetAmtRound = 0;
        playerTurn();
    }
    
    allMove = true;
    //now make sure every has equal bet
    for(int i = 1; i <= numOfPlayers; i++){
           playerTurn();
       }
    
    deckOfCards.m_deck.push_back(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    communityCards.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    
    //final bets
     while(playerList.head->player.badge != dealer){
          playerList.head = playerList.head->next;
     }
    currentRaise = 0;
    allMove = false;
    playerList.head = playerList.head->next;
    //next set of betting
    for(int i = 1; i <= numOfPlayers; i++){
        playerList.head->player.totalBetAmtRound = 0;
        playerTurn();
    }
    
    allMove = true;
    //now make sure every has equal bet
    for(int i = 1; i <= numOfPlayers; i++){
           playerTurn();
    }
    
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

void Table::DealtoPlayersAndBlinds(){
    
    while(playerList.head->player.badge != smallBlind){
        playerList.head = playerList.head->next;
    }
    
    playerList.head->player.Bet(smallBlindAmt);
    pot = smallBlindAmt;
    playerList.head = playerList.head->next;
    playerList.head->player.Bet(bigBlindAmt);
    pot += bigBlindAmt;
    currentRaise = bigBlindAmt;
    
    playerList.head->player.hand.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    playerList.head->player.hand.push_front(deckOfCards.m_deck.front());
    deckOfCards.m_deck.pop_front();
    playerList.head = playerList.head->next;
    
    while(playerList.head->player.badge != bigBlind){
        
        playerList.head->player.hand.push_front(deckOfCards.m_deck.front());
        deckOfCards.m_deck.pop_front();
        playerList.head->player.hand.push_front(deckOfCards.m_deck.front());
        deckOfCards.m_deck.pop_front();
        playerList.head = playerList.head->next;
    }
        
        playerList.head = playerList.head->next;
    
}

void Table::playerTurn(){
    
    if((playerList.head->player.playerFold == false && playerList.head->player.chips != 0) || (playerList.head->player.totalBetAmtRound != currentRaise && allMove == true)){
            
            std::string moveType;
            std::string betAmount;
            std::cout << "------------------------------" << std::endl;
            std::cout << playerList.head->player.playerName << std::endl;
            std::cout << "Your Chips: " << playerList.head->player.chips << std::endl;
            std::cout << "Currnet Minumum Bet: " << currentRaise << std::endl;
            showHand();
            std::cout << "------------------------------" << std::endl;
            
             if(allMove == true){
                 
                 while (true) {
                
                     std::cout << "Your Turn, enter fold or call." << std::endl;
                     std::cin >> moveType;
                     
                     if(moveType == "fold"){
                         playerList.head->player.Fold();
                         break;
                     }
                     
                     if(moveType == "call"){
                         playerList.head->player.Bet(playerList.head->player.totalBetAmtRound - currentRaise);
                         pot += playerList.head->player.totalBetAmtRound - currentRaise;
                    }
                     
                     else{
                         continue;
                     }
                     
                 }
             }
            
            if(allMove == false){
                while (true) {
                    
                    std::cout << "Your Turn, enter fold,check,bet." << std::endl;
                    std::cin >> moveType;
                    
                    
                    if(moveType == "fold"){
                        playerList.head->player.Fold();
                        break;
                    }
                        
                    if(moveType == "check"){
                        
                        if(currentRaise == 0){
                            break;
                        }
                        else if (currentRaise != 0){
                            std::cout << "You have to fold or call the bet." << std::endl;
                            continue;
                        }
                    }
                        
                    if(moveType == "bet"){
                        
                        std::cout << "Place bet amount." << std::endl;
                        std::cin >> betAmount;
                        
                        if(std::stoi(betAmount) >  playerList.head->player.chips){
                            std::cout << "Dont have enough chips." << std::endl;
                            continue;
                        }
                       
                        
                            if(std::stoi(betAmount) < (currentRaise - playerList.head->player.totalBetAmtRound) && std::stoi(betAmount) != playerList.head->player.chips){
                                
                                std::cout << "Did not bet enough." << std::endl;
                                continue;
                            }
                            
                            else if(std::stoi(betAmount) == (currentRaise - playerList.head->player.totalBetAmtRound)){
                                
                                std::cout << "Bet Called." << std::endl;
                                playerList.head->player.Bet(std::stoi(betAmount));
                                pot += std::stoi(betAmount);
                                break;
                            }
                            
                            else if(std::stoi(betAmount) > (currentRaise - playerList.head->player.totalBetAmtRound)){
                                
                                std::cout << "Bet Raised." << std::endl;
                                playerList.head->player.Bet(std::stoi(betAmount));
                                pot += std::stoi(betAmount);
                                currentRaise +=  std::stoi(betAmount);
                                break;
                            }
                        
                    }
                        
                    else{
                      continue;
                    }
                    
                    break;
                }//while loop
            
            
        }// big ifs.. if they should be playing round
    
    playerList.head = playerList.head->next;

}
}
void Table::showHand(){
    
    playerList.head->player.hand.front().showCard();
    std::cout << ", ";
    playerList.head->player.hand.back().showCard();
    std::cout << std::endl;
}

void Table::showCommunityCards(){
    
}
