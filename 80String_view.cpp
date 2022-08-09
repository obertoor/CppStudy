#include<string>
#include<iostream>




//本节主题  如何让字符串更快



//字符串格式化或者字符串操作需要分配内存
//C++17新加入
//string_view,字符串的一种视图
//本质是一个const char指针，指向其他人拥有的现有字符串，再加上一个大小
//可以避免分配


static uint32_t s_AllocCount = 0;//记录分配次数
#if 0
 void* operator new(size_t size) {
	s_AllocCount++;
	std::cout << "分配了" << size << "字节\n";
	return malloc(size);
}
#endif
namespace my_80 {
	void PrintName(const std::string& name) {
		std::cout << name << std::endl;
	}
	void PrintName_view(std::string_view name) {
		std::cout << name << std::endl;
	}
	//直接传值会导致分配次数加一
	void PrintNames(std::string name) {
		std::cout << name << std::endl;
	}
}

#if 0
int main() {

	using namespace my_80;

	std::string name = "weng jiahao";//此时已经分配了8字节
	const char* name_char = "weng jiahao";//对于静态字符串的正确处理
	//std::string firstName = name.substr(0, 4);
	//std::string lastName = name.substr(5, 10);

	//使用string_view,不会增加分配次数
	std::string_view firstName(name.c_str(),4);
	std::string_view lastName(name.c_str()+5, 6);

	std::string_view firstName_char(name_char, 4);
	std::string_view lastName_char(name_char+5, 6);

	PrintName_view(firstName);
	PrintName_view(lastName);
	//PrintNames(firstName);

	//PrintName(name);
	PrintName_view("cherno");//不会导致分配
	//PrintName("cherno");//虽然接收的是引用,但仍然需要构造,因此需要分配内存
	std::cout << "分配次数:" << s_AllocCount << std::endl;

	std::cin.get();
}
#endif