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

void Ball::draw(bool& bom)
{
	gotoXY(position.x, position.y);
	if (bom)
	{
		Color(13);
	}
	cout << 'O';
	
	Color(15);
}
void Ball::printFill()
{
	gotoXY(position.x, position.y);
	cout << ' ';
}

void Ball::move(bool& bom)
{
	printFill();
	switch (direction)
	{
	case UP:
		if (position.y - (int)speed >= 1)
		{
			position.y -= (int)speed;
		}
		break;
	case DOWN:
		position.y += (int)speed;
		break;
	case UPLEFT:
		if (position.x - (int)speed >= 1 && position.y - (int)speed >= 1)
		{
			position.x -= (int)speed;
			position.y -= (int)speed;
		}
		break;
	case DOWNLEFT:
		if (position.x - (int)speed >= 1)
		{
			position.x -= (int)speed;
			position.y += (int)speed;
		}
		break;
	case UPRIGHT:
		if (position.x + (int)speed <= SCREEN_X - 1 && position.y - (int)speed >= 1)
		{
			position.x += (int)speed;
			position.y -= (int)speed;
		}
		break;
	case DOWNRIGHT:
		if (position.x + (int)speed <= SCREEN_X - 1)
		{
			position.x += (int)speed;
			position.y += (int)speed;
		}
		break;
	}
	draw(bom);

}

void Ball::conllision(Map& map, Paddle& pad, int &score, int& broken_bricks, bool& bom)
{
	vector2D p;
	switch (direction)
	{
	case UP:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.y - i < 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWN;
				this->draw(bom);
				return;
			}

			//cham gach
			if (position.y - i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y - 1 - i][(position.x - 1) / 4])
					{
						case 1:
						{
							score += 10;
							broken_bricks++;
						}break;
						case 2:
							score += 20;
							broken_bricks+=2;
							break;
						case 7:
							score += 30;
							break;
						default:
								break;
					}
					map.data[position.y - 1 - i][(position.x - 1) / 4] = 0;
					continue;
				}

				switch (map.data[position.y - 1 - i][(position.x - 1) / 4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y - 1 - i][(position.x - 1) / 4]--;
					score += 10;
					broken_bricks++;
				case 7:
					this->printFill();
					p.x = position.x;
					p.y = position.y - i + 1;
					this->setPosition(p);
					direction = DOWN;
					this->draw(bom);
					return;

				}
			}
		}

		break;
	case DOWN:

		for (int i = 1; i <= speed; i++)
		{
			//cham gach
			if (position.y + i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y + i - 1][(position.x - 1) / 4])
					{
					case 1:
					{
						score += 10;
						broken_bricks++;
					}break;
					case 2:
						score += 20;
						broken_bricks += 2;
						break;
					case 7:
						score += 30;
						break;
					default:
						break;
					}
					map.data[position.y + i - 1][(position.x - 1) / 4] = 0;
					continue;
				}
				switch (map.data[position.y + i - 1][(position.x - 1) / 4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y + i - 1][(position.x - 1) / 4]--;
					score += 10;
					broken_bricks++;
				case 7:

					this->printFill();
					p.x = position.x;
					p.y = position.y + i - 1;
					this->setPosition(p);
					printFill();
					direction = UP;
					this->draw(bom);
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

					this->draw(bom);
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
			if (position.x - i < 1 && position.y - i < 1)
			{
				this->printFill();
				position.x = 1;
				position.y = 1;
				direction = DOWNRIGHT;
				this->draw(bom);
				return;
			}

			if (position.x - i < 1)
			{
				this->printFill();
				position.x = 1;
				direction = UPRIGHT;
				this->draw(bom);
				return;
			}

			if (position.y - i < 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNLEFT;
				this->draw(bom);
				return;
			}

			//cham gach
			if (position.y - i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y - i - 1][(position.x - i - 1) / 4])
					{
					case 1:
					{
						score += 10;
						broken_bricks++;
					}break;
					case 2:
						score += 20;
						broken_bricks += 2;
						break;
					case 7:
						score += 30;
						break;
					default:
						break;
					}
					map.data[position.y - i - 1][(position.x - i - 1) / 4] = 0;
					continue;
				}
				switch (map.data[position.y - i - 1][(position.x - i - 1) / 4])
				{
				case 0:
					break;
				case 1:
				case 2:
					map.data[position.y - i - 1][(position.x - i - 1) / 4]--;
					score += 10;
					broken_bricks++;
				case 7:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y - i + 1;
					if ((map.data[position.y - i - 1][(position.x - i - 1) / 4 + 1] == 0) && (map.data[position.y - i - 1 + 1][(position.x - i - 1) / 4] == 0))
					{
						if ((position.x - i - 1) % 4 == 3)
							direction = DOWNRIGHT;
						else
						{
							direction = DOWNLEFT;
						}
					}
					else if (map.data[position.y - i - 1][(position.x - i - 1) / 4 + 1] == 0)
						direction = UPRIGHT;
					else if (map.data[position.y - i - 1 + 1][(position.x - i - 1) / 4] == 0)
						direction = DOWNLEFT;
					else
					{
						if (map.data[position.y - i - 1][(position.x - i - 1) / 4 + 1] != 7)
						{
							map.data[position.y - i - 1][(position.x - i - 1) / 4 + 1]--;
							broken_bricks++;
							score += 10;
						}
						
						if (map.data[position.y - i - 1 + 1][(position.x - i - 1) / 4] != 7)
						{
							map.data[position.y - i - 1 + 1][(position.x - i - 1) / 4]--;
							broken_bricks++;
							score += 10;
						}
							
					}
					this->setPosition(p);
					this->draw(bom);
					return;

				}
			}
		}

		break;
	case DOWNLEFT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x - i < 1)
			{
				this->printFill();
				position.x = 1;
				direction = DOWNRIGHT;
				this->draw(bom);
				return;
			}

			//cham gach
			if (position.y + i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y + i - 1][(position.x - i - 1) / 4])
					{
					case 1:
					{
						score += 10;
						broken_bricks++;
					}break;
					case 2:
						score += 20;
						broken_bricks += 2;
						break;
					case 7:
						score += 30;
						break;
					default:
						break;
					}
					map.data[position.y + i - 1][(position.x - i - 1) / 4] = 0;
					continue;
				}
				switch (map.data[position.y + i - 1][(position.x - i - 1) / 4])
				{
				case 0:
					break;
				case 1:

				case 2:
					map.data[position.y + i - 1][(position.x - i - 1) / 4]--;
					score += 10;
					broken_bricks++;
				case 7:
					this->printFill();
					p.x = position.x - i + 1;
					p.y = position.y + i - 1;
					if ((map.data[position.y + i - 1][(position.x - i - 1) / 4 + 1] == 0) && (map.data[position.y + i - 1 - 1][(position.x - i - 1) / 4] == 0))
					{
						if ((position.x - i - 1) % 4==3)
						direction = UPRIGHT;
						else
						{
							direction = UPLEFT;
						}
					}
					else if (map.data[position.y + i - 1][(position.x - i - 1) / 4 + 1] == 0)
						direction = DOWNRIGHT;
					else if (map.data[position.y + i - 1 - 1][(position.x - i - 1) / 4] == 0)
						direction = UPLEFT;
					else
					{
						if (map.data[position.y + i - 1][(position.x - i - 1) / 4 + 1] != 7)
						{
							map.data[position.y + i - 1][(position.x - i - 1) / 4 + 1]--;
							broken_bricks++;
							score += 10;
						}
						if (map.data[position.y + i - 1 - 1][(position.x - i - 1) / 4] != 7) 
						{
							map.data[position.y + i - 1 - 1][(position.x - i - 1) / 4]--;
							broken_bricks++;
							score += 10;
						}
					}
					this->setPosition(p);
					this->draw(bom);
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
					this->draw(bom);
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
			if (position.x + i > SCREEN_X - 1 && position.y - i < 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				position.y = 1;
				direction = DOWNLEFT;
				this->draw(bom);
				return;
			}

			if (position.x + i > SCREEN_X - 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				direction = UPLEFT;
				this->draw(bom);
				return;

			}

			if (position.y - i < 1)
			{
				this->printFill();
				position.y = 1;
				direction = DOWNRIGHT;
				this->draw(bom);
				return;
			}

			//cham gach
			if (position.y - i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y - i - 1][(position.x + i - 1) / 4])
					{
					case 1:
					{
						score += 10;
						broken_bricks++;
					}break;
					case 2:
						score += 20;
						broken_bricks += 2;
						break;
					case 7:
						score += 30;
						break;
					default:
						break;
					}
					map.data[position.y - i - 1][(position.x + i - 1) / 4] = 0;
					continue;
				}
				switch (map.data[position.y - i - 1][(position.x + i - 1) / 4])
				{
				case 0:
					break;
				case 1:

				case 2:
					score += 10;
					broken_bricks++;
					map.data[position.y - i - 1][(position.x + i - 1) / 4]--;
				case 7:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y - i + 1;
					if ((map.data[position.y - i - 1][(position.x + i - 1) / 4 - 1] == 0) && (map.data[position.y - i - 1 + 1][(position.x + i - 1) / 4] == 0))
					{
						if ((position.x + i - 1) % 4 == 0)
							direction = DOWNLEFT;
						else
						{
							direction = DOWNRIGHT;
						}
					}
					else if (map.data[position.y - i - 1][(position.x + i - 1) / 4 - 1] == 0)
						direction = UPLEFT;
					else if (map.data[position.y - i - 1 + 1][(position.x + i - 1) / 4] == 0)
						direction = DOWNRIGHT;
					else
					{
						if (map.data[position.y - i - 1][(position.x + i - 1) / 4 - 1] != 7)
						{
							map.data[position.y - i - 1][(position.x + i - 1) / 4 - 1]--;
							broken_bricks++;
							score += 10;
						}
							
						if (map.data[position.y - i - 1 + 1][(position.x + i - 1) / 4] != 7)
						{
							map.data[position.y - i - 1 + 1][(position.x + i - 1) / 4]--;
							broken_bricks++;
							score += 10;
						}
						
					}
					this->setPosition(p);
					this->draw(bom);
					return;

				}

			}
		}
		break;
	case DOWNRIGHT:

		for (int i = 1; i <= speed; i++)
		{
			//cham tuong
			if (position.x + i > SCREEN_X - 1)
			{
				this->printFill();
				position.x = SCREEN_X - 1;
				direction = DOWNLEFT;
				this->draw(bom);
				return;
			}

			//cham gach
			if (position.y + i < 16)
			{
				//banh sieu cap
				if (bom)
				{
					switch (map.data[position.y + i - 1][(position.x + i - 1) / 4])
					{
					case 1:
					{
						score += 10;
						broken_bricks++;
					}break;
					case 2:
						score += 20;
						broken_bricks += 2;
						break;
					case 7:
						score += 30;
						break;
					default:
						break;
					}
					map.data[position.y + i - 1][(position.x + i - 1) / 4] = 0;
					continue;
				}
				switch (map.data[position.y + i - 1][(position.x + i - 1) / 4])
				{
				case 0:
					break;
				case 1:

				case 2:
					score += 10;
					broken_bricks++;
					map.data[position.y + i - 1][(position.x + i - 1) / 4]--;
				case 7:
					this->printFill();
					p.x = position.x + i - 1;
					p.y = position.y + i - 1;
					if ((map.data[position.y + i - 1][(position.x + i - 1) / 4 - 1] == 0) && (map.data[position.y + i - 1 - 1][(position.x + i - 1) / 4] == 0))
						if ((position.x + i - 1) % 4 == 0)
							direction = UPLEFT;
						else
						{
							direction = UPRIGHT;
						}
					else if (map.data[position.y + i - 1][(position.x + i - 1) / 4 - 1] == 0)
						direction = DOWNLEFT;
					else if (map.data[position.y + i - 1 - 1][(position.x + i - 1) / 4] == 0)
						direction = UPRIGHT;
					else
					{
						if (map.data[position.y + i - 1][(position.x + i - 1) / 4 - 1] != 7)
						{
							map.data[position.y + i - 1][(position.x + i - 1) / 4 - 1]--;
							broken_bricks++;
							score += 10;
						}
							
						if (map.data[position.y + i - 1 - 1][(position.x + i - 1) / 4] != 7)
						{

							map.data[position.y + i - 1 - 1][(position.x + i - 1) / 4]--;
							broken_bricks++;
							score += 10;
						}
					}
					this->setPosition(p);
					this->draw(bom);
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
					this->draw(bom);
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

void Ball::reset()
{
	position.x = SCREEN_X / 2;
	position.y = SCREEN_Y - 3;
	speed = BALL_SPEED;
	direction = STOP;
}


