#include<iostream>



//本节主题 类型转换


//方便我们去搜索代码库，找到类型转换
//增加了编译器的检查
//static_cast:静态类型转换
//reinterpret_cast:类型双关，把这段内存解释成其他东西
//const_cast:移除或者添加变量的const限定
//dynamic_cast：将一个基类对象指针（或引用）转换到继承类指针


class Base {
public:
	Base() {}
	virtual ~Base(){}
};
class Derived:public Base {
public:
	Derived() {}
	virtual ~Derived() {}
};
class AnotherClass :public Base {
public:
	AnotherClass() {}
	virtual ~AnotherClass() {}
};


#if 0
int main() 
{
	double value = 5.25;//隐式转换
	int a = value;//隐式转换,a=5


	//c++风格的转换
	double b = static_cast<int>(value) + 5.3; //b=10.3，转换不成功返回NULL
	
	Derived* derived = new Derived();
	Base* base = derived;//变成Base指针

	//查看是否是Derived实例或者AnotherClass实例
	//dynamic_cast会查看是否转换成功
	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
	if (!ac) 
	{
		std::cout << "转换失败" << std::endl;
	}
}
#endif