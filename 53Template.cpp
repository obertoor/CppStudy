#include<iostream>
#include<string>

using namespace std;
//�������� ģ��

//ģ�����ñ���������д����
//���û�õ���Print��������ô��������Ͳ�����ڣ���ʱPrint�������д���Ҳ���ᱨ��(msvc��������
template<typename T>
//template<class T> ����һ�д�����ͬ
void Print(T value) 
{
	cout << value << endl;
}

//ģ���������ϵ����
template<typename T, int N>
class Array
{
private:
	//���һ������ΪT������
	T m_Array[N];
public:
	int GetSize() const
	{
		return N;
	}
};

//int main()
//{
//	//ָ������
//	Print<int>(4);
//	//��ʽ�Ļ�ò�������
//	Print(5);
//	Print("string");
//	Print(5.04f);
//
//	Array<char,5> array;
//	cout << array.GetSize() << endl;
//
//
//
//	cin.get();
//}


