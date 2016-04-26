//
//  neighborhood.cpp
//  #2
//
//  Created by Darren Meier on 4/06/16.
//  Copyright © 2016 Darren Meier. All rights reserved.
//


#include <random>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include "constants.h"
#include "buffer.hpp"
#include "shape.hpp"
#include "neighborhood.hpp"


// ---------------------------------------------------------------------------- //

namespace {
    unsigned int mtrand(unsigned int low, unsigned int high) {
        static std::random_device rd;
        static std::mt19937 mt(rd());  // engine (mersenne twister)
        
        return std::uniform_int_distribution<unsigned int>(low, high)(mt);
    }
    
}


Neighborhood::Neighborhood(unsigned int size_x, unsigned int size_y) : size_x(size_x), size_y(size_y)
{
    unsigned int padding = 5 * 3;
    
    for (int idx = 0; idx < (size_y * size_x * padding); idx++)
    {
        Shape p_next_shape;
        p_next_shape.setType("empty");
        Neighborhood_[idx] = p_next_shape;
    }
}


Neighborhood::~Neighborhood()
{
    Neighborhood_.erase(Neighborhood_.begin(), Neighborhood_.end());
}


Shape Neighborhood::get(unsigned int x, unsigned int y) const
{
    return ((Neighborhood_[y * size_x + x]));
}


void  Neighborhood::set(unsigned int x, unsigned int y, const Shape & s)
{
    Neighborhood[y * size_x + x] = s;
    
}


void Neighborhood::move(unsigned int old_x, unsigned int old_y)
{
    unsigned int x_random_position = mtrand(0,TERM_SIZE_X);
    unsigned int y_random_position = mtrand(0,TERM_SIZE_Y);
    Shape empty_shape;
    get(old_x,old_y);
    Shape shape_to_move = neighborhood_[old_y * size_x + old_x];
    set(old_x,old_y,empty_shape);
    Neighborhood[old_y * size_x + old_x] = empty_shape;
    set(x_random_position,y_random_position,shape_to_move);
    Neighborhood[y_random_position * size_x + x_random_position] = empty_shape;
}


void Neighborhood::animate(unsigned int frames)
{
    {
        Buffer b(size_x * Shape::size_x, size_y * Shape::size_y);
        for (int k = 0; k < frames; k++)
        {
            for (int y = 0; y < size_y; y++)
            {
                for (int x = 0; x < size_x; x++)
                {
                    Neighborhood[y*size_x + x].drawToBuffer(b, x*Shape::size_x, y*Shape::size_y);
                }
            }
            
            b.draw();
            for (int y = 0; y < size_y; y++)
            {
                for (int x = 0; x < size_x; x++)
                {
                    if (!Neighborhood_[y*size_x + x].isHappy(*this, x, y))
                        
                        move(x, y);
                    
                
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    };
