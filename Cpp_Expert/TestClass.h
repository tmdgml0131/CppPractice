#include <iostream>
class TestClass
{
	int test = 0;
public:
	TestClass()
	{
		test = 100;
		std::cout << "������ ȣ��!\n";
	}
	~TestClass()
	{
		test = 0;
		std::cout << "�Ҹ��� ȣ��!\n";
	}
	int get_Test();
	void set_Test(int value);
	void do_Something();
};

