#include<iostream>
#include<string>
#include<vector>
#include<future>//����async

//��������  ���߳�


//Ϊʲô���ܴ����ã�
//�̺߳����Ĳ�����ֵ�ƶ����ơ�������ò�����Ҫ���ݸ��̺߳����������뱻��װ������ʹ��std::ref��std::cref��

//std::asyncΪʲôһ��Ҫ����ֵ��
//���û�з���ֵ����ô��һ��forѭ��֮����ʱ����ᱻ��������������������Ҫ�ȴ��߳̽��������Ծͺ�˳��ִ��һ����һ�����ĵ���ȥ
//���������ֵ��ֵ���ⲿ��������ô�����ھ���forѭ��֮�⣬��ô���󲻻ᱻ������Ҳ�Ͳ���Ҫ�ȴ��߳̽�����
#if 0
namespace my_79 {

	std::mutex mut;
	void PrintName() {
		std::lock_guard(mut);//����������������ڸ���������
		std::cout << "obeytoor\m";
	}
	void ForName(){

#define ASYNC 1
#if ASYNC
		for (int i = 0; i < 10; i++) {
			//asyncʵ���Ϸ���һ��future
			//��Ҫ�������future,���������ʱ��future��for��ÿһ�ε�����ͻ�ݻ�
			auto fut=std::async(std::launch::async, PrintName);//��һ����������������(�첽),�ڶ�����Ҫִ�еĺ���
		}
#else
		for (int i = 0; i < 10; i++) {
			PrintName();
		}
#endif
	}
}
#endif