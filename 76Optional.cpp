#include<iostream>
#include<string>
#include<fstream>
#include<optional>

//本节主题  OPTIONAL


//处理返回不确定的返回数据


//读取文件,使用OutSuccess标记是否查询成功
std::string ReadFileAsStrin(const std::string& filepath,bool& OutSuccess) 
{
	std::ifstream stream(filepath);//输入文件流

	if (stream) {
		std::string result;
		//成功打开
		//关闭文件流
		stream.close();
		OutSuccess = true;
		return result;
	}

	return std::string();//返回空字符
}

//使用OPTIONAL
//C++17新特性
std::optional<std::string> ReadFileAsStrin_useOptional(const std::string& filepath)
{

	std::ifstream stream(filepath);//输入文件流

	if (stream) {
		std::string result;
		//成功打开
		//关闭文件流
		stream.close();
		return result;
	}

	return {};//返回optinal
}
#if 0
int main() {
	std::optional<std::string> data = ReadFileAsStrin_useOptional("data.txt");

	std::string value = data.value_or("Not present!");//如果数据存在，返回数据，否则返回我们传入value_or的值
	std::cout << value << std::endl;
	//更改返回值
	std::optional<int> count;
	int c = count.value_or(100);

	if (data.has_value()) {//如果为true,成功打开,也可以使用if(data),data对象中有一个bool运算符
		std::cout << "成功打开！" << std::endl;
		std::string& string = *data;//解引用，然后可以以普通字符串的形式访问
		std::string strings = data.value();//也是一种访问方法
	}
	else {
		std::cout << "打开失败！\n";
	}


	std::cin.get();
}
#endif