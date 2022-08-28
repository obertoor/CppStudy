#include<iostream>




//本节主题  移动语义

#if 0
class String {
public:
	String() = default;
	String(const char* string)
	{
		printf("构造!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	//拷贝构造函数,深拷贝
	String(const String& other)
	{
		printf("复制!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	//noexcept
	//如果一个函数中调用的其他函数都为noexcept，即便这个函数未声明为noexcept，也具有noexcept的效果；
	//如果一个noexcept函数中，抛出了异常，则程序直接在函数异常处终止，函数外部的资源不会显式的释放；


	//move构造函数,接受的是右值,这是移动构造函数
	//实际上是接管原来的字符串
	String(String&& other) noexcept//不应该抛出异常
	{
		printf("移动!\n");
		m_Size = other.m_Size;
		//m_Data = new char[m_Size];//不是分配新的内存
		m_Data = other.m_Data;//新的指针，指向原来的内存
		//memcpy(m_Data, other.m_Data, m_Size);

		//防止原来的实例delete,把原来的指针置空(野指针)
		//创建空对象
		other.m_Size = 0;
		other.m_Data = nullptr;
	}


	~String() {
		printf("析构!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++) {
			printf("%c", m_Data[i]);
		}
		printf("\n");

	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity {
public:
	Entity(const String& name)
		:m_Name(name)
	{

	}
	Entity(String&& name)
		:m_Name((String&&)name)//将其显式的声明为临时对象 
		//:m_Name(std::move(name));//效果同上
	{

	}

	void PrintName() {
		m_Name.Print();
	}
private:
	String m_Name;
	//移动语义是为了将在main中创建的String直接放到这里的内存，而不是复制传递进来，再设置m_Names
};


int main() {
	//Entity entity(String("Cherno"));
	//entity.PrintName();
	//创建，复制，都会发生，把String传递给entity的时候会复制Stirng

	Entity entity("Cherno");
	entity.PrintName();

	std::cin.get();
}
#endif