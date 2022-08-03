#include <iostream>
#include<string>


//本节主题 不使用using namespace std

//大型项目都不应该使用std,或者说不要这头文件包含
//只在一个函数内使用，或者使用：：
namespace apple {
	void print(const std::string& text) {
		std::cout << text << std::endl;
	}
}

namespace orange {
	void print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}


//std可以这作用域内声明
void usestd() {
	using namespace std;
	cout << "usestd" << endl;
}


#if 0
using namespace apple;
using namespace orange;

int main() {
	print("hello");//hello是char[] 先调用orange
	apple::print("hello");//带有隐式转换
	//直接调用print会出错
}

#endif