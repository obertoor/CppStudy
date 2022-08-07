#include<iostream>
#include<tuple>
#include<string>
#include <chrono>

//本节主体  结构化绑定

//针对C++17

//可以使用pari,但只能限定两个参数,tuple可以有多个
std::tuple<std::string,int> CreatePerson()
{
	return { "Obeytoor",24 };
}


#if 0
int main()
{
	auto person = CreatePerson();
	//访问数据
	std::string name00 = std::get<0>(person);
	int age00 = std::get<1>(person);

	//使用tie
	std::string name01;
	int age01;
	std::tie(name01, age01) = CreatePerson();


	std::string name02;
	int age02;
	{
		//结构化绑定,name和age限定于作用域内
		auto [name, age] = CreatePerson();
		auto [name02, age02] = CreatePerson();
		std::cout << name << std::endl;
	}
	std::cout << name02 << std::endl;//无法传递	


}
#endif