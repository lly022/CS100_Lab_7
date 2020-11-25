#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>

class Div : public Base {
    private:
        Base* op1; //could later change to private/protected
        Base* op2;
    public:
        Div(Base* op1, Base* op2) : Base() {this->op1 = op1; this->op2 = op2; }

        double evaluate() {
		if(op2->evaluate() == 0){
			return -1;
		} 
		else{
			return op1->evaluate()/op2->evaluate(); 
		}
	}

        std::string stringify() { 
		if(op2->evaluate() == 0){
			return "-1";
		}
		else{
			return op1->stringify() + "/" + op2->stringify();
		} 
	}
};

#endif //__OP_HPP__
