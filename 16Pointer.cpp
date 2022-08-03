#include <iostream>
//本节主题 指针

//本质是一种存储内存地址的数字	



#if 0
int main() {
	int var = 8;
	void* pvar = &var;//&对一个变量名取地址，引用,&是一个操作符
	//调试看内存, 调试-窗口-内存-内存一

	int* pivar = &var;//有类型才能操作
	*pivar =50 ;//逆向引用，解引用

	char* buffer = new char[8];//分配八个字节的内存，返回一个指向该内存的指针
	memset(buffer, 0, 8);//填充内存函数

	char** pbuffer = &buffer;//双指针,从后往前看，是buffer的地址（大小端），小端

	delete[] buffer;

	void* ptr = NULL;//无类型指针,用nullptr更好
	//类型是用于操作内存
}

#endif