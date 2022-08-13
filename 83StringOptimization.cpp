#include<iostream>
#include<string>

//本节主题 小字符串优化(sso)


//不是很长的字符串,标准库并不会堆分配
//VS2019的小字符串分配的界限:如果一个字符串不超过15个字符,就不会在堆是分配内存,只会使用栈缓存区
//只在release模式下发生


#if 0
void* operator new(size_t size) {
	std::cout << "分配了" << size << "字节\n";
	return malloc(size);
}


int main() 
{
	std::string name = "1234567890abcdef";//没有堆分配开销,存储在静态分配的缓存区
	//如果超过15个字符，那么会先分配8字节,再分配32字节
	std::cin.get();
}

#endif