#include <iostream>
class TestClass
{
	int test = 0;
public:
	TestClass()
	{
		test = 100;
		std::cout << "생성자 호출!\n";
	}
	~TestClass()
	{
		test = 0;
		std::cout << "소멸자 호출!\n";
	}
	int get_Test();
	void set_Test(int value);
	void do_Something();
};

