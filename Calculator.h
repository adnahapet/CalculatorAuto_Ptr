//
//  Calculator.h
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <memory>

#include "Stack.h"
#include "Stack_Expression_Command_Factory.h"
#include "Array.h"
#include "Array_Iterator.h"

class Calculator{
    
public:
    
    /**
     * @class invalid_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class invalid_exception : public std::exception
    {
        
    public:
        /// Default constructor.
        invalid_exception (void)
        : std::exception () { }
    };
    
    //constructors and methods
    Calculator();
    
    ~Calculator();
    
    void getExpression();
    
    Array <std::string> tokenize();
    
    bool isBalanced(Array <std::string> expression);
    
    bool isValid(Array <std::string> expression);
    
    void parse();
    
    void infixtopostfix(const std::string & infix, Expression_Command_Factory & factory,Array <std::shared_ptr <Expression_Command> >& postfix);
    
    void printPostfix(void);
    
    int eval(void);
    
    
    //member variables
    
    std::string input;

    Array <std::string> infix;
    
    Array <std::shared_ptr <Expression_Command>> postfix;
    
    Stack <int> result;
    


    
};

#endif /* Calculator_h */
