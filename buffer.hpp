//
//  buffer.hpp
//  #2
//
//  Created by Darren Meier on 4/02/16.
//  Copyright © 2016 Darren Meier. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#include <string>
#include <iostream>

// ----------------------------------------------------------------------------

class Buffer {
        private:
            char * data_;

        public:
            const unsigned int size_x;

            const unsigned int size_y;

    
        Buffer(unsigned int size_x, unsigned int size_y);

            ~Buffer();

            char get(unsigned int x, unsigned int y) const;

            void set(unsigned int x, unsigned int y, char c);

    
            void set(unsigned int pos_x, unsigned int pos_y, std::string s);
    
        void draw() const;
    
    
           void clear();
};
#endif /* buffer_hpp */
