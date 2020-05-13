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
    Deck deckOfCards;
    std::deque<Card> communityCards;
    int pot;
    int currentRaise;
    int numOfPlayers;
    int smallBlindAmt = 5;
    int bigBlindAmt = 10;
    void DealtoPlayersAndBlinds();
    void showCommunityCards();
    void StartGame(int numPlayers, int startingChips);
    void StartRound();
    void setUpBadges();
    bool isFirstRound = true;
    void playerTurn();
    void showHand();
    bool allMove = false;
};

#endif /* Table_h */

