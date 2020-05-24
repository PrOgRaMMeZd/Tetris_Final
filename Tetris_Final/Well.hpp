//
//  Well.hpp
//  Tetris_Final
//
//  Created by Данила Дудин on 14.12.2019.
//  Copyright © 2019 Данила Дудин. All rights reserved.
//

#ifndef Well_hpp
#define Well_hpp

#include <stdio.h>
#pragma once

class Painter;
class Tetromino;

class Well
{
public:
    enum { WIDTH = 10, HEIGHT = 20 };
    Well();
    // рисует колодец на рисовальщике Painter
    void draw(Painter &) const;
    // проверка на столкновения тетромины с
    // блоками в колодце
    bool isCollision(const Tetromino &) const;
    // перенос тетромины в колодец
    void unite(const Tetromino &);
    // удаление полностью заполненых строки
    int removeSolidLines();
    int res=0;
private:
    bool map_[HEIGHT][WIDTH];
};
#endif /* Well_hpp */
