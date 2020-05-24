//
//  painter.hpp
//  Tetris_Final
//
//  Created by Данила Дудин on 14.12.2019.
//  Copyright © 2019 Данила Дудин. All rights reserved.
//

#ifndef painter_hpp
#define painter_hpp

#include <stdio.h>
#pragma once

class Painter
{
public:
    enum Color { RED, WHITE, MAGENTA, DARK_BLUE,
        GREEN, BROWN, CYAN, BLACK };
    void rect(int x1, int y1, int x2, int y2);
    void setColor(Color);
};

#endif /* painter_hpp */
