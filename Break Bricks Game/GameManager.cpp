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

<<<<<<< HEAD
=======
void play(Map& map, bool& playing)
{
	Ball ball;
	Paddle pad;
	ball.setDirection(UPRIGHT);
	pad.draw();
	while (playing)
	{
		ball.move();
		ball.conllision(map, pad);
		Sleep(100);
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
>>>>>>> 421ecb2e6df18ca9c83b7f44b382cc1ef85a5628
