//
//  Expression_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Command_h
#define Expression_Command_h

#include "Stack.h"
#include <string>

class Expression_Command {
public:
    
    virtual void execute (void) = 0;
    
    virtual int getPrecedence(void) = 0;
    
    virtual std::string getRep(void) = 0;
    
};

#endif /* ExpressionCommand_h */
