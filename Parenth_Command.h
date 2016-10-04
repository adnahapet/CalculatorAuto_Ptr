//
//  Parenth_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Parenth_Command_h
#define Parenth_Command_h

#include <stdio.h>
#include "Expression_Command.h"

class Parenth_Command : public Expression_Command {
public:
    
    Parenth_Command (Stack <int> & evaluation);
    
    void execute();
    
    int getPrecedence(void);
    
    std::string getRep(void);
    
    int Precedence = 1;
    
    
    
private:
    Stack <int> & s_;
    
    std::string stringRepresentation;
    
};

#endif /* Parenth_Command_h */
