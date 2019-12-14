﻿#pragma once
#include "Map.h"

#define PADDLE_SIZE 6
#define PADDLE_SPEED 3
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 5, UP = 3, UPRIGHT = 4, RIGHT = 2, DOWNRIGHT = 6, DOWN = 7, DOWNLEFT = 8 };// Khai báo kiểu liệt kê

class Paddle
{
private:
	vector2D position;
	eDir direction;

public:
	int size;	//khoảng cách từ giữa đến biên

	Paddle();
	~Paddle();
	void setPosition(vector2D& pos);
	void setDirection(eDir dir);
	vector2D getPosition();
	eDir getDirection();

	void moveLeft();
	void moveRight();

	void draw();
	void drawFill();
	void reset();
};

