#pragma once
#include "Map.h"
#define TIME_TO_APPEAR_ITEM 20000
#define TIME_ITEM_EXIST 10000
#define TIME_SUPERBALL 4000


enum eItem { x2 = 0, d2 = 1, BOM = 2, TARGET = 3 };

class Item
{
public:
	vector2D position;//t?a d? v?t ph?m
	eItem kind;//lo?i v?t ph?m
	clock_t t0;//th?i gian hi?n t?i
	bool existed;//thu?c t�nh ki?m tra c� t?n t?i hay kh�ng
	Item();
	~Item();
	//t?o v?t ph?m
	void createItem(Map& map);
	//in v?t ph?m
	void print();
	//x�a v?t ph?m
	void printFill();
};