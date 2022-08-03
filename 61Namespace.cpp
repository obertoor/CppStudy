#include <iostream>
#include<string>

//本节主题 名称空间

//主要目的：避免命名冲突
//类本身也是一种名称空间
//class A {
//public:
//	int values;
//	void Aprint(const std::string& text) {
//		std::cout << text << std::endl;
//	}
//};

namespace Firsnamespace {
	void print(const std::string& text) {
		std::cout << text << std::endl;
	}
}

//命名空间的嵌套
namespace Seconcenamespace { namespace Fristnamespace{ namespace function{
	void printf(const std::string& text) {
		std::cout << text << std::endl;
	}
}}}
#if 0
int main() {

	using Firsnamespace::print;//单独引入print
	namespace a = Firsnamespace;//取别名 在该作用域内起效


	//等同
	//using namespace Seconcenamespace::Fristnamespace::function;
	using namespace Seconcenamespace::Fristnamespace;
	using namespace function;

	Seconcenamespace::Fristnamespace::function::printf("hello");
	a::print("hello");
}
#endif