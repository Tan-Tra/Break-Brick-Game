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

void Ball::printFill()
{
	gotoXY(position.x, position.y);
	cout << ' ';
}

void Ball::move()
{
	printFill();
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
	vector2D p;
	switch (direction)
	{
	case LEFT:
		//cham tuong
		if (position.x <= 1)
		{
			position.x = 1;
			direction = RIGHT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y][position.x - i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x - i;
					p.y = position.y;
					this->setPosition(p);
					printFill();
					direction = RIGHT;
					map.data[position.y][position.x - i]--;
					break;

				case 2:
					p.x = position.x - i + 1;
					p.y = position.y;
					this->setPosition(p);
					direction = RIGHT;
					map.data[position.y][position.x - i]--;
					//chinh mau
					break;

				case 7:
					p.x = position.x - i + 1;
					p.y = position.y;
					this->setPosition(p);
					direction = RIGHT;
					break;

				}
			}
		}

		break;
	case RIGHT:
		//cham tuong
		if (position.x >= SCREEN_X - 1)
		{
			position.x = SCREEN_X - 1;
			direction = LEFT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y][position.x + i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x + i;
					p.y = position.y;
					this->setPosition(p);
					printFill();
					direction = LEFT;
					map.data[position.y][position.x + i]--;
					break;

				case 2:
					p.x = position.x + i - 1;
					p.y = position.y;
					this->setPosition(p);
					direction = LEFT;
					map.data[position.y][position.x + i]--;
					break;

				case 7:
					p.x = position.x + i - 1;
					p.y = position.y;
					this->setPosition(p);
					direction = LEFT;
					break;

				}
			}
		}

		break;
	case UP:
		//cham tuong
		if (position.y <= 1)
		{
			position.y = 1;
			direction = DOWN;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y - i][position.x])
				{
				case 0:
					break;
				case 1:
					p.x = position.x;
					p.y = position.y - i;
					this->setPosition(p);
					printFill();
					direction = DOWN;
					map.data[position.y - i][position.x]--;
					break;

				case 2:
					p.x = position.x;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = DOWN;
					map.data[position.y - i][position.x]--;
					break;

				case 7:
					p.x = position.x;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = DOWN;
					break;

				}
			}
		}

		break;
	case DOWN:

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y + i][position.x])
				{
				case 0:
					break;
				case 1:
					p.x = position.x;
					p.y = position.y + i;
					this->setPosition(p);
					printFill();
					direction = UP;
					map.data[position.y + i][position.x]--;
					break;

				case 2:
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UP;
					map.data[position.y + i][position.x]--;
					break;

				case 7:
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UP;
					break;

				}
			}
		}
		//cham paddle
		else
		{
			for (int i = 0; i < speed; i++)
			{
				if (position.y + i == pad.getPosition().y && (position.x >= pad.getPosition().x - pad.size && position.x <= pad.getPosition().x + pad.size))
				{
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UP;
				}
			}
		}
		break;
	case UPLEFT:
		//cham tuong
		if (position.x <= 1)
		{
			position.x = 1;
			direction = UPRIGHT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y - i][position.x - i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x - i;
					p.y = position.y - i;
					this->setPosition(p);
					printFill();
					direction = (map.data[position.y - i][position.x - i + 1] == 0 && map.data[position.y - i + 1][position.x - i] == 0) ? DOWNRIGHT : UPRIGHT;
					map.data[position.y - i][position.x - i]--;
					break;

				case 2:
					p.x = position.x - i + 1;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = (map.data[position.y - i][position.x - i + 1] == 0 && map.data[position.y - i + 1][position.x - i] == 0) ? DOWNRIGHT : UPRIGHT;
					map.data[position.y - i][position.x - i]--;
					break;

				case 7:
					p.x = position.x - i + 1;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = (map.data[position.y - i][position.x - i + 1] == 0 && map.data[position.y - i + 1][position.x - i] == 0) ? DOWNRIGHT : UPRIGHT;
					break;

				}
			}
		}

		break;
	case DOWNLEFT:
		//cham tuong
		if (position.x <= 1)
		{
			position.x = 1;
			direction = DOWNRIGHT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y + i][position.x - i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x - i;
					p.y = position.y + i;
					this->setPosition(p);
					printFill();
					direction = (map.data[position.y + i - 1][position.x - i] == 0 && map.data[position.y + i][position.x - i + 1] == 0) ? UPRIGHT : DOWNRIGHT;
					map.data[position.y + i][position.x - i]--;
					break;

				case 2:
					p.x = position.x - i + 1;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = (map.data[position.y + i - 1][position.x - i] == 0 && map.data[position.y + i][position.x - i + 1] == 0) ? UPRIGHT : DOWNRIGHT;
					map.data[position.y + i][position.x - i]--;
					break;

				case 7:
					p.x = position.x - i + 1;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = (map.data[position.y + i - 1][position.x - i] == 0 && map.data[position.y + i][position.x - i + 1] == 0) ? UPRIGHT : DOWNRIGHT;
					break;

				}
			}
		}
		//cham paddle
		else
		{
			for (int i = 0; i < speed; i++)
			{
				if (position.y + i == pad.getPosition().y && (position.x >= pad.getPosition().x - pad.size && position.x <= pad.getPosition().x + pad.size))
				{
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UPLEFT;
				}
			}
		}
		break;
	case UPRIGHT:
		//cham tuong
		if (position.x >= SCREEN_X - 1)
		{
			position.x = SCREEN_X - 1;
			direction = UPLEFT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y - i][position.x + i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x + i;
					p.y = position.y - i;
					this->setPosition(p);
					printFill();
					direction = (map.data[position.y - i][position.x + i - 1] == 0 && map.data[position.y - i + 1][position.x + i] == 0) ? DOWNLEFT : UPLEFT;
					map.data[position.y - i][position.x + i]--;
					break;

				case 2:
					p.x = position.x + i - 1;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = (map.data[position.y - i][position.x + i - 1] == 0 && map.data[position.y - i + 1][position.x + i] == 0) ? DOWNLEFT : UPLEFT;
					map.data[position.y - i][position.x + i]--;
					break;

				case 7:
					p.x = position.x + i - 1;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = (map.data[position.y - i][position.x + i - 1] == 0 && map.data[position.y - i + 1][position.x + i] == 0) ? DOWNLEFT : UPLEFT;
					break;

				}
			}
		}
		break;
	case DOWNRIGHT:
		//cham tuong
		if (position.x >= SCREEN_X - 1)
		{
			position.x = SCREEN_X - 1;
			direction = DOWNLEFT;
		}

		//cham gach
		if (position.y < 15)
		{
			for (int i = 0; i < speed; i++)
			{
				switch (map.data[position.y + i][position.x + i])
				{
				case 0:
					break;
				case 1:
					p.x = position.x + i;
					p.y = position.y + i;
					this->setPosition(p);
					printFill();
					direction = (map.data[position.y + i - 1][position.x + i] == 0 && map.data[position.y + i][position.x + i - 1] == 0) ? UPLEFT : DOWNLEFT;
					map.data[position.y + i][position.x + i]--;
					break;

				case 2:
					p.x = position.x + i - 1;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = (map.data[position.y + i - 1][position.x + i] == 0 && map.data[position.y + i][position.x + i - 1] == 0) ? UPLEFT : DOWNLEFT;
					map.data[position.y + i][position.x + i]--;
					break;

				case 7:
					p.x = position.x + i - 1;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = (map.data[position.y + i - 1][position.x + i] == 0 && map.data[position.y + i][position.x + i - 1] == 0) ? UPLEFT : DOWNLEFT;
					break;

				}
			}
		}
		//cham paddle
		else
		{
			for (int i = 0; i < speed; i++)
			{
				if (position.y + i == pad.getPosition().y && (position.x >= pad.getPosition().x - pad.size && position.x <= pad.getPosition().x + pad.size))
				{
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UPRIGHT;
				}
			}
		}
		break;
	}
}


