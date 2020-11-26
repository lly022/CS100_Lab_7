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

//test nullpte EXPECT_EQ 
TEST(FactoryTest, BasicSubtraction){
	char* test_val[3];
	test_val[0] = "8";
	test_val[1] = "-";
	test_val[2] = "2";
	Factory* factory = new Factory();
	
	Base* conversion = factory->parse(test_val, 3);

	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(), "8.000000 - 2.000000");
	EXPECT_EQ(conversion->evaluate(), 6.000000);
}

TEST(FactoryTest, BasicDivision){
	char* test_val[3];
	test_val[0] = "8";
	test_val[1] = "/";
	test_val[2] = "2";
	Factory* factory = new Factory();
	
	Base* conversion = factory->parse(test_val, 3);
	
	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(), "8.000000 / 2.000000");
	EXPECT_EQ(conversion->evaluate(), 4.000000);
}

TEST(FactoryTest, DivAndSub){
	char* test_val[5];
	test_val[0] = "8";
	test_val[1] = "/";
	test_val[2] = "2";
	test_val[3] = "-";
	test_val[4] = "1";
	Factory* factory = new Factory();

	Base* conversion = factory->parse(test_val, 5);
	
	ASSERT_NE(conversion, nullptr);
	EXPECT_EQ(conversion->stringify(), "8.000000 / 2.000000 - 1.000000");
	EXPECT_EQ(conversion->evaluate(), 3.000000);
}

TEST(FactoryTest, SubtractionInvalidInput){
	char* test_val[3];
	test_val[0] = "8";
	test_val[1] = "--";
	test_val[2] = "2";
	Factory* factory = new Factory();

	Base* conversion = factory->parse(test_val, 3);

	EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, DivisionInvalidInput){
	char* test_val[3];
	test_val[0] = "/";
	test_val[1] = "8";
	test_val[2] = "4";
	Factory* factory = new Factory();

	Base* conversion = factory->parse(test_val, 3);

	EXPECT_EQ(conversion, nullptr);
}	

TEST(FactoryTest, MultipleOperatorsInvalidInput){
	char* test_val[3];
	test_val[0] = "/";
	test_val[1] = "-";
	test_val[2] = "/";
	Factory* factory = new Factory();
	
	Base* conversion = factory->parse(test_val, 3);

	EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, EqualSignInvalidInput){
	char* test_val[3];
	test_val[0] = "5";
	test_val[1] = "=";
	test_val[2] = "5";
	Factory* factory = new Factory();

	Base* conversion = factory->parse(test_val, 3);

	EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, BasicMult) {
        char* test_val[3];
        test_val[0]="8";
        test_val[1]="*";
        test_val[2]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 3);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 * 2.000000");
        EXPECT_EQ(conversion->evaluate(), 16.000000);
}

TEST(FactoryTest, MultAndAdd) {
        char* test_val[5];
        test_val[0]="8";
        test_val[1]="*";
        test_val[2]="2";
	test_val[3]="+";
	test_val[4]="4";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 5);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 * 2.000000 + 4.000000");
        EXPECT_EQ(conversion->evaluate(), 20.000000);
}

TEST(FactoryTest, BasicPow) {
        char* test_val[3];
        test_val[0]="8";
        test_val[1]="**";
        test_val[2]="2";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 3);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 ** 2.000000");
        EXPECT_EQ(conversion->evaluate(), 64.000000);
}

TEST(FactoryTest, PowAndAdd) {
        char* test_val[5];
        test_val[0]="8";
        test_val[1]="**";
        test_val[2]="2";
	test_val[3]="+";
	test_val[4]="4";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 5);

        ASSERT_NE(conversion, nullptr);
        EXPECT_EQ(conversion->stringify(), "8.000000 ** 2.000000 + 4.000000");
        EXPECT_EQ(conversion->evaluate(), 68.000000);
}

TEST(FactoryTest, InvalidInput1) {
        char* test_val[3];
        test_val[0]="8";
        test_val[1]="*";
        test_val[2]="*";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 3);

        EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, InvalidInput2) {
        char* test_val[3];
        test_val[0]="8";
        test_val[1]="4";
        test_val[2]="*";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 3);

        EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, InvalidInput3) {
        char* test_val[1];
        test_val[0]="*";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 1);

        EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, InvalidInput4) {
        char* test_val[4];
        test_val[0]="8";
        test_val[1]="*";
        test_val[2]="5";
	test_val[3]="+";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        EXPECT_EQ(conversion, nullptr);
}

TEST(FactoryTest, InvalidInput5) {
        char* test_val[4];
        test_val[0]="*";
        test_val[1]="5";
        test_val[2]="*";
	test_val[3]="4";
        Factory* factory = new Factory();

        Base* conversion = factory->parse(test_val, 4);

        EXPECT_EQ(conversion, nullptr);
}




#endif
