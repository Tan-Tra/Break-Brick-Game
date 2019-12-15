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
	int data[15][15];//ma trận lưu level
	int level;//màn chơi
	int bricks;//số gạch của màn chơi
	//in màn chơi ra màn hình
	void printMap();
	//Function đọc màn chơi từ file lên
	int freadMap(int level);
	//đọc map
	int fread(fstream& f);
	//viết lại map xuống file
	void fwrite(fstream& f);
	//in tường
	void drawWall();
};
//thay đổi màu
void changeColor(int x, int y);

