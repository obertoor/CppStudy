#include <iostream>



//��������  dynamic_cast	

//�����ڱ���ʱ��������ת��,����������ʱ,�������ص����гɱ�
//��̬����ת��
//�洢������ʱ������Ϣ(RTTI),�����Ҫrtti�Ǵ�״̬

//��һ����Ϸ��,��Entityʵ����,Enemy���˺�Player��Ҽ̳�ʵ����,dynamic_cast���Բ�ѯһ��ʵ����ȷ�����Ǻ�������,������ת��(Entity-Player)

class Entity
{
public:
	virtual void PrintName() {//ʹ�ø�����һ���麯����,������Ҫ��д�ĵط�,��ζ�����Ƕ�̬
		std::cout << "obeytoor" << std::endl;
	}
};

class Player:public Entity
{
public:
};

class Enemy :public Entity
{
public:
};
#if 0
int main() 
{
	Player* player = new Player;
	Entity* actuallyPlayer = player;
	Entity* actuallyEnemy = new Enemy;

	Entity* e1 = new Enemy;
	Player* p1 = (Player*)e1;//������Σ�յ�,e1��Ȼ��Enemy
	Player* p2 = dynamic_cast<Player*>(e1);//����ж�̬���,����null
	Player* p3 = dynamic_cast<Player*>(actuallyPlayer);
	Player* p4 = dynamic_cast<Player*>(actuallyEnemy); //����Null
	Enemy* e1 = dynamic_cast<Enemy*>(actuallyEnemy);
}
#endif