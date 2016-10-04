//
//  Mod_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Mod_Command.h"


Mod_Command::Mod_Command(Stack <int> & evaluate):
Binary_Operator_Command(evaluate)
{
    
}


int Mod_Command::evaluate(int operandOne, int operandTwo) const{
    return operandTwo % operandOne;
}

int Mod_Command::getPrecedence(void){
    return Precedence;
}

std::string Mod_Command::getRep(void){
    return stringRepresentation;
}
