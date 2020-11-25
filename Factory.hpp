#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__
#include <iostream>
#include <ctype.h>
#include <stack>

class Factory{
	public:
		Base* parse(char** input, int length){
			boolean flag = 0; //0 = operand, 1 = operator
			std::stack<Base*> list;
			if(length % 2 == 0){ //even or odd check
				std::cout << "Input is invalid" << std::end1;
				return nullptr;
			}
			if(length == 1){ //just 1 operand/operator in array
				if(isdigit(input[0])){
					Base* base = new Base(input[0]);
					return base;
				}
				else{
					std::cout << "Input is invalid" << std::endl;
					return nullptr;
				}
			}
			for(int i = 0; i < length; i++){ //checks operator follows operand and vice versa
				if(input[i] == '+' || input[i] == '*' || input[i] == '-' || input[i] == '/' || input[i] == '**' ){
					if(flag == 0){
						std::cout << "Input is invalid" << std::endl;
						return nullptr;
					}
					else{
						flag = 0;
					}
				 
				}
				if(isdigit(input[i])){
					if(flag == 1){
						std::cout << "Input is invalid" << std::endl;
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
			temp2 = new Base(input[0]);
			list.push(temp2); 
			for(int i = 1; i < length; i+2){
				if(input[i] == '+'){
					temp3 = new Base(input[i+1]);
					temp2 = list.pop();
					temp1 = new Add(temp2, temp3);
					list.push(temp1);
				}
				else if(input[i] == '*'){
                                        temp3 = new Base(input[i+1]);
                                        temp2 = list.pop();
                                        temp1 = new Mult(temp2, temp3);
					list.push(temp1);
				}
				else if(input[i] == '/'){                                                                                                                                                                                                  temp3 = new Base(input[i+1]);
                                        temp2 = list.pop();
					temp1 = new Div(temp2, temp3);
					list.push(temp1);
				}
				else if(input[i] == '-'){
					temp3 = new Base(input[i+1]);
					temp2 = list.pop();
					temp1 = new Sub(temp2, temp3);
					list.push(temp1);
				}
				else if(input[i] == '**'){
					temp3 = new Base(input[i+1]);
					temp2 = list.pop();
					temp1 = new Pow(temp2, temp3);
					list.push(temp1);
				}
			}
			return list.pop();	
		}			

};

#endif //__FACTORY_HPP__
