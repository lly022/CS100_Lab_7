#ifndef __FACTORY_TESTS_HPP_
#define __FACTORY_TESTS_HPP_

using namespace std;

#include "Factory.hpp"
#include "base.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "Div.hpp"
#include "pow.hpp"
#include "sub.hpp"

TEST(FactoryTest, BasicAddition) {
	char* test_val[3];
	test_val[0]="8";
	test_val[1]="+";
	test_val[2]="2";
	Factory* factory = new Factory();
	
	Base* conversion = factory->parse(test_val, 3);

	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(), "8.000000 + 2.000000");
	EXPECT_EQ(conversion->evaluate(), 10.000000);
}


#endif
