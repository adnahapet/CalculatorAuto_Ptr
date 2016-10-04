//
//  Binary_Operator_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Binary_Operator_Command.h"


Binary_Operator_Command::Binary_Operator_Command(Stack <int> & evaluation):
    s_(evaluation)
{
    
}


Binary_Operator_Command::~Binary_Operator_Command(){
    
}



void Binary_Operator_Command::execute(){
    
    int operandOne = s_.pop();
    
    int operandTwo = s_.pop();
    
    int result = this->evaluate(operandOne,operandTwo);
    
    s_.push(result);
    
}
