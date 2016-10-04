//
//  Multiply_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Multiply_Command_h
#define Multiply_Command_h

#include <stdio.h>

#include "Binary_Operator_Command.h"

class Multiply_Command: public Binary_Operator_Command {
    
public:
    
    Multiply_Command(Stack <int> & evaluate);
    
    int evaluate ( int operandOne, int operandTwo) const;
    
    int getPrecedence(void);
    
    std::string getRep(void);
    
    
    //static vars
    
    int Precedence = 4;
    
    std::string stringRepresentation = "*";
    
};


#endif /* Multiply_Command_h */
