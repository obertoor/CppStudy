#include<iostream>


//�������� ������



//����ͬ������ϵ����
//����ʹ���鷽��
//����union�����г�Ա����

struct Vector2
{
	float x, y;
};

struct Vector4
{
	float x, y, z, w;
	Vector2& GetA() {//����ָ��Vector2������
		return *(Vector2*)&x;//ȡx�ĵ�ַ��ת��ΪVectorָ�룬Ȼ�������
	}
};

//ʹ��Union
struct UnVector4
{
	union 
	{
		//a��xy�ڴ���ͬ��b��zw�ڴ���ͬ
		//float x, y, z, w;//��������xyzwռ����ͬ�ռ�
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
		//��������union���봴�������ṹ����ͬ
		union
		{
			float a;
			int b;
		};
	};
	Union u;
	u.a = 2.0f;
	std::cout << u.a << "," << u.b << std::endl;\
	//���2 �Լ� 107......
	//�����ȡa���ڴ棬�������Ϊint

	UnVector4 vector ={1.0f,2.0f,3.0f,4.0f};
	vector.x = 2.0f;
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 500.0f;
	PrintVector2(vector.b);

}
#endif