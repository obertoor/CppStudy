#include<iostream>
//�������� ��װ������������adapter����



template<typename T, typename F>
T use_f(T v,F f)
{
	static int count = 0;
	count++;

	std::cout << "use_f count = " << count
		<< ", &count = " << &count << std::endl;
	return f(v);
}

