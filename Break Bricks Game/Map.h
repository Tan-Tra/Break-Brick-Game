#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;

#define SCREEN_X 61
#define SCREEN_Y 40

void gotoXY(int x, int y);

// hàm thay đổi màu sắc chữ
void Color(int cl);
void Nocursortype();

struct vector2D
{
	int x, y;
};

class Map
{
public:
	int data[15][15];
	int level;
	void printMap();
	void freadMap();
	void drawWall();
};

void changeColor(int x, int y);

