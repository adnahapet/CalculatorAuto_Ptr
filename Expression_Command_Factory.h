//
//  Expression_Command_Factory.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Expression_Command_Factory_h
#define Expression_Command_Factory_h

#include <stdio.h>
#include <memory>

#include "Binary_Operator_Command.h"
#include "Add_Command.h"
#include "Number_Command.h"
#include "Sub_Command.h"
#include "Multiply_Command.h"
#include "Mod_Command.h"
#include "Division_Command.h"
#include "Parenth_Command.h"
#include "Right_Parenth_Command.h"

class Expression_Command_Factory {
    
public:
    
    Expression_Command_Factory(void);
    
    virtual ~Expression_Command_Factory (void) = 0;
    
    virtual std::shared_ptr <Number_Command> create_number_command (int num,std::string token) = 0;
    
    virtual std::shared_ptr <Add_Command>  create_add_command (void) = 0;
    
    virtual std::shared_ptr <Sub_Command> create_sub_command (void) = 0;
    
    virtual std::shared_ptr <Multiply_Command>  create_multi_command (void) = 0;
    
    virtual std::shared_ptr <Division_Command>  create_div_command (void) = 0;
    
    virtual std::shared_ptr <Mod_Command>  create_mod_command (void) = 0;
    
    virtual std::shared_ptr <Parenth_Command > create_parenth_command (void) = 0;
    
    virtual std::shared_ptr <Right_Parenth_Command>  create_right_parenth_command (void)= 0;
    

private:
    
    //Copy Constructor and = Operator
    //Prevents call in child classes
    
   Expression_Command_Factory (const Expression_Command_Factory &);
    
   const Expression_Command_Factory & operator = (const Expression_Command_Factory &);
    
};

#endif /* Expression_Command_Factory_h */
