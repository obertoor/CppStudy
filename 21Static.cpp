#include<iostream>
#include <string>


//本节主题 static


//类或者结构体外使用static：只能对定义它的翻译单元可见
//类或者结构体内部使用static：静态变量，与类的所有实例共享，可以用于统计类的实例个数。


//只会在这个翻译单元链接，简单的说就是只在这个文件内起效，在编译时，哪怕其他文件有s_Variale这个名称的int变量，也不会影响。
static int s_Variale=5;

extern int extern_int;//extern标记会在外部去寻找定义。extern_int=5;需要同时编译

static void PrinName(std::string name) {
	std::cout << name << std::endl;
}

#if 0
int main() {
	PrinName("obeytoor");
	std::cout << extern_int << std::endl;
}
#endif
