#include<iostream>


//本节主题 类和结构体中的static

//类和结构体中的静态变量，代表在类的所有实例中，只存在一个变量
//类和结构体中的静态方法，无法访问类的实例，无需通过类的实例，在其内部不能写引用到类实例的代码

struct Entity_22
{
	static int g;
	int x, y;
	void Print()
	{
		std::cout << x <<","<< y << "," <<g<< std::endl;
	}
	//静态方法不能访问非静态成员函数
	static void s_Print()
	{
		std::cout << g << std::endl;
	}

	//实际上每个类或者结构体的非静态方法，其参数表都有一个隐藏的参数，就是当前的实例
	//静态方法的参数表缺乏当前实例函数的引用
#if 0
	static void s_Print(Entity_22 e1)
	{
		std::cout << g << std::endl;
	}
#endif 
};



int Entity_22::g;//使得其可以通过实例去定义
#if 0
int main()
{
	Entity_22 e1;
	e1.x = 2;
	e1.y = 4;
	e1.g = 6;

	Entity_22 e2;
	e2.x = 4;
	e2.y = 8;
	e2.g = 10;//static固定为最后一次定义
	//所有实例的g指向同一片内存

	Entity_22::g = 22;

	e1.Print();
	e2.Print();
	std::cin.get();
}
#endif