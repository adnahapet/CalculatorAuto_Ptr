//
//  Binary_Operator_Command.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Binary_Operator_Command_h
#define Binary_Operator_Command_h

#include <stdio.h>

#include "Expression_Command.h"

class Binary_Operator_Command : public Expression_Command {
    
public:
    
    Binary_Operator_Command(Stack <int> & evaluation);
    
    ~Binary_Operator_Command();
    
    virtual void execute (void);
    
    virtual int evaluate(int operandOne, int operandTwo)const = 0;
    
    
    
    
private:
    
    Stack <int> & s_;
    
};

#endif /* Binary_Operator_Command_h */
