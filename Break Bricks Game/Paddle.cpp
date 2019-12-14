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
	direction = dir;
}

vector2D Paddle::getPosition()
{
	return position;
}

eDir Paddle::getDirection()
{
	return direction;
}

void Paddle::moveLeft()
{
	if (position.x - size > 1)
	{
		this->drawFill();
		position.x -= PADDLE_SPEED;
		if (position.x - size <= 1)
			position.x = size + 1;
		this->draw();
	}
}

void Paddle::moveRight()
{
	if (position.x + size < SCREEN_X-1)
	{
		this->drawFill();
		position.x += PADDLE_SPEED;
		if (position.x + size >= SCREEN_X - 1)
			position.x = SCREEN_X - size;
		this->draw();
	}
}

void Paddle::draw()
{
	gotoXY(position.x - size, position.y);
	for (int i = position.x - size; i < position.x + size; i++)
	{
		cout << "\xDB";
	}
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
}

void Paddle::drawFill()
{
	gotoXY(position.x - size, position.y);
	for (int i = position.x - size; i < position.x + size; i++)
	{
		cout << " ";
	}
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
}

void Paddle::reset()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 2;
}
