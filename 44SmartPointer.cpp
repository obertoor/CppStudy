#include<iostream>
#include<memory>
#include<string>


//本节主题 智能指针


//本质是原始指针的包装
//自动化delete的指针

//unique_ptr:作用域指针,不能复制,如果有复制了,那么两个unique_ptr会指向同一段内存,那么在指针销毁时会释放俩次

//shared_ptr:实现方式取决于编译器和编译器使用的标准库,使用引用计数(跟踪指针有多少个引用)
//该智能指针拥有一块内存,叫控制块,用于存储引用计数


//weak_ptr:弱指针,不会增加引用计数的shared_ptr,不影响所指对象生命周期

//operator=()	重载 = 赋值运算符，weak_ptr指针可以直接被weak_ptr或者shared_ptr类型指针赋值。
//swap(x)		其中x表示一个同类型的weak_ptr类型指针，该函数可以互换2个共同类型weak_ptr指针的内容。
//reset()		将当前weak_ptr指针置为空指针。
//use_count()	查看指向和当前weak_ptr指针相同的shared_ptr指针的数量。
//expired()		判断当前weak_ptr指针是否过期（指针为空，或者指向的堆内存已经被释放）。
//lock()		如果当前weak_ptr已经过期，则该函数会返回一个空的shared_ptr指针；反之，该函数返回一个和当前weak_ptr指针指向相同的shared_ptr指针


class Entity
{
public:
	Entity() {
		std::cout << "创建Entity" << std::endl;
	}
	~Entity() {
		std::cout << "销毁Entity" << std::endl;
	}
	void Print() {
		std::cout << "运行Entity中" << std::endl;
	}
};
#if 0
int main()
{
	std::shared_ptr<Entity> e0;
	std::weak_ptr<Entity> weakentity;
	{
		//std::unique_ptr<Entity> entity(new Entity());//需要显式的调用构造函数(explicit),可能得到悬空指针
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();//这种方式比较安全,遇到构造函数抛出异常会安全


		std::shared_ptr<Entity> shareentity = std::make_shared<Entity>();
		//引用计数加一,用new分配:本身内存以及控制块内存会分开分配,而使用make_shared则是一起分配
		weakentity = std::make_shared<Entity>();
		e0 = shareentity;


		entity->Print();
	}
	 

}
#endif 