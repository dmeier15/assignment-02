//
//  neighborhood.hpp
//  #2
//
//  Created by Darren Meier on 4/06/16.
//  Copyright © 2016 Darren Meier. All rights reserved.
//

#ifndef neighborhood_hpp
#define neighborhood_hpp

// ---------------------------------------------------------------------------- //

#include "shape.hpp"
#include <vector>

// ---------------------------------------------------------------------------- //

class Shape;
/**
 * Forward declare `Shape`, in case this file gets included first.
 *
 * This is definitely not the cleanest way to do things; but it seems to me
 * right now to be the simplest.
 */

// ---------------------------------------------------------------------------- //

class Neighborhood {
private:

    
public:
    const unsigned int size_x;

    
    const unsigned int size_y;
    
    Neighborhood(unsigned int size_x, unsigned int size_y);

    
    ~Neighborhood();

    
    
    Shape get(unsigned int x, unsigned int y) const;

    
    void set(unsigned int x, unsigned int y, const Shape & s);
    
    
    void move(unsigned int old_x, unsigned int old_y);
    
    
    void animate(unsigned int frames);

};

// ---------------------------------------------------------------------------- //


#endif /* neighborhood_hpp */
