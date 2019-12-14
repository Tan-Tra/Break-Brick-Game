#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
#include<time.h>
using namespace std;

#define SCREEN_X 61
#define SCREEN_Y 40

void gotoXY(int x, int y);

// hàm thay đổi màu sắc chữ
void Color(int cl);
void Nocursortype();

void resizeConsole(int width, int height);

struct vector2D
{
	int x, y;
};

class Map
{
protected:

public:
	int data[15][15];
	int level;
	int bricks;
	void printMap();
	int freadMap(int level);
	int fread(fstream& f);
	void fwrite(fstream& f);
	void drawWall();
};

void changeColor(int x, int y);

