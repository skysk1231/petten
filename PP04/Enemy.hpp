#include <iostream>
#include <string>

class Enemy
{
public:
	int x = 50, y;
	
	Enemy()
	{
		y = 7;
	}
	~Enemy()
	{

	}
	void EnemyMove()
	{
		x--;
		if (x == 0)
		{
			x = 50;
		}
	}
};
#pragma once
