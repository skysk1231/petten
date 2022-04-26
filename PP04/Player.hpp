#include <iostream>
#include <string>
#include "Enemy.hpp"

class Player
{
public : 
	Enemy e;
	bool c = false;
	int x, y;
	Player()
	{
		x = 20;
		y = 7;
		//check();
	}
	~Player()
	{

	}

	/*void check()
	{
		if (e.x == x && e.y == y)
		{
			c = true;
		}
	}*/

};
