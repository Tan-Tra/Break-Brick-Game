#pragma once
#include "Map.h"
#define TIME_TO_APPEAR_ITEM 20000
#define TIME_ITEM_EXIST 10000
#define TIME_SUPERBALL 4000


enum eItem { x2 = 0, d2 = 1, BOM = 2, TARGET = 3 };

class Item
{
public:
	vector2D position;
	eItem kind;
	clock_t t0;
	bool existed;
	Item();
	~Item();
	void createItem(Map& map);
	void print();
	void printFill();
};