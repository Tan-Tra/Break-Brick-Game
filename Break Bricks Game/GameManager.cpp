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
	ball.setDirection(UP);
	ball.draw();
	pad.draw();
	system("pause>nul");
	srand(time_t(NULL));
	while (playing)
	{
		map.printMap();
		ball.conllision(map, pad);
		ball.conllision(map, pad);
		ball.move();
		Sleep(20);


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

		if (ball.getPosition().x <= pad.getPosition().x)
		{
			pad.moveLeft();
			eDir r = (eDir)(rand() % 3);
			pad.setDirection(r);
		}

		if (ball.getPosition().x >= pad.getPosition().x)
		{
			pad.moveRight();
			eDir r = (eDir)(rand() % 3);
			pad.setDirection(r);
		}

		if (ball.getPosition().y > SCREEN_Y)
			playing = false;
	}




}

void autoPlay(Map& map, bool& playing)
{
	Ball ball;
	Paddle pad;
	ball.setDirection(UP);
	ball.draw();
	pad.draw();
	system("pause>nul");
	srand(time_t(NULL));
	while (playing)
	{
		map.printMap();
		ball.conllision(map, pad);
		ball.conllision(map, pad);
		ball.move();
		Sleep(20);


		if (GetAsyncKeyState(27))
		{
			playing = false;
		}


		if (ball.getPosition().x <= pad.getPosition().x)
		{
			pad.moveLeft();
			eDir r = (eDir)(rand() % 3);
			pad.setDirection(r);
		}

		if (ball.getPosition().x >= pad.getPosition().x)
		{
			pad.moveRight();
			eDir r = (eDir)(rand() % 3);
			pad.setDirection(r);
		}

		if (ball.getPosition().y > SCREEN_Y)
			playing = false;
	}
}
