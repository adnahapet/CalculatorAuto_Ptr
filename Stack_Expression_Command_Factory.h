//
//  Stack_Expression_Command_Factory.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Stack_Expression_Command_Factory_h
#define Stack_Expression_Command_Factory_h

#include <stdio.h>

#include "Expression_Command_Factory.h"

class Stack_Expression_Command_Factory : public Expression_Command_Factory{
    
public:
    
    Stack_Expression_Command_Factory(Stack <int> &evaluation);
    
    virtual ~Stack_Expression_Command_Factory ();
    
    virtual std::shared_ptr <Number_Command> create_number_command (int num,std::string token);
    
    virtual std::shared_ptr <Add_Command>  create_add_command ();
    
    virtual std::shared_ptr <Sub_Command> create_sub_command ();
    
    virtual std::shared_ptr <Multiply_Command>  create_multi_command ();
    
    virtual std::shared_ptr <Division_Command>  create_div_command ();
    
    virtual std::shared_ptr <Mod_Command> create_mod_command ();
    
    virtual std::shared_ptr <Parenth_Command> create_parenth_command ();
    
    virtual std::shared_ptr <Right_Parenth_Command> create_right_parenth_command ();
    
    
private:
    
    Stack <int> & s_;

    
};

#endif /* Stack_Expression_Command_Factory_h */
