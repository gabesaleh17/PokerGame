//
//  Player.cpp
//  Poker
//
//  Created by Gabe Saleh on 5/1/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <deque>

Player::Player()
{
    
}


Player::Player(std::string name, int money)
{
    playerName = name;
    chips = money;
    currentBet = 0;
    playerFold = false;
    
}

void Player::Bet(int wager)
{
    currentBet += wager;
    
    if((chips - wager) != 0)
    {
        chips -= wager;
    }
    else
    {
        std::cout << "Not enough money" << std::endl;
    }
}

void Player::Check()
{
    
}

void Player::Fold()
{
    playerFold = true;
}
