


//�������� �Ѻ�ջ�ڴ�


struct Vector3
{
	float x, y, z;
	
	Vector3() 
		:x(10), y(20), z(30) {}
};


//�Ѻ�ջ�����ڴ�������ǻ���
//ջ���Է���cpu������
//��ʹ��ջ����õ�cache misses (����δ���У�
#if 0
int main()
{
	//ջ�Ϸ����ڴ�
	//ֻ��Ҫһ��cpuָ��
	//������������һ��������
	int value = 5;

	int array[2];
	array[0] = 1;
	array[1] = 2;
	Vector3 vector3;



	//���Ϸ����ڴ�,ջָ����ƶ���һ����˵���ǴӸ��ڴ�����ڴ��ƶ�
	//����ǳ���
	//new����malloc,���õײ㺯�������ڴ�
	//�����ά�������б�free list��,����׷����Щ�ڴ���ǿ��е��Լ���λ��	 
	//mallloc����ȥ����free list Ȼ��õ�һ����С���ڵ���Ҫ����ڴ棬Ȼ���һ��ָ�룬֮���¼�����С����������ȵ�
	//������󳬳�free list�Ŀռ䣬�����ѯ�ʲ���ϵͳ��Ҫ����ռ�
	int* hvalue = new int;//ջָ���ƶ�4���ֽڣ�int��
	//������
	*hvalue = 5;

	int* harray = new int[2];
	harray[0] = 1;
	harray[1] = 2;

	Vector3* hvector = new Vector3();


	//deleteҲ��ֻ��Ҫһ��cpuָ��
	delete harray;
	delete[] harray;
	delete hvector;


}

#endif