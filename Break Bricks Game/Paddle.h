#pragma once
#include "Map.h"

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, UP = 3, UPRIGHT = 4, RIGHT = 5, DOWNRIGHT = 6, DOWN = 7, DOWNLEFT = 8 };// Khai báo kiểu liệt kê

class Paddle
{
private:
	vector2D position;


public:
	Paddle();
	~Paddle();
	void setPosition(vector2D& pos);
	void setDirection(eDir dir);
	vector2D getPosition();
	eDir getDirection();
};

