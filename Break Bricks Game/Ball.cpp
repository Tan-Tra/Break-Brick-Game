#include "Ball.h"


Ball::Ball()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 4;
	speed = BALL_SPEED;
	direction = STOP;
}

void Ball::setPosition(vector2D& pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Ball::setDirection(eDir dir)
{
	direction = dir;
}

vector2D Ball::getPosition()
{
	return position;
}

eDir Ball::getDirection()
{
	return direction;
}

void Ball::draw()
{
	gotoXY(position.x, position.y);
	cout << 'O';
}

void Ball::refill()
{
	gotoXY(position.x, position.y);
	cout << ' ';
}

void Ball::move()
{
	refill();
	switch (direction)
	{
	case LEFT:
		position.x -= speed;
		break;
	case RIGHT:
		position.x += speed;
		break;
	case UP:
		position.y -= speed;
		break;
	case DOWN:
		position.y -= speed;
		break;
	case UPLEFT:
		position.x -= speed;
		position.y -= speed;
		break;
	case DOWNLEFT:
		position.x -= speed;
		position.y += speed;
		break;
	case UPRIGHT:
		position.x += speed;
		position.y -= speed;
		break;
	case DOWNRIGHT:
		position.x += speed;
		position.y += speed;
		break;
	}
	draw();

}

void Ball::conllision(Map& map, Paddle& pad)
{
	switch (direction)
	{
	case LEFT:
		if (position.x <= 1)
		{
			position.x = 1;
			direction = RIGHT;
		}

		//if ()



		break;
	case RIGHT:
		position.x += speed;
		break;
	case UP:
		position.y -= speed;
		break;
	case DOWN:
		position.y -= speed;
		break;
	case UPLEFT:
		position.x -= speed;
		position.y -= speed;
		break;
	case DOWNLEFT:
		position.x -= speed;
		position.y += speed;
		break;
	case UPRIGHT:
		position.x += speed;
		position.y -= speed;
		break;
	case DOWNRIGHT:
		position.x += speed;
		position.y += speed;
		break;
	}
}

