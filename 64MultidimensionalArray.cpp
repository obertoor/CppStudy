#include<iostream>
#include<vector>


//本节主题 多维数组



/*二维数组： 得到指向一维数组指针的指针*/



#if 0
int main() {
	//本质是分配内存	
	int* array = new int[50];//array是一个指向整型指针,50个int,200个字节

	int** a2d = new int* [50]; //指向指针集合的指针，这是一个指向int指针的指针 

	//给指针数组分配int数组，分配了50*200字节的内存，
	for (int i = 0; i < 50; i++) {
		a2d[i] = new int[50];
	}

	//会造成内存泄漏，无法再访问到int数组
	//delete[][] a2d;



	//正确的delete  需先遍历delete
	for (int i = 0; i < 50; i++) {
		delete[] a2d[i];
	}
	delete[] a2d;
	//内存不连续，容易cache miss 缓存未命中，访问时间较长


	//更好的方法
	int* newarray=new int[5*5];
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			newarray[x + y * 5] = 2;
		}
	}
}
#endif