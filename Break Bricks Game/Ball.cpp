#include "Ball.h"


Ball::Ball()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 3;
	speed = BALL_SPEED;
	direction = STOP;
}

Ball::~Ball()
{
}

void Ball::setPosition(vector2D& pos)
{
	position.x = pos.x;
	position.y = pos.y;
}

void Ball::setPosition(int pos_y, int pos_x)
{
	position.y = pos_y;
	position.x = pos_x;
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
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
}

void Ball::printFill()
{
	gotoXY(position.x, position.y);
	cout << ' ';
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
}

void Ball::move()
{
	printFill();
	switch (direction)
	{
	case LEFT:
		position.x -= (int)speed;
		break;
	case RIGHT:
		position.x += (int)speed;
		break;
	case UP:
		position.y -= (int)speed;
		break;
	case DOWN:
		position.y += (int)speed;
		break;
	case UPLEFT:
		position.x -= (int)speed;
		position.y -= (int)speed;
		break;
	case DOWNLEFT:
		position.x -= (int)speed;
		position.y += (int)speed;
		break;
	case UPRIGHT:
		position.x += (int)speed;
		position.y -= (int)speed;
		break;
	case DOWNRIGHT:
		position.x += (int)speed;
		position.y += (int)speed;
		break;
	}
	draw();

}

void Ball::conllision(Map& map, Paddle& pad)
{
	vector2D p;
	switch (direction)
	{
	case UP:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.y - i <= 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWN;
				this->draw();
				return;
			}

			//cham gach
			if (position.y-i < 16)
			{

				switch (map.data[position.y - 1 - i][(position.x - 1)/4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y - 1 - i][(position.x - 1) / 4]--;
				
				case 7:
					this->printFill();
					p.x = position.x;
					p.y = position.y - i+1;
					this->setPosition(p);
					direction = DOWN;
					this->draw();
					return;

				}
			}
		}

		break;
	case DOWN:

		for (int i = 1; i <= speed; i++)
		{
			//cham gach
			if (position.y+i < 16)
			{

				switch (map.data[position.y + i-1][(position.x - 1)/4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y + i - 1][(position.x - 1) / 4]--;

				case 7:
					
					this->printFill();
					p.x = position.x;
					p.y = position.y + i-1;
					this->setPosition(p);
					printFill();
					direction = UP;
					this->draw();
					return;
				}
			}

			//cham paddle
			else
			{

				if (position.y + i == pad.getPosition().y && (position.x >= pad.getPosition().x - pad.size && position.x <= pad.getPosition().x + pad.size))
				{
					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					switch (pad.getDirection())
					{
					case STOP:
						direction = UP;
						break;
					case LEFT:
						direction = UPLEFT;
						break;
					case RIGHT:
						direction = UPRIGHT;
						break;
					}

					this->draw();
					i = speed;
					if (speed < BALL_SPEED_MAX)
						speed *= 1.1;
					break;

				}
			}
		}
		break;
	case UPLEFT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x - i <= 1 && position.y - i <= 1)
			{
				this->printFill();
				position.x = 1;
				position.y = 1;
				direction = DOWNRIGHT;
				this->draw();
				return;
			}

			if (position.x - i <= 1)
			{
				this->printFill();
				position.x = 1;
				direction = UPRIGHT;
				this->draw();
				return;
			}

			if (position.y - i <= 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNLEFT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y-i < 16)
			{

				switch (map.data[position.y - i-1][(position.x - i - 1)/4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y - i - 1][(position.x - i - 1) / 4]--;
				case 7:
					this->printFill();
					p.x = position.x - i+1;
					p.y = position.y - i+1;
					if ((map.data[position.y - i-1][(position.x - i - 1) / 4 + 1] == 0) == (map.data[position.y - i - 1 +1][(position.x - i - 1) / 4] == 0))
						direction = DOWNRIGHT;
					else if (map.data[position.y - i - 1][(position.x - i - 1) / 4 + 1] == 0)
						direction = UPRIGHT;
					else
						direction = DOWNLEFT;
					this->setPosition(p);
					this->draw();
					return;

				}
			}
		}

		break;
	case DOWNLEFT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x - i <= 1)
			{
				this->printFill();
				position.x = 1;
				direction = DOWNRIGHT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y+i < 16)
			{

				switch (map.data[position.y + i-1][(position.x - i - 1)/4])
				{
				case 0:
					break;
				case 1:

				case 2:
					map.data[position.y + i - 1][(position.x - i - 1) / 4]--;

				case 7:
					this->printFill();
					p.x = position.x - i+1;
					p.y = position.y + i-1;
					if ((map.data[position.y + i - 1][(position.x - i - 1) / 4+1] == 0) == (map.data[position.y + i - 1-1][(position.x - i - 1) / 4] == 0))
						direction = UPRIGHT;
					else if (map.data[position.y + i - 1][(position.x - i - 1) / 4 + 1] == 0)
						direction = DOWNRIGHT;
					else
						direction = UPLEFT;
					this->setPosition(p);
					this->draw();
					return;

				}
			}

			//cham paddle
			else
			{

				if (position.y + i == pad.getPosition().y && (position.x - i >= pad.getPosition().x - pad.size && position.x - i <= pad.getPosition().x + pad.size))
				{
					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					switch (pad.getDirection())
					{
					case STOP:
						direction = UP;
						break;
					case LEFT:
						direction = UPLEFT;
						break;
					case RIGHT:
						direction = UPRIGHT;
						break;
					}
					this->draw();
					i = speed;
					if (speed < BALL_SPEED_MAX)
						speed *= 1.1;
					break;
				}

			}
		}
		break;
	case UPRIGHT:

		for (int i = 1; i <= speed; i++)
		{

			//cham tuong
			if (position.x + i >= SCREEN_X - 1 && position.y - i <= 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				position.y = 1;
				direction = DOWNLEFT;
				this->draw();
				return;
			}

			if (position.x + i >= SCREEN_X - 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				direction = UPLEFT;
				this->draw();
				return;

			}

			if (position.y - i <= 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNRIGHT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y-i < 16)
			{

				switch (map.data[position.y - i-1][(position.x + i - 1)/4])
				{
				case 0:
					break;
				case 1:
					
				case 2:
			
					map.data[position.y - i - 1][(position.x + i - 1) / 4]--;
				case 7:
					this->printFill();
					p.x = position.x + i-1;
					p.y = position.y - i+1;
					if ((map.data[position.y - i - 1][(position.x + i - 1) / 4-1] == 0) == (map.data[position.y - i - 1+1][(position.x + i - 1) / 4] == 0))
						direction = DOWNLEFT;
					else if (map.data[position.y - i - 1][(position.x + i - 1) / 4 - 1] == 0)
						direction = UPLEFT;
					else
						direction = DOWNRIGHT;
					this->setPosition(p);
					this->draw();
					return;

				}

			}
		}
		break;
	case DOWNRIGHT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x + i >= SCREEN_X - 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				direction = DOWNLEFT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y+i < 16)
			{

				switch (map.data[position.y + i-1][(position.x + i - 1)/4])
				{
				case 0:
					break;
				case 1:
					
				case 2:
					map.data[position.y + i - 1][(position.x + i - 1)/4]--;
				case 7:
					this->printFill();
					p.x = position.x + i-1;
					p.y = position.y + i-1;
					if ((map.data[position.y + i - 1][(position.x + i - 1) / 4-1] == 0) == (map.data[position.y + i - 1-1][(position.x + i - 1) / 4] == 0))
						direction = UPLEFT;
					else if (map.data[position.y + i - 1][(position.x + i - 1) / 4 - 1] == 0)
						direction = DOWNLEFT;
					else
						direction = UPRIGHT;
					this->setPosition(p);
					this->draw();
					return;

				}

			}
			//cham paddle
			else
			{

				if (position.y + i == pad.getPosition().y && (position.x + i >= pad.getPosition().x - pad.size && position.x + i <= pad.getPosition().x + pad.size))
				{
					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					switch (pad.getDirection())
					{
					case STOP:
						direction = UP;
						break;
					case LEFT:
						direction = UPLEFT;
						break;
					case RIGHT:
						direction = UPRIGHT;
						break;
					}
					this->draw();
					i = speed;
					if (speed < BALL_SPEED_MAX)
						speed *= 1.1;
					break;
				}

			}

		}
		break;
	}
}


