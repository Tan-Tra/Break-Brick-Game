#ifndef _MENU_H_
#define _MENU_H_

#include"Map.h"
#include<time.h>
#include<Windows.h>
#include<iostream>
using namespace std;
class Menu
{
public:
	//in tên game
	void printTitle();
	//in menu chính
	int startMenu();
	//in tên màn chơi
	void textLevel(int level);
	//in khung kết quả
	int resultMenu(int score, int level);

	//in thông bao qua màn
	void passLevel();
	//in thông báo thắng game.
	void winGame();
};


#endif




