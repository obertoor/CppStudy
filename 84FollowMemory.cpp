#include<iostream>
#include<string>
#include<memory>


//��������  �����ڴ�

#if 0
struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;


	uint32_t CurrentUsage() {
		return TotalAllocated - TotalFreed;
	}
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
	// std::cout << "������" << size << "�ֽ�\n";
	s_AllocationMetrics.TotalAllocated += size;
	return malloc(size);
}

void operator delete(void* memory,size_t size) {
	s_AllocationMetrics.TotalFreed += size;

	free(memory);
}

static void PrintMemoryUsage() {
	std::cout << "��ʹ���ڴ棺" << s_AllocationMetrics.CurrentUsage() << "bytes\n";
}
#endif



struct Object
{
	int x, y, z;
};
#if 0
int main() {
	PrintMemoryUsage();
	std::string name = "cherno";
	PrintMemoryUsage();
	//Object* obj = new Object;
	{
		std::unique_ptr<Object> obj = std::make_unique<Object>();
		PrintMemoryUsage();

	}
	PrintMemoryUsage();

	std::cin.get();
}
#endif