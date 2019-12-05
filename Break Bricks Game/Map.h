#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;

#define SCREEN_X 72
#define SCREEN_Y 50

void gotoXY(int x, int y);

struct vector2D
{
	int x, y;
};

class Map
{
	int data[15][70];
	int level;
};

