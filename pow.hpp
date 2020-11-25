#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <string>
#include <cmath>

class Pow : public Base {
        public:
         Pow(Base* val1 ,Base* val2) : Base() {this->val1=val1; this->val2=val2;}
         double evaluate() {
		return std::pow(val1->evaluate(),val2->evaluate());
        }

         std::string stringify() {
                return val1->stringify() + " ** " + val2->stringify();
        }
        private:
         Base* val1;
         Base* val2;
};

#endif
