#include<iostream>
#include<array>
//右键打开array文档
using namespace std;


//本节主题 静态数组	


//与vector不同，这是存储这栈中的
// 以下是相对于C语言数组的区别
// 增加调试功能，却没有性能成本
//在debug模式下会有边界检查，而这release模式下没有
//实际是array类不存储大小，其size函数就是直接返回参数


template<typename T>//array<int,5>
void PrintArray(const T& data) {
	for (int i = 0; i < data.size(); i++) {

	}
}
#if 0
int main() {
	array<int, 5> data; 
	data.size();
	data[0] = 0;
	data[4] = 4;





	//C语言风格
	int dataOld[5];
	dataOld[0] = 0;
	dataOld[4] = 4;

}
#endif