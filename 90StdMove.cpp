#include<iostream>


//本节主题  std::move与移动赋值操作符

//避免资源的重新分配(new)





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
	//拷贝构造函数
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


	//move构造函数,接受的是右值
	//实际上是接管原来的字符串
	String(String&& other) noexcept//不应该抛出异常
	{
		printf("移动!\n");
		m_Size = other.m_Size;
		//m_Data = new char[m_Size];//不是分配新的内存
		m_Data = other.m_Data;//新的指针，指向原来的内存
		//memcpy(m_Data, other.m_Data, m_Size);

		//防止原来的实例delete,把原来的指针置空
		//创建空对象
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	//移动赋值运算符
	String& operator=(String&& other) noexcept {
		//printf("移动赋值运算符!\n");
		if (this != &other) {
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;


			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		else {
			return *this;
		}
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




void func(int &n) {
	std::cout << "Lvalue:" << n << std::endl;
}
void func(int &&n) {
	std::cout << "Rvalue:" << n << std::endl;
}



//完美转发还能传递其是左值或者右值以及准确接收其左值右值
//万能引用
//引用折叠规则:(模板内生效)
//int& &&t => int& t
//int&& &&t => int&& t
template<typename T>
void revoke(T &&t)
{
	//forward<T>(t):如果T为左值引用,将t转换为T类型的左值
	//如果T为右值引用,将t转换为T类型的右值
	func(std::forward<T>(t));
	//func(std::move(t));//把t变成右值

	//func(t);
}




#if 0
int main() {

	int i = 10;
	int &m = i;
	int &&n = 100;


	//revoke(i);
	//revoke(10);

	revoke(static_cast<int&>(m));
	revoke(static_cast<int&&>(n));


	//Entity entity(String("Cherno"));
	//entity.PrintName();
	//创建，复制，都会发生，把String传递给entity的时候会复制Stirng

	//Entity entity("Cherno");
	//entity.PrintName();

	//String string = "Hello";
	//String dest = (String&&)string;
	//String dest((String&&)string);//效果同上	
	//String dest = std::move(string);


	String apple = "Apple";
	String dest;

	apple.Print();
	dest.Print();

	dest = std::move(apple);//apple的内容被移动到dest,apple变空  apple的内存变成了dest的内存
	//dest.operator=(std::move(apple));
	apple.Print();
	dest.Print();

	std::cin.get();
}
#endif