#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <string>

class Mult : public Base {
        public:
         Mult(Base* val1 ,Base* val2) : Base() {this->val1=val1; this->val2=val2;}
         double evaluate() {
                return val1->evaluate() * val2->evaluate();
        }
         std::string stringify() {
                return val1->stringify() + " * " + val2->stringify();
        }
        private:
         Base* val1;
         Base* val2;
};

#endif

