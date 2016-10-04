//
//  Number_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Number_Command_h
#define Number_Command_h

#include <stdio.h>
#include <string>

#include "Expression_Command.h"

class Number_Command : public Expression_Command {
public:
    
    Number_Command (Stack <int> & evaluation, int value, std::string token);
    
    void execute();
    
    int getPrecedence(void);
    
    std::string getRep(void);
    
    int Precedence = 0;
    
    
    
private:
    Stack <int> & s_;
    
    int n_;
    
    std::string stringRepresentation;
    
};

#endif /* Number_Command_h */
