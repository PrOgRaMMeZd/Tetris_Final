//
//  game.hpp
//  Tetris_Final
//
//  Created by Данила Дудин on 14.12.2019.
//  Copyright © 2019 Данила Дудин. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#pragma once
#include "tetromino.hpp"
#include "Well.hpp"

class Painter;

class Game
{
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Game();
    void draw(Painter &);
    void tick();
    void restart();
    void keyEvent(Direction);
    unsigned long long int SCORE=0;
    bool gameover=false;
private:
    Well well_;
    Tetromino tetromino_;
};

#endif /* game_hpp */
