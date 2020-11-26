#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <iostream>
#include <ctype.h>
#include <stack>
#include <vector>
#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "Div.hpp"
#include "pow.hpp"

using namespace std;

class base;

class Factory{
	public:
		Factory() { };
		Base* parse(char** input, int length){
			bool flag = 0; //0 = operand, 1 = operator
			std::stack<Base*> list;
			if(length % 2 == 0){ //even or odd check
				cout << "Input is invalid" << endl;
				return nullptr;
			}
			if(length == 1){ //just 1 operand/operator in array
				string val= static_cast<string>(input[0]);
				if(isdigit(val.at(0))){
					Op* val = new Op(atoi(input[0]));
					return val;
				}
				else{
					cout << "Input is invalid" << endl;
					return nullptr;
				}
			}
			vector<string> vect;
                        for(int i = 0; i < length; i++){
                                vect.push_back(static_cast<string>(input[i]));
                        }
			for(int i = 0; i < vect.size(); i++){ //checks operator follows operand and vice versa
				if(vect.at(i) == "+" || vect.at(i) == "*" || vect.at(i) == "-" || vect.at(i) == "/" || vect.at(i) == "**" ){
					if(flag == 0){
						cout << "Input is invalid" << endl;
						return nullptr;
					}
					else{
						flag = 0;
					}
				 
				}
				if(isdigit(vect.at(i).at(0))){	
					if(flag == 1){
						cout << "Input is invalid" << endl;
						return nullptr;
					}
					else{
						flag = 1;
					}
				}	
			}
			Base* temp1;
			Base* temp2;
			Base* temp3;
			temp2 = new Op(stod(vect.at(0)));
			list.push(temp2); 
			for(int i = 1; i < vect.size(); i+=2){
				if(vect.at(i) == "+"){
					temp3 = new Op(stod(vect.at(i+1)));
					temp2 = list.top();
					list.pop();
					temp1 = new Add(temp2, temp3);
					list.push(temp1);
				}
				else if(vect.at(i) == "*"){
                                        temp3 = new Op(stod(vect.at(i+1)));
                                        temp2 = list.top();
					list.pop();
                                        temp1 = new Mult(temp2, temp3);
					list.push(temp1);
				}
				else if(vect.at(i) == "/"){                                                                                                                                         
					temp3 = new Op(stod(vect.at(i+1)));
                                        temp2 = list.top();
					list.pop();
					temp1 = new Div(temp2, temp3);
					list.push(temp1);
				}
				else if(vect.at(i) == "-"){
					temp3 = new Op(stod(vect.at(i+1)));
					temp2 = list.top();
					list.pop();
					temp1 = new Sub(temp2, temp3);
					list.push(temp1);
				}
				else if(vect.at(i) == "**"){
					temp3 = new Op(stod(vect.at(i+1)));
					temp2 = list.top();
					list.pop();
					temp1 = new Pow(temp2, temp3);
					list.push(temp1);
				}
			}
			return list.top();	
		}			

};

#endif //__FACTORY_HPP__
