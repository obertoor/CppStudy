#include<iostream>
using namespace std;
//�������� ����

//ָ���ϵ��﷨��
//�������б����ķ�ʽ
//����Ϊ��

void Increment(int value) {
	value++;//������������ݣ������Ḵ��һ���µ�value
}

void PIncrement(int* value) {//����ָ��
	(*value)++;//�������ã��������Ե�ַ����+1
}

void RIncrement(int& value) {//������Ҫ�ں����ڲ��ı����
	value++;
}

#if 0
int main() {
	int a = 5;
	int b = 8;
	//�������� ���븳ֵ
	int& ref = a;//�����&���ǲ�����,�������͵�һ����,
	//ref =b;���Ǵ���ģ����ܸı�����
	// ���ִ�У������ a=8,b=8;
	//refֻ��һ������,�������ڱ����ĵĴ�����
	ref = 2;//��ref����aʹ��
	cout << a << endl;


	int* pref = &a;
	*pref = 2;
	pref = &b;
	*pref = 1;
	//a=2;b=1

	Increment(a);
	PIncrement(&a);//����ָ�룬����˵����a�ĵ�ַ
	RIncrement(a);//�ɹ��޸�a
}
#endif