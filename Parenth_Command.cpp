//
//  Parenth_Command.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Parenth_Command.h"

Parenth_Command::Parenth_Command(Stack <int> & evaluation):
    s_(evaluation)
{
    
}

void Parenth_Command::execute(void){
    //nothing to do
}

int Parenth_Command::getPrecedence(void){
    return Precedence;
}

std::string Parenth_Command::getRep(void){
    return stringRepresentation;
}