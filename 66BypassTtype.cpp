#include<iostream>


//��������  ����˫��

//�����֮���ƹ�����ϵͳ


struct Entity //���Ϊ�սṹ�壬��������1�ֽ��Ա�Ѱַ
{
	int x, y;//��ʱΪ8�ֽڴ�С

	int* GetPosition() {
		return &x;
	}
};

#if 0
int main()
{
	//a=50,valueA=50.0000
	//���߲���ͬһ�ڴ���
	int a = 50;
	double valueA = a;//������ʽת��

	//ԭʼ����������˫��
	//��С��ͬ��int4�ֽڣ�double8�ֽڣ������4�ֽ�δ��ʼ�����ڴ�
	int b = 50;
	//intָ��װ��Ϊdoubleָ��
	double valueB = *(double*)&a;//&a ȡa�ĵ�ַ��double*ת��Ϊdoubleָ�룬���*������
	double& valueBP = *(double*)&a;//�������ö������±�����ʵ�������ǽ�B����double���ʣ������ڴ�ֻ��4�ֽ�

	//ԭʼ������
	Entity e = { 5,8 };//��ʱ���ڴ�����8�ֽ��ڴ棬�ֱ�洢4��8
	int* position = (int*)&e;//positionΪintָ�룬ȡe��ַ��Ȼ��ת��Ϊint*
	std::cout << position[0] << "," << position[1] << std::endl;
	//���5��8
	int y = *(int*)((char*)&e + 4);//���8
	int* pos = e.GetPosition();
	pos[0] = 2;//�޸�x


}
#endif

