#include<iostream>
#include<string>


//本节主题  成员初始化列表


//构造函数中初始化类成员(变量)的一种方式

class Example
{
public:
	Example()
	{
		std::cout << "构造Example\n";
	}
	Example(int a) 
	{
		std::cout << "构造Eample(" << a << ")\n";
	}
};


class Entity 
{
private:
	std::string m_Name;
	Example m_Example;
public:
	//初始化列表需要安按照声明顺序去初始化
	Entity()
		:m_Name("Unknown"),m_Example(8)//只构造一次
	{
		//这种情况下,会调用俩次构造函数,一次默认,去初始化m_Name,然后才是this函数
		//m_Name = "Unknown";
		
		//m_Example = Example(8);
		//会构造俩次
	}
	Entity(const std::string& name) 
	{

	}
	const std::string& GetName() const {//最后的const该函数隐式传入的this指针将const指针
		return m_Name;
	}

};
#if 0
int main()
{
	Entity e;

	//std::cout << e.GetName() << std::endl;
}
#endif