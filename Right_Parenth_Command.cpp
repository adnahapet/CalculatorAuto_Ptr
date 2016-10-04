//
//  Right_Parenth.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Right_Parenth_Command.h"

Right_Parenth_Command::Right_Parenth_Command(Stack <int> & evaluation):
s_(evaluation)
{
    
}

void Right_Parenth_Command::execute(void){
    //nothing to do
}

int Right_Parenth_Command::getPrecedence(void){
    return Precedence;
}

std::string Right_Parenth_Command::getRep(void){
    return stringRepresentation;
}