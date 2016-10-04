//
//  Calculator.cpp
//  490calculator
//
//  Created by Armen Nahapetian on 3/5/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "Calculator.h"


Calculator::Calculator()
{
    std::cout<<"Please enter an expression with spaces between all operators and operands."<<std::endl;
    std::cout<<"+ / - * % and () are currently supported. Failure to inpute a balanced expression or any other characters whill throw an exception"<<std::endl;
    std::cout<<"Enter 'QUIT' in ALL Caps to exit."<<std::endl;
    
    
    getExpression();
    
    while (input!="QUIT"){
    
        infix=tokenize();
        
        parse();
    
        std::cout<<"="<<eval()<<std::endl;
        
        getExpression();
    
   }
   
    
}


Calculator::~Calculator(){
    
}


void Calculator::getExpression(){
    
    getline(std::cin,input);
    
}

Array <std::string>  Calculator::tokenize(){
    
    Array <std::string> temp;
    std::stringstream ss(input);
    std::string token;
    int i = 0;
    
    while(ss >> token){
        temp[i]=token;
        i++;
    }
    
    temp.resize(i+1);
    return temp;
    
}

bool Calculator::isBalanced(Array <std::string> expression ){
    
    Stack <std::string> balanceCheck;
    for(int i = 0; i < expression.size(); i++){
        if (expression[i] == "(" || expression[i] == "{" || expression[i] =="["){
            balanceCheck.push(expression[i]);
        }
        else if (expression[i] == ")"){
            if(balanceCheck.is_empty()==true || balanceCheck.top() != "(")
                return false;
            else
                balanceCheck.pop();
        }
        else if(expression[i] == "}"){
            if(balanceCheck.is_empty()==true || balanceCheck.top() != "{")
                return false;
            else
                balanceCheck.pop();
        }
        else if(expression[i] == "]"){
            if(balanceCheck.is_empty()==true || balanceCheck.top() != "[")
                return false;
            else
                balanceCheck.pop();
        }
    }
    
    if(balanceCheck.is_empty()==true)
        return true;
    balanceCheck.clear();
    return false;
}


void Calculator::parse(){
    
    if(isBalanced(infix)==true && isValid(infix)==true){
        
        Stack_Expression_Command_Factory factory (result);
        
        infixtopostfix(input,factory,postfix);
        
        printPostfix();
    }
    else{
        std::cout<<"Invalid input!"<<std::endl;
        throw invalid_exception();
    }
}


//really primitive validator, new operators would need to be manually added here
//takes Array of Strings and then iterates over each string character by character
bool Calculator::isValid(Array <std::string> expression){
    
    for(int i=0;i<expression.size();i++){
        for(int z = 0; z < expression[i].length();i++){
            std::string temp = expression[i];
            if(temp < "%" ||temp > "9" || temp == "&" ||temp == "."||temp == "'"||temp == "`")
                        return false;
        }
    }
    return true;
    
}

void Calculator::infixtopostfix(const std::string & infix, Expression_Command_Factory & factory,Array <std::shared_ptr <Expression_Command>> & postfix){
    
    std::istringstream input(infix); // create a input stream parser
    std::string token;
    std::shared_ptr <Expression_Command> cmd;
    Stack <std::shared_ptr <Expression_Command> > temp;
    int i=0;
    postfix.resize(100);
    
    while (!input.eof ()) {
        
        input >> token;
        
        if (token == "+"){
            cmd = factory.create_add_command();
        }
        else if (token =="-"){
            cmd = factory.create_sub_command();
        }
        else if (token =="*"){
            cmd = factory.create_multi_command();
        }
        else if (token =="/"){
            cmd = factory.create_div_command();
        }
        else if (token =="%"){
            cmd = factory.create_mod_command();
        }
        else if (token =="("){
            cmd = factory.create_parenth_command();
        }
        else if (token == ")"){
            cmd = factory.create_right_parenth_command();
        }
        else{
            int operand = std::stoi(token);
            cmd = factory.create_number_command (operand,token);
        }
        
        
        
        // ...
        // handle the command based on infix-to-postfix algorithm
        
        if(cmd->getPrecedence()==0){
            this->postfix[i] = cmd;
            i++;
        }
        else if(cmd->getPrecedence()==1){
            temp.push(cmd);
        }
        else if(cmd->getPrecedence()==2){
            while(temp.is_empty()==false && (temp.top())->getPrecedence()!=1){
                this->postfix[i]=temp.pop();
                i++;
            }
            temp.pop();
        }
        else{
            if(temp.is_empty()==true || cmd->getPrecedence()<=(temp.top())->getPrecedence()){
                temp.push(cmd);
            }
            else if((temp.top()->getPrecedence())==1){
                temp.push(cmd);
            }
            else{
                while(temp.is_empty()==false && cmd->getPrecedence()>(temp.top()->getPrecedence()))
                    this->postfix[i]=temp.pop();
                    i++;
                    temp.push(cmd);
                }
            }
        
    
    }//end while loop

    //clears the rest of the stack of low precedence operators
    while(temp.is_empty()==false){
        this->postfix[i]=temp.pop();
        i++;
    }
    
    this->postfix.resize(i);
}


//uses iterator to traverse postfix and print it out
void Calculator::printPostfix(){
    typedef Array_Iterator <std::shared_ptr <Expression_Command>> Cmd_Array_Iterator;
    for (Cmd_Array_Iterator iter (postfix); !iter.is_done (); iter.advance ()){
        std::cout<<(*iter)->getRep();
    }
}


//uses iterator to traverse postfix and call execute() method
int Calculator::eval(void){
    
    typedef Array_Iterator <std::shared_ptr <Expression_Command>> Cmd_Array_Iterator;
    for (Cmd_Array_Iterator iter (postfix); !iter.is_done (); iter.advance ()){
        (*iter)->execute();
    }

    
    int temp = result.pop();
    return temp;
}