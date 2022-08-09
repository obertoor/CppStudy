#include<iostream>
#include<any>


//本节主题  any


//C++17新特性
//存储任意类型的数据

//对于小类型是variant,对于大类型是void*,此时会动态分配内存

//测试内存分配
#if 0
void* operator new(size_t size){
	return malloc(size);
}
#endif

//超过32字节
struct CustomClass
{
	std::string a, b; //56字节
};
#if 0
int main() {

	//初始化
	std::any data01;
	std::cout <<"data01大小为" << sizeof(data01) << "\n";//大小为40
	data01 = 2;
	data01 = "Cherno";
	std::cout << "data01大小为" << sizeof(data01) << "\n";
	data01 = std::string("Cherno");//出现内存分配
	data01 = CustomClass();//出现内存分配


	//读取string,无法转换则抛出类型转换异常,
	data01 = std::string("Cherno");
	std::string str01=std::any_cast<std::string>(data01);
	std::string& str02 = std::any_cast<std::string&>(data01);//避免复制


}
#endif