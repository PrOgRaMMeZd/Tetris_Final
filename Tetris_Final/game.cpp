//
//  game.cpp
//  Tetris_Final
//
//  Created by Данила Дудин on 14.12.2019.
//  Copyright © 2019 Данила Дудин. All rights reserved.
//

#include "game.hpp"
#include <cstdlib>

Game::Game():
tetromino_(static_cast<Tetromino::Name>(rand() % 7)) {}

void Game::draw(Painter &p)
{
    well_.draw(p);
    tetromino_.draw(p);
}

void Game::tick()
{
    Tetromino t = tetromino_;
    t.move(0, 1);
    if (!well_.isCollision(t))
        tetromino_ = t;
    else
    {
        well_.unite(tetromino_);
        well_.removeSolidLines();
        if (well_.removeSolidLines()!=0){
            SCORE+=10*well_.res;
            well_.res=0;
        }
        tetromino_ = Tetromino
        (static_cast<Tetromino::Name>(rand() % 7));
        if (well_.isCollision(tetromino_)){
            gameover=true;
            restart();
    }
    }
}

void Game::restart()
{
    well_ = Well();
}

void Game::keyEvent(Direction d)
{
    Tetromino t = tetromino_;
    switch (d)
    {
        case UP: t.rotate(Tetromino::LEFT);
            break;
        case DOWN: t.move(0, 1);
            break;
        case LEFT: t.move(-1, 0);
            break;
        case RIGHT: t.move(1, 0);
            break;
    }
    if (!well_.isCollision(t))
        tetromino_ = t;
}
