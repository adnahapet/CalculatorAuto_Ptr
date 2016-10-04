//
//  Division_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Division_Command_h
#define Division_Command_h

#include <stdio.h>

#include "Binary_Operator_Command.h"

class Division_Command: public Binary_Operator_Command {
    
public:
    
    Division_Command(Stack <int> & evaluate);
    
    int evaluate ( int operandOne, int operandTwo) const;
    
    int getPrecedence(void);
    
    std::string getRep(void);
    
    
    //static vars
    
    int Precedence = 4;
    
    std::string stringRepresentation = "/";
    
};


#endif /* Division_Command_h */
