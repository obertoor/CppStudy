#include<iostream>
#include<string>

using namespace std;
//本节主题 宏

//预处理器执行.纯文本替换
// 改变文本生成的方式
//发生在编译的预处理阶段


//如果处于debug模式下，有以下代码
//在属性-c++-预处理器-预处理定义一栏添加对应名称

#ifdef CS_DEBUG
//也可以定义CS_DEBUG=1(不能有空格）
//#if CS_DEBUG ==1

#define LOG(x) cout<<x<<endl;

#else
//或者
//#elif defined(CS_RELEASE)

#define LOG(x) 
//	切换回release模式，则什么都不输出

#endif // CS_DEBUG

//快速禁用代码
#if 0

#endif
//多行宏
#define MAIN int main()\
{\
	cin.get();\
}

#if 0
int main()
{

	LOG("hello");
	

}
#endif