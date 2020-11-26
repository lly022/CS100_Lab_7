#include <iostream>

#include "Factory.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include <vector>

using namespace std;

int main(int argv, char** argc) {
	char* vals[argv-1];
	for(unsigned i = 0; i< argv-1;i++){
		vals[i]=argc[i+1];
	}	
	Factory* factory = new Factory();
	Base* conversion = factory->parse(vals, argv-1);
	cout << conversion->stringify() << " = " << conversion->evaluate() << endl;
	return 0;


}
