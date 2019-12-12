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
	while (playing)
	{
		map.printMap();
		//ball.conllision(map, pad);
		Sleep(50);
		ball.conllision(map, pad);
		ball.move();
		
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
	}

}
