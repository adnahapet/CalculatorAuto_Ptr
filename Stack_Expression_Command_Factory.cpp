//
//  Stack_Expression_Command_Factory.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Stack_Expression_Command_Factory.h"


Stack_Expression_Command_Factory::Stack_Expression_Command_Factory(Stack <int> &evaluation):
    s_(evaluation)
{
    
}


Stack_Expression_Command_Factory::~Stack_Expression_Command_Factory(){
    
}

std::shared_ptr <Add_Command> Stack_Expression_Command_Factory::create_add_command(){
    
    std::shared_ptr <Add_Command>  newAddCommand ( new Add_Command(s_));
    return newAddCommand;
    
}

std::shared_ptr <Number_Command> Stack_Expression_Command_Factory::create_number_command(int num, std::string token){
    
    std::shared_ptr <Number_Command> newNumberCommand (new Number_Command(s_,num,token));
    return newNumberCommand;
}

std::shared_ptr <Sub_Command> Stack_Expression_Command_Factory::create_sub_command(){
    
    std::shared_ptr <Sub_Command> newSubCommand (new Sub_Command(s_));
    return newSubCommand;
    
}

std::shared_ptr <Multiply_Command> Stack_Expression_Command_Factory::create_multi_command(){
    
    std::shared_ptr <Multiply_Command >newMultiCommand (new Multiply_Command(s_));
    return newMultiCommand;
    
}

std::shared_ptr <Mod_Command> Stack_Expression_Command_Factory::create_mod_command(){
    
    std::shared_ptr <Mod_Command> newModCommand (new Mod_Command(s_));
    return newModCommand;
}

std::shared_ptr <Division_Command> Stack_Expression_Command_Factory::create_div_command(){
    
    std::shared_ptr <Division_Command> newDivCommand  (new Division_Command(s_));
    return newDivCommand;
}

std::shared_ptr <Parenth_Command> Stack_Expression_Command_Factory::create_parenth_command(){
    
    std::shared_ptr <Parenth_Command> newParenthCommand (new Parenth_Command(s_));
    return newParenthCommand;
}

std::shared_ptr <Right_Parenth_Command> Stack_Expression_Command_Factory::create_right_parenth_command(){
    
    std::shared_ptr <Right_Parenth_Command> newRightParenthCommand  (new Right_Parenth_Command(s_));
    return newRightParenthCommand;
}

