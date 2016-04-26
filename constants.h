//
//  constants.h
//  #2
//
//  Created by Darren Meier on 4/04/16.
//  Copyright © 2016 Darren Meier. All rights reserved.
//

#ifndef constants_h
#define constants_h

namespace {
    
    const unsigned int TERM_SIZE_X = 80;
    /*
     * The width of the terminal window, in characters.
     */
    
    const unsigned int TERM_SIZE_Y = 25;
    /*
      The height of the terminal window, in characters.
     */
    
    
    const double RATIO_FILLED = 0.40;
    /*
     * How much of the neighborhood should be filled with shapes?
     */
    
    
    const double RATIO_ALIKE_HAPPY = 1 / 2.0;
    /*
     * "I'll move if my neighbors aren't at least this much like me"
     */
    
    const double RATIO_DIFFERENT_HAPPY = 1 / 5.0;
    /*
     * "I'll move if my neighbors aren't at least this much different than me"
     */
    
}

// --------------------------------------------------------------------------- //

#endif /* constants_h */
