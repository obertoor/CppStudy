#include<iostream>



//本节主题  虚析构函数



//不覆写析构函数,而是加上析构函数
//析构函数标记为virtual,则程序知道在层次结构去找派生类的析构函数
//为了安全的扩展类

class Base
{
public:
	Base() {
		std::cout << "Base构造成功\n";
	}
	virtual ~Base() {
		std::cout << "Base析构成功\n";
	}
};

class Dervied:public Base
{
public:
	Dervied() {
		my_Array = new int[5];
		std::cout << "Dervied构造成功\n";
	}
	~Dervied() {//如果该函数没有被调用，则内存泄露
		delete my_Array;
		std::cout << "Dervied析构成功\n";
	}
private:
	int* my_Array;
};

#if 0
int main()
{

	Base* base = new Base();
	delete base;

	std::cout << "-----------------------\n";

	//未标记virtual:此处会先调用Base的构造函数,然后才是dervied的构造函数,析构函数都调用了
	Dervied* dervied = new Dervied();
	delete dervied;

	std::cout << "-----------------------\n";

	//未标记virtual:此时会调用两个构造函数,但析构函数只调用base,这会导致内存泄露
	Base* poly = new Dervied();
	//未标记virtual:delete调用Base的析构函数
	//标记virtual:两个构造，两个析构都被调用
	delete poly;

}
#endif