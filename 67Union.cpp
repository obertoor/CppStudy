#include<iostream>


//本节主题 联合体



//将不同类型联系起来
//不能使用虚方法
//匿名union不能有成员函数

struct Vector2
{
	float x, y;
};

struct Vector4
{
	float x, y, z, w;
	Vector2& GetA() {//返回指向Vector2的引用
		return *(Vector2*)&x;//取x的地址，转换为Vector指针，然后解引用
	}
};

//使用Union
struct UnVector4
{
	union 
	{
		//a与xy内存相同，b与zw内存相同
		//float x, y, z, w;//这样会让xyzw占用相同空间
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a,b;
		};
	};

};
#if 0
void PrintVector2(const Vector2& vector) {
	std::cout << vector.x << "," << vector.y << std::endl;
}





int main()
{
	struct Union
	{
		//创建匿名union，与创建匿名结构体相同
		union
		{
			float a;
			int b;
		};
	};
	Union u;
	u.a = 2.0f;
	std::cout << u.a << "," << u.b << std::endl;\
	//输出2 以及 107......
	//就像读取a的内存，将其解释为int

	UnVector4 vector ={1.0f,2.0f,3.0f,4.0f};
	vector.x = 2.0f;
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 500.0f;
	PrintVector2(vector.b);

}
#endif