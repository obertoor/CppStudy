


//本节主题 堆和栈内存


struct Vector3
{
	float x, y, z;
	
	Vector3() 
		:x(10), y(20), z(30) {}
};


//堆和栈都在内存里，而不是缓存
//栈可以放在cpu缓存线
//即使用栈不会得到cache misses (缓存未命中）
#if 0
int main()
{
	//栈上分配内存
	//只需要一条cpu指令
	//生存周期在于一个｛｝内
	int value = 5;

	int array[2];
	array[0] = 1;
	array[1] = 2;
	Vector3 vector3;



	//堆上分配内存,栈指针的移动，一般来说，是从高内存向低内存移动
	//分配非常快
	//new调用malloc,调用底层函数分配内存
	//程序会维护空闲列表（free list）,用于追踪哪些内存块是空闲的以及其位置	 
	//mallloc就是去查找free list 然后得到一个大小大于等于要求的内存，然后给一个指针，之后记录分配大小，分配情况等等
	//如果请求超出free list的空间，程序会询问操作系统需要更多空间
	int* hvalue = new int;//栈指针移动4个字节（int）
	//解引用
	*hvalue = 5;

	int* harray = new int[2];
	harray[0] = 1;
	harray[1] = 2;

	Vector3* hvector = new Vector3();


	//delete也是只需要一条cpu指令
	delete harray;
	delete[] harray;
	delete hvector;


}

#endif