//
//  shape.hpp
//  #2
//
//  Created by Darren Meier on 4/06/16.
//  Copyright © 2016 Darren Meier. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp

#include <string>

#include "buffer.hpp"
#include "neighborhood.hpp"

// ---------------------------------------------------------------------------- //

class Neighborhood;


// ---------------------------------------------------------------------------- //

class Shape {
    
private:
    
    std::string type_;

    std::string type_art_;

    
public:
    static const unsigned int size_x = 5;

    static const unsigned int size_y = 3;
    
    Shape(const std::string & type="empty");
    
    ~Shape();

    std::string getType();
    
    void setType(const std::string & type);

    void drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const;

    bool isHappy( const Neighborhood & n,
                 unsigned int x,
                 unsigned int y ) const;
    
};

// ---------------------------------------------------------------------------- //

#endif /* shape_hpp */
