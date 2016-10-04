//
//  Multiply_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack <int> & evaluate):
Binary_Operator_Command(evaluate)
{
    
}


int Multiply_Command::evaluate(int operandOne, int operandTwo) const{
    return operandOne * operandTwo;
}

int Multiply_Command::getPrecedence(void){
    return Precedence;
}

std::string Multiply_Command::getRep(void){
    return stringRepresentation;
}
