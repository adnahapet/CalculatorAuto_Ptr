//
//  Add_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Add_Command_h
#define Add_Command_h

#include <stdio.h>

#include "Binary_Operator_Command.h"

class Add_Command: public Binary_Operator_Command {

public:
    
    Add_Command(Stack <int> & evaluate);
    
    int evaluate ( int operandOne, int operandTwo) const;
    
    int getPrecedence(void);
    
    std::string getRep(void);

    
    //static vars
    
    int Precedence = 5;
    
    std::string stringRepresentation = "+";
    
};

#endif /* Add_Command_h */
