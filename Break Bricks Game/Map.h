#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;

#define SCREEN_X 72
#define SCREEN_Y 25

void gotoXY(int x, int y);

// hàm thay đổi màu sắc chữ
void Color(int cl);

struct vector2D
{
	int x, y;
};

class Map
{
public:
	int data[15][70];
	int level;
	void printMap();
	void freadMap();
	void drawWall();
};

