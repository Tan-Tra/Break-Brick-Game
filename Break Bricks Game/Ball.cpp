#include "Ball.h"


Ball::Ball()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 4;
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

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x - i <= 1)
			{
				this->printFill();
				position.x = 1;
				direction = RIGHT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y][position.x - i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x - i;
					p.y = position.y;
					this->setPosition(p);
					printFill();
					direction = RIGHT;
					this->draw();
					map.data[p.y][p.x - 1]--;
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y;
					this->setPosition(p);
					direction = RIGHT;
					this->draw();
					map.data[p.y][p.x - 1 - 1]--;
					i = speed;
					//chinh mau
					break;

				case 7:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y;
					this->setPosition(p);
					direction = RIGHT;
					this->draw();
					i = speed;
					break;

				}

			}
		}
		break;
	case RIGHT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x + i >= SCREEN_X - 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				direction = LEFT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y][position.x + i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x + i;
					p.y = position.y;
					this->setPosition(p);
					printFill();
					direction = LEFT;
					this->draw();
					map.data[p.y][p.x - 1]--;
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y;
					this->setPosition(p);
					direction = LEFT;
					this->draw();
					map.data[p.y][p.x]--;
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y;
					this->setPosition(p);
					direction = LEFT;
					this->draw();
					i = speed;
					break;

				}

			}
		}
		break;
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
			if (position.y < 15)
			{

				switch (map.data[position.y - i][position.x - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x;
					p.y = position.y - i;
					this->setPosition(p);
					printFill();
					direction = DOWN;
					this->draw();
					map.data[p.y][p.x - 1]--;
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = DOWN;
					this->draw();
					map.data[p.y - 1][p.x - 1]--;
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = DOWN;
					this->draw();
					i = speed;
					break;

				}
			}
		}

		break;
	case DOWN:

		for (int i = 1; i <= speed; i++)
		{
			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y + i][position.x - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x;
					p.y = position.y + i;
					this->setPosition(p);
					printFill();
					direction = UP;
					this->draw();
					map.data[p.y][p.x - 1]--;
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UP;
					this->draw();
					map.data[p.y + 1][p.x - 1]--;
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					direction = UP;
					this->draw();
					i = speed;
					break;

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
					direction = UP;
					this->draw();
					i = speed;
					break;

				}
			}
		}
		break;
	case UPLEFT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x - i <= 1 && position.y - 1 <= 1)
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

			if (position.y - 1 <= 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNLEFT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y - i][position.x - i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x - i;
					p.y = position.y - i;
					if (map.data[position.y - i][position.x - i - 1 + 1] == 0 && map.data[position.y - i + 1][position.x - i - 1] == 0)
						direction = DOWNRIGHT;
					else if (map.data[position.y - i][position.x - i - 1 + 1] == 0)
						direction = UPRIGHT;
					else
						direction = DOWNLEFT;
					map.data[position.y - i][position.x - i - 1]--;
					this->setPosition(p);
					printFill();
					this->draw();
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y - i + 1;
					if (map.data[position.y - i][position.x - i - 1 + 1] == 0 && map.data[position.y - i + 1][position.x - i - 1] == 0)
						direction = DOWNRIGHT;
					else if (map.data[position.y - i][position.x - i - 1 + 1] == 0)
						direction = UPRIGHT;
					else
						direction = DOWNLEFT;
					map.data[position.y - i][position.x - i - 1]--;
					this->setPosition(p);
					printFill();
					this->draw();
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y - i + 1;
					this->setPosition(p);
					if (map.data[p.y][p.x - 1 + 1] == 0 && map.data[p.y + 1][p.x - 1] == 0)
						direction = DOWNRIGHT;
					else if (map.data[p.y][p.x - 1 + 1] == 0)
						direction = UPRIGHT;
					else
						direction = DOWNLEFT;
					this->draw();
					i = speed;
					break;

				}
			}
		}

		break;
	case DOWNLEFT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x <= 1)
			{
				this->printFill();
				position.x = 1;
				direction = DOWNRIGHT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y + i][position.x - i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x - i;
					p.y = position.y + i;
					if (map.data[position.y + i][position.x - i - 1 + 1] == 0 && map.data[position.y + i - 1][position.x - i - 1] == 0)
						direction = UPRIGHT;
					else if (map.data[position.y + i][position.x - i - 1 + 1] == 0)
						direction = DOWNRIGHT;
					else
						direction = UPLEFT;

					map.data[position.y + i][position.x - i - 1]--;
					this->setPosition(p);
					printFill();
					this->draw();
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y + i - 1;
					if (map.data[position.y + i][position.x - i - 1 + 1] == 0 && map.data[position.y + i - 1][position.x - i - 1] == 0)
						direction = UPRIGHT;
					else if (map.data[position.y + i][position.x - i - 1 + 1] == 0)
						direction = DOWNRIGHT;
					else
						direction = UPLEFT;

					map.data[position.y + i][position.x - i - 1]--;
					this->setPosition(p);
					printFill();
					this->draw();
					i = speed;

					break;

				case 7:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y + i - 1;
					if (map.data[position.y + i][position.x - i - 1 + 1] == 0 && map.data[position.y + i - 1][position.x - i - 1] == 0)
						direction = UPRIGHT;
					else if (map.data[position.y + i][position.x - i - 1 + 1] == 0)
						direction = DOWNRIGHT;
					else
						direction = UPLEFT;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

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
					direction = UPLEFT;
					this->draw();
					i = speed;
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

			if (position.y + i <= 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNRIGHT;
				this->draw();
				return;
			}

			//cham gach
			if (position.y < 15)
			{

				switch (map.data[position.y - i][position.x + i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x + i;
					p.y = position.y - i;
					if (map.data[position.y - i][position.x + i - 1 - 1] == 0 && map.data[position.y - i + 1][position.x + i - 1] == 0)
						direction = DOWNLEFT;
					else if (map.data[position.y - i][position.x + i - 1 - 1] == 0)
						direction = UPLEFT;
					else
						direction = DOWNRIGHT;
					map.data[position.y - i][position.x + i - 1]--;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y - i + 1;
					if (map.data[position.y - i][position.x + i - 1 - 1] == 0 && map.data[position.y - i + 1][position.x + i - 1] == 0)
						direction = DOWNLEFT;
					else if (map.data[position.y - i][position.x + i - 1 - 1] == 0)
						direction = UPLEFT;
					else
						direction = DOWNRIGHT;
					map.data[position.y - i][position.x + i - 1]--;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y - i + 1;
					if (map.data[position.y - i][position.x + i - 1 - 1] == 0 && map.data[position.y - i + 1][position.x + i - 1] == 0)
						direction = DOWNLEFT;
					else if (map.data[position.y - i][position.x + i - 1 - 1] == 0)
						direction = UPLEFT;
					else
						direction = DOWNRIGHT;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

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
			if (position.y < 15)
			{

				switch (map.data[position.y + i][position.x + i - 1])
				{
				case 0:
					break;
				case 1:
					this->printFill();
					p.x = position.x + i;
					p.y = position.y + i;
					if (map.data[position.y + i][position.x + i - 1 - 1] == 0 && map.data[position.y + i - 1][position.x + i - 1] == 0)
						direction = UPLEFT;
					else if (map.data[position.y + i][position.x + i - 1 - 1] == 0)
						direction = DOWNLEFT;
					else
						direction = UPRIGHT;
					map.data[position.y + i][position.x + i - 1]--;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

				case 2:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y + i - 1;
					if (map.data[position.y + i][position.x + i - 1 - 1] == 0 && map.data[position.y + i - 1][position.x + i - 1] == 0)
						direction = UPLEFT;
					else if (map.data[position.y + i][position.x + i - 1 - 1] == 0)
						direction = DOWNLEFT;
					else
						direction = UPRIGHT;
					map.data[position.y + i][position.x + i - 1]--;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

				case 7:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y + i - 1;
					if (map.data[position.y + i][position.x + i - 1 - 1] == 0 && map.data[position.y + i - 1][position.x + i - 1] == 0)
						direction = UPLEFT;
					else if (map.data[position.y + i][position.x + i - 1 - 1] == 0)
						direction = DOWNLEFT;
					else
						direction = UPRIGHT;
					this->setPosition(p);
					this->draw();
					i = speed;
					break;

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
					direction = UPRIGHT;
					this->draw();
					i = speed;
				}

			}

		}
		break;
	}
}


