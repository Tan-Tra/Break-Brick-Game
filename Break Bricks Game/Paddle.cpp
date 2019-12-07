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
}

void Paddle::setDirection(eDir dir)
{
}

vector2D Paddle::getPosition()
{
	return vector2D();
}

eDir Paddle::getDirection()
{
	return eDir();
}
