#include<iostream>
#include <vector>
#include <algorithm>
#include<functional>


//�������� ����


//sort(),void ���Ӷȶ���N*logN
#if 0 
int main() {
	std::vector<int> values={3, 5, 1, 4, 2};

	std::sort(values.begin(), values.end());//Ĭ����������

	std::sort(values.begin(), values.end(),std::greater<int>());//�Ӵ�С����

	std::sort(values.begin(), values.end(), [](int a, int b) {
		//return a<b;//a����ǰ��,���aС��b����ôa����ǰ�� ,����
		//return a>b;//b����ǰ�棬���a����b,   ��ôa����ǰ�� ,����

		//���a==1����ôa�ŵ����
		if (a == 1) {
			return false;
		}
		});
}
#endif