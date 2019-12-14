#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#include "Ball.h"
#include"Player.h"
#include"ListUser.h"
#include"Menu.h"
class GameManager
{
private:
	Player player;
	ListUser dsuser;
	Ball ball;
	Paddle pad;
	Menu menu;

protected:
	void guide();
	int play(bool& playing, int& broken_bricks);
	int autoPlay(bool& playing, int& broken_bricks);
	
public:

	void runGame();
};

#endif

