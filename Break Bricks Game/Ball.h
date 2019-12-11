#pragma once
#include "Paddle.h"
#define BALL_SPEED 1


class Ball
{
private:
	vector2D position;
	float speed;
	eDir direction;
public:
	Ball();
	~Ball();
	void setPosition(vector2D& pos);
	void setPosition(int pos_y, int pos_x);
	void setDirection(eDir dir);
	vector2D getPosition();
	eDir getDirection();
	void draw();
	void printFill();
	void move();
	void conllision(Map& map, Paddle& pad);
	bool checkEndGame();
};

