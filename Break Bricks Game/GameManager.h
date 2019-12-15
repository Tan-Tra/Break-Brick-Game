#pragma comment(lib, "winmm.lib")
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#include "Ball.h"
#include"Player.h"
#include"ListUser.h"
#include"Menu.h"
#include"Item.h"
class GameManager
{
private:
	Player player;
	ListUser dsuser;
	Ball ball;
	Paddle pad;
	Menu menu;

protected:
	//in cách chơi
	void guide();
	//hàm chơi thủ công
	int play(bool& playing, int& broken_bricks);
	//hàm chơi tự động
	int autoPlay(bool& playing, int& broken_bricks);
	
public:
	//hàm chạy chương trình chính
	void runGame();
};

#endif

