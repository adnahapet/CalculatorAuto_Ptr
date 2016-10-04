//
//  Add_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Add_Command.h"


Add_Command::Add_Command(Stack <int> & evaluate):
    Binary_Operator_Command(evaluate)
{
    
}


int Add_Command::evaluate(int operandOne, int operandTwo) const{
    return operandOne + operandTwo;
}

int Add_Command::getPrecedence(void){
    return Precedence;
}

std::string Add_Command::getRep(void){
    return stringRepresentation;
}



