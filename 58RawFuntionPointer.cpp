#include<iostream>
#include<vector>
using namespace std;
//�������� ����ָ��


//��һ��������ֵ��һ�������ķ���
//��������Ϊ�������ݸ���һ������


//�����ᱻ�����cpuָ�����ִ���ļ�������ָ���ȡ��Щcpuָ����ڴ��ַ

void HelloWorld() {
	cout << "HelloWorld" << endl;
}
void HelloWorlds(int a) {
	cout << "HelloWorld! value:" <<a<< endl;
}

void PrintValue(int value) {
	cout << value << endl;
}

void ForEach(const vector<int>& values,void(*func)(int))//���ܺ���ָ��
{
	for (int value : values) {
		func(value);//���뺯��
	}
}
#if 0
int main() {
	auto funtion = HelloWorld;//��ȡ����ָ�룬����&helloworld���õ��������ڴ��ַ 

	//��һ�ֻ�ȡ����ָ��ķ�ʽ
	void(*otherfuntion)();//()�Ų����б�int��
	otherfuntion = HelloWorld;

	//����һ�ֻ�ȡ����ָ��ķ�ʽ
	typedef	void(*HelloWorldFuntion)(int);
	HelloWorldFuntion anthorfuntion = HelloWorlds;

	anthorfuntion(8);
	//���������helloworld
	funtion();
	funtion();

	vector<int> values = { 1,5,4,2,3 };
	ForEach(values, PrintValue);
	//lambda,������һ����ͨ���������������ɣ����꼴��
	ForEach(values, [](int value) {cout << value << endl; });


}
#endif