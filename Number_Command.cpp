//
//  Number_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Number_Command.h"


Number_Command::Number_Command(Stack <int> & evaluation, int value,std::string token):
    s_(evaluation),
    n_(value),
    stringRepresentation(token)
{
    
}

void Number_Command::execute(void){
    s_.push(n_);
}

int Number_Command::getPrecedence(void){
    return Precedence;
}

std::string Number_Command::getRep(void){
    return stringRepresentation;
}