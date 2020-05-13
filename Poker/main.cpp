//
//  main.cpp
//  Poker
//
//  Created by Gabe Saleh on 4/26/20.
//  Copyright © 2020 Gabe Saleh. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Table.h"

int main(int argc, const char * argv[])
{
    int numOfPlayers;
    int startingChips;
    Table newTable;
    std::cout << "enter number of players between 2-11" << std::endl;
    std::cin >> numOfPlayers;
    std::cout << "enter number of starting chips" << std::endl;
    std::cin >> startingChips;
    newTable.StartGame(numOfPlayers,startingChips);
    newTable.StartRound();
    
    

    
}
