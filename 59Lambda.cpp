#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

//�������� lambda

//lambda�����������Ƕ���һ�����������ķ�ʽ
//���ٵ�һ���Ժ���
//�ڿ����ú���ָ��ĵط�������lambda

void ForEach59(const vector<int>& values, void(*func)(int))//���ܺ���ָ��
{
	for (int value : values) {
		func(value);//���뺯��
	}
}
void ForEachs(const vector<int>& values, const function<void(int)>& func)//���ܺ���ָ��
{
	for (int value : values) {
		func(value);//���뺯��
	}
}



//�ص�����

#if 0
int main() {
	int a = 5;
	vector<int> values = { 1,2,3,4,5 };

	auto it =find_if(values.begin(), values.end(), [](int value) {return value > 3; });//���ɵ�����
	cout << *it << endl; //����4



	ForEach59(values, [](int value) {cout << value << endl; });//����lambda���ʽ
	//����ʹ��auto
	auto lambda = [](int value) {cout << value << endl; };//�ǲ����lambda������ʽ��ת��Ϊ����ָ��,�������lambda������
	auto lambda01= [a](int value) {cout << a << endl; };
	auto lambda02 = [=](int value) mutable  {a = 555; cout << a << endl; };//ʹ��mutab��������޸�ֵ���ݵı���
	ForEach59(values, lambda);
	ForEachs(values, lambda01);
	ForEachs(values, lambda02);

	// []�ǲ���,���Բ��������([=]��[&]�ǲ�������,=��ͨ������,&��ͨ������),��δ��ݱ���
}
#endif