#include<iostream>


//本节主题  左值与右值

//左值: 某种存储支持的变量
//右值：临时值

//左值引用与右值引用的本质都是左值

#if 0
//返回一个右值，是临时的
int GetValue01() {
	return 10;
}



//左值引用	
int& GetValue02() {
	static int value = 10;	
	return value;
}


//使用const 可以接受左值或者右值的引用
//右值引用是通过创建一个临时的temp，实际上仍然是左值引用
void SetValue(const int& value) {

}

static void PrintName(std::string& name) {
	std::cout <<"Lvalue" << name << std::endl;
}

//使用&& 可以使得该函数只接受右值（临时对象）
//临时对象不用担心复制，生存周期等
static void PrintName(std::string&& name) {
	std::cout <<"Rvalue:" << name << std::endl;
}




int main()
{
	//大部分情况下，左值在左，右值在右
	int i = 10;
	//例外
	int a = i;


	GetValue02() = 20;

	//可以接受右值引用
	SetValue(10);

	
	std::string firstname = "weng";
	std::string lasttname = "jiahao";
	//右边的表达式是右值，这两个字符串组成一个临时字符串，然后赋值给左值
	std::string fullname = firstname + lasttname;
	PrintName(fullname);
	//无法调用，除非PrintName是接受const string&  或者 string&&
	PrintName(firstname + lasttname);




	std::cin.get();
}
#endif