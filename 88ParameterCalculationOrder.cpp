#include<iostream>


//本节主题  参数计算顺序



#if 0

void Function(int a, int b) {
	std::cout << a <<"+"<<b<<"="<<(a+b)<< std::endl;

};




int main()
{
	int a = 2;

	//这是C++标准未定义的行为,其具体行动取决与编译器
	//不要使用这种操作
	Function(2, a++);//传入两个参数,都是2  2+2
	std::cout << a << std::endl;//a=3
	a = 2;
	Function(a++, a++);//3+2
}

#endif