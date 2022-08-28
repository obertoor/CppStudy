#include<iostream>
#include<variant>
#include<string>
#include <optional>
#include<fstream>


//本节主题 Variant


//C++17新特性
//单一变量存放多种类型的数据
//除非为了内存性能,否则更应该使用Variant,而不是Union
//类型安全的union


//使用 枚举
enum class ErrorCode
{
	None = 0,//没有错误
	NotFound = 1,//没找到
	NoAccess = 2,//不可读取
};

//读取文件.ErrorCode作为错误代码
std::variant<std::string, ErrorCode> ReadFileAsStrin_useVariant(const std::string& filepath)
{

	std::ifstream stream(filepath);//输入文件流

	if (stream) {
		std::string result;
		//成功打开
		//关闭文件流
		stream.close();
		return result;
	}

	return {};
}

#if 0
int main() {
	//初始化,可以说string或者int的变量
	std::variant<std::string, int> data01("12");
	std::variant<std::string, int> data02(12);
	std::variant<std::string, int> data03;

	//与UNION的比较
	union 
	{
		double a;//8字节,因此该union大小为8
		float b;
	};

	std::cout << "string大小为" << sizeof(std::string) << "\n";
	std::cout << "data01大小为" <<sizeof(data01) << "\n";//大小为32,int=4,string=28 28+4=32
	std::cout << "data03大小为" <<sizeof(data03) << "\n";


	


	data03 = "data";
	std::string& strdata = std::get<std::string>(data03);//获取string,使用&可以避免复制
	std::cout << "data03为" << std::get<std::string>(data03) << "\n";
	data03 = 12;
	std::cout << "data03为" << std::get<int>(data03) << "\n";

	int index03 = data03.index();//获取类型的下标,如string就返回0,int就返回1

	//传入data指针,如果不是string.则返回空指针,如果是,这返回指向字符串的指针
	auto value = std::get_if<std::string>(&data03);
	if (value) {
		std::string& v = *value;
		std::cout << "data03是string\n";
	}
	else {
		std::cout << "data03不是string\n";
	}

}
#endif