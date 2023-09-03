#include "TestClass.h"

using namespace std;

int TestClass::get_Test()
{
	return test;
}

void TestClass::set_Test(int value)
{
	test = value;
}

void TestClass::do_Something()
{
	test += 10;
}