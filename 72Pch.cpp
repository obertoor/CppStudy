//#include<iostream>


//本节主题  预编译头文件


//每次#include <vector>都要重新复制粘贴并编译
//接收一堆头文件,只编译一次,以二进制存储,大大加快编译速度
//不要将频繁改变的文件加入到预编译中,一旦有文件改变,整个预编译头文件会从头到尾去重新构建
//主要用于外部依赖(std,window.h....)



#if 0
//ctrl+f7 会生成72Pch.i的文件,里面包含37万行代码
int main() {
	std::cout << "Hello World" << std::endl;
}
#endif