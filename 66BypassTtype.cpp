#include<iostream>


//本节主题  类型双关

//简而言之是绕过类型系统


struct Entity //如果为空结构体，则至少有1字节以便寻址
{
	int x, y;//此时为8字节大小

	int* GetPosition() {
		return &x;
	}
};

#if 0
int main()
{
	//a=50,valueA=50.0000
	//两者不在同一内存上
	int a = 50;
	double valueA = a;//带有隐式转换

	//原始方法的类型双关
	//大小不同，int4字节，double8字节，因此有4字节未初始化的内存
	int b = 50;
	//int指针装换为double指针
	double valueB = *(double*)&a;//&a 取a的地址，double*转换为double指针，最后*解引用
	double& valueBP = *(double*)&a;//创建引用而不是新变量，实际上这是将B当成double访问，而且内存只有4字节

	//原始的数组
	Entity e = { 5,8 };//此时在内存中有8字节内存，分别存储4和8
	int* position = (int*)&e;//position为int指针，取e地址，然后转换为int*
	std::cout << position[0] << "," << position[1] << std::endl;
	//输出5，8
	int y = *(int*)((char*)&e + 4);//输出8
	int* pos = e.GetPosition();
	pos[0] = 2;//修改x


}
#endif

