#include<iostream>
#include<string>
#include<vector>
#include<future>//包含async

//本节主题  多线程


//为什么不能传引用？
//线程函数的参数按值移动或复制。如果引用参数需要传递给线程函数，它必须被包装（例如使用std::ref或std::cref）

//std::async为什么一定要返回值？
//如果没有返回值，那么在一次for循环之后，临时对象会被析构，而析构函数中需要等待线程结束，所以就和顺序执行一样，一个个的等下去
//如果将返回值赋值给外部变量，那么生存期就在for循环之外，那么对象不会被析构，也就不需要等待线程结束。
#if 0
namespace my_79 {

	std::mutex mut;
	void PrintName() {
		std::lock_guard(mut);//这个锁的生命周期在该作用域内
		std::cout << "obeytoor\m";
	}
	void ForName(){

#define ASYNC 1
#if ASYNC
		for (int i = 0; i < 10; i++) {
			//async实际上返回一个future
			//需要保持这个future,否则这个临时的future在for的每一次迭代后就会摧毁
			auto fut=std::async(std::launch::async, PrintName);//第一个参数是任务类型(异步),第二个是要执行的函数
		}
#else
		for (int i = 0; i < 10; i++) {
			PrintName();
		}
#endif
	}
}
#endif