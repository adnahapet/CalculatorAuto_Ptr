//
//  Right_Parenth.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/9/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef Right_Parenth_Command_h
#define Right_Parenth_Command_h

#include <stdio.h>
#include "Expression_Command.h"

class Right_Parenth_Command : public Expression_Command {
public:
    
    Right_Parenth_Command (Stack <int> & evaluation);
    
    void execute();
    
    int getPrecedence(void);
    
    std::string getRep(void);
    
    int Precedence = 2;
    
    
    
private:
    Stack <int> & s_;
    
    std::string stringRepresentation;
    
};

#endif /* Right_Parenth_Command_h*/
