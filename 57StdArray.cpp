#include<iostream>
#include<array>
//�Ҽ���array�ĵ�
using namespace std;


//�������� ��̬����	


//��vector��ͬ�����Ǵ洢��ջ�е�
// �����������C�������������
// ���ӵ��Թ��ܣ�ȴû�����ܳɱ�
//��debugģʽ�»��б߽��飬����releaseģʽ��û��
//ʵ����array�಻�洢��С����size��������ֱ�ӷ��ز���


template<typename T>//array<int,5>
void PrintArray(const T& data) {
	for (int i = 0; i < data.size(); i++) {

	}
}
#if 0
int main() {
	array<int, 5> data; 
	data.size();
	data[0] = 0;
	data[4] = 4;





	//C���Է��
	int dataOld[5];
	dataOld[0] = 0;
	dataOld[4] = 4;

}
#endif