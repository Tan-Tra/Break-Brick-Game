#pragma once
#include"Map.h"
class Player
{
public:
	Map map;
	int score,level;
	string ten;

	void printMenuScore();
	void printScore();
	Map getMap();
	void fread();
	void fwrite();
};

