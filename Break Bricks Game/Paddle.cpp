#include "Paddle.h"

Paddle::Paddle()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 2;
	size = PADDLE_SIZE;
}

Paddle::~Paddle()
{
}

void Paddle::setPosition(vector2D& pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Paddle::setDirection(eDir dir)
{
	
}

vector2D Paddle::getPosition()
{
	return this->position;
}

eDir Paddle::getDirection()
{
	return eDir();
}

void Paddle::moveLeft()
{
	position.x--;
}

void Paddle::moveRight()
{
	position.x++;
}

void Paddle::draw()
{
	gotoXY(position.x - size, SCREEN_Y);
	for (int i = position.x-size; i <position.x+size ; i++)
	{
		cout << "\xDB";
	}
}

void Paddle::drawFill()
{
	gotoXY(position.x - size, SCREEN_Y);
	for (int i = position.x - size; i < position.x + size; i++)
	{
		cout << " ";
	}
}
