#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
        Base* op1;
        Base* op2;
    public:
        Sub(Base* op1, Base* op2) : Base() {this->op1 = op1; this->op2 = op2; }
        double evaluate() { return op1->evaluate()-op2->evaluate(); }
        std::string stringify() { return op1->stringify() + "-" + op2->stringify(); }
};

#endif //__OP_HPP__
