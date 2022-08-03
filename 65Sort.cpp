#include<iostream>
#include <vector>
#include <algorithm>
#include<functional>


//本节主题 排序


//sort(),void 复杂度都是N*logN
#if 0 
int main() {
	std::vector<int> values={3, 5, 1, 4, 2};

	std::sort(values.begin(), values.end());//默认升序排列

	std::sort(values.begin(), values.end(),std::greater<int>());//从大到小排序

	std::sort(values.begin(), values.end(), [](int a, int b) {
		//return a<b;//a排在前面,如果a小于b，那么a排在前面 ,升序
		//return a>b;//b排在前面，如果a大于b,   那么a排在前面 ,降序

		//如果a==1，那么a排到最后
		if (a == 1) {
			return false;
		}
		});
}
#endif