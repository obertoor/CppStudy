#include<iostream>
#include<vector>


//�������� ��ά����



/*��ά���飺 �õ�ָ��һά����ָ���ָ��*/



#if 0
int main() {
	//�����Ƿ����ڴ�	
	int* array = new int[50];//array��һ��ָ������ָ��,50��int,200���ֽ�

	int** a2d = new int* [50]; //ָ��ָ�뼯�ϵ�ָ�룬����һ��ָ��intָ���ָ�� 

	//��ָ���������int���飬������50*200�ֽڵ��ڴ棬
	for (int i = 0; i < 50; i++) {
		a2d[i] = new int[50];
	}

	//������ڴ�й©���޷��ٷ��ʵ�int����
	//delete[][] a2d;



	//��ȷ��delete  ���ȱ���delete
	for (int i = 0; i < 50; i++) {
		delete[] a2d[i];
	}
	delete[] a2d;
	//�ڴ治����������cache miss ����δ���У�����ʱ��ϳ�


	//���õķ���
	int* newarray=new int[5*5];
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			newarray[x + y * 5] = 2;
		}
	}
}
#endif