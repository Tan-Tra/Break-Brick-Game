#include "GameManager.h"

void guide()
{
	fstream f("Guide.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Guide." << endl;
		return;
	}
	char a[501];
	Color(14);
	while (!f.eof())
	{
		f.getline(a, 500);
		cout << a << endl;
	}
	system("pause>nul");
}

void play(Map& map, bool& playing)
{
	Ball ball;
	Paddle pad;
	bool bom = false;
	ball.setDirection(UP);
	ball.draw(bom);
	pad.draw();
	system("pause>nul");
	srand(time(NULL));
	
	clock_t t1 = clock();
	clock_t t2;
	Item item;
	while (playing)
	{
		t2 = clock();

		//tao item
		if ((int)(t2 - t1) > TIME_TO_APPEAR_ITEM)
		{
			item.createItem(map);
			t1 = t2;
		}

		if ((int)(t2 - t1) > TIME_ITEM_EXIST)
		{
			item.existed = false;
		}

		if (item.existed)
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{

					if (((ball.getPosition().x + i == item.position.x)|| (ball.getPosition().x + i == item.position.x+1)) && (ball.getPosition().y + j == item.position.y))
					{
						switch (item.kind)
						{
							////
						case BOM:
							bom = true;
							item.t0 = clock();
							break;
						default:
							break;
						}
						item.existed = false;
						item.printFill();
					}
				}

			}
		}

		if ((int)(t2 - item.t0) > TIME_SUPERBALL)
		{
			bom = false;
		}

		map.printMap();
		if (item.existed)
		{
			item.print();
		}

		ball.conllision(map, pad, bom);
		ball.conllision(map, pad, bom);
		ball.move(bom);
		pad.setDirection(STOP);


		if (GetAsyncKeyState(27))
		{
			playing = false;
		}

		if (GetAsyncKeyState(37))
		{
			pad.moveLeft();
			pad.setDirection(LEFT);
		}

		if (GetAsyncKeyState(39))
		{
			pad.moveRight();
			pad.setDirection(RIGHT);
		}


		if (ball.getPosition().y > SCREEN_Y)
			playing = false;


		Sleep(20);
		if (item.existed)
		{
			item.printFill();
		}
	}




}

void autoPlay(Map& map, bool& playing)
{
	Ball ball;
	Paddle pad;
	bool bom = false;
	ball.setDirection(UP);
	ball.draw(bom);
	pad.draw();
	system("pause>nul");
	srand(time(NULL));
	clock_t t1 = clock();
	clock_t t2;
	Item item;
	while (playing)
	{

		t2 = clock();

		//tao item
		if ((int)(t2 - t1) > TIME_TO_APPEAR_ITEM)
		{
			item.createItem(map);
			t1 = t2;
		}

		if ((int)(t2 - t1) > TIME_ITEM_EXIST)
		{
			item.existed = false;
		}

		if (item.existed)
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{

					if (((ball.getPosition().x + i == item.position.x) || (ball.getPosition().x + i == item.position.x + 1)) && (ball.getPosition().y + j == item.position.y))
					{
						switch (item.kind)
						{
							////
						case BOM:
							bom = true;
							item.t0 = clock();
							break;
						default:
							break;
						}
						item.existed = false;
						item.printFill();
					}
				}

			}
		}

		if ((int)(t2 - item.t0) > TIME_SUPERBALL)
		{
			bom = false;
		}

		map.printMap();
		if (item.existed)
		{
			item.print();
		}

		ball.conllision(map, pad, bom);
		ball.conllision(map, pad, bom);
		ball.move(bom);


		if (GetAsyncKeyState(27))
		{
			playing = false;
		}


		if (ball.getPosition().x < pad.getPosition().x - PADDLE_SPEED)
		{
			pad.moveLeft();
		}

		if (ball.getPosition().x > pad.getPosition().x + PADDLE_SPEED)
		{
			pad.moveRight();
		}

		eDir r = (eDir)(rand() % 3);
		pad.setDirection(r);

		if (ball.getPosition().y > SCREEN_Y)
			playing = false;

		Sleep(20);
		if (item.existed)
		{
			item.printFill();
		}
	}
}
