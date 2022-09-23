#include<iostream>
#include<string>


//本节主题  C++隐式转换与explicit关键字

//explicit 禁用隐式转换

//隐式转换只会执行一次
#if 0
namespace my_40 {
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;
	public:
		Entity(const std::string& name)
			:m_Name(name),m_Age(-1){}
		Entity(int age)
			:m_Name("unknow"), m_Age(age) {}

	};

	void PrintEnity(const Entity& entity)
	{

	}
}




int main()
{
	using namespace my_40;

	PrintEnity(22);
	//发生隐式转换，直接使用int构造了Entity

	//PrintEnity("Cherno");
	//char数组加上空终止符，不是string，隐式转换无法char数组>>string>>Entity

	PrintEnity(std::string("Cherno"));//string>>Entity
	PrintEnity(Entity("Cherno")); //char数组 >> string

	Entity a("Cherno");
	Entity b("22");


}
#endif