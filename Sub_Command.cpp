//
//  Sub_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Sub_Command.h"


Sub_Command::Sub_Command(Stack <int> & evaluate):
Binary_Operator_Command(evaluate)
{
    
}


int Sub_Command::evaluate(int operandOne, int operandTwo) const{
    return operandTwo - operandOne;
}

int Sub_Command::getPrecedence(void){
    return Precedence;
}

std::string Sub_Command::getRep(void){
    return stringRepresentation;
}
