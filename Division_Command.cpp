//
//  Division_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Division_Command.h"

Division_Command::Division_Command(Stack <int> & evaluate):
Binary_Operator_Command(evaluate)
{
    
}


int Division_Command::evaluate(int operandOne, int operandTwo) const{
    return  operandTwo / operandOne;
}

int Division_Command::getPrecedence(void){
    return Precedence;
}

std::string Division_Command::getRep(void){
    return stringRepresentation;
}
