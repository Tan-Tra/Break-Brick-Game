#pragma once
#include"Map.h"
class Player
{
public:
	Map map;
	int score,level;
	string name;
	int broken_bricks;
	void getInfor();
	void printMenuScore();
	void printScore();
	int fread();
	void fwrite();
};

