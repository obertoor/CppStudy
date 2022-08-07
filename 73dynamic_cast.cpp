#include <iostream>



//本节主题  dynamic_cast	

//不是在编译时进行类型转换,而是在运行时,因此有相关的运行成本
//动态类型转换
//存储了运行时类型信息(RTTI),因此需要rtti是打开状态

//在一个游戏中,有Entity实体类,Enemy敌人和Player玩家继承实体类,dynamic_cast可以查询一个实体类确定其是何种类型,并将其转换(Entity-Player)

class Entity
{
public:
	virtual void PrintName() {//使得该类有一个虚函数表,有了需要重写的地方,意味着这是多态
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
	Player* p1 = (Player*)e1;//这样是危险的,e1仍然是Enemy
	Player* p2 = dynamic_cast<Player*>(e1);//会进行多态检查,返回null
	Player* p3 = dynamic_cast<Player*>(actuallyPlayer);
	Player* p4 = dynamic_cast<Player*>(actuallyEnemy); //返回Null
	Enemy* e1 = dynamic_cast<Enemy*>(actuallyEnemy);
}
#endif