#include "Ball.h"
#include <ctime>


void main()
{
	Map map;
	map.freadMap();
	map.drawWall();
	map.printMap();

	Paddle pad;
	Ball ball;
	ball.setPosition(1, 10);
	ball.setDirection(DOWNRIGHT);
	ball.draw();
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
	system("pause");
	while (true)
	{
		ball.move();
		ball.conllision(map, pad);
		Sleep(100);
	}




}