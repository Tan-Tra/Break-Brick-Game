#include "Map.h"
#define _CRT_SECURE_N0_WARNINGS
#define _CRT_SECURE_N0_WARNINGS
void Color(int cl)// hàm thay đổi màu sắc chữ
{
	//hàm tham khảo tiêu chuẩn
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, cl);
}

void changeColor(int x, int y)
{
	gotoXY(x, y);
	Color(10);
	cout << "\xDB";
	Color(15);
	
}

void Map::printMap()
{
	for (int i = 0; i < 15; i++)
	{
		gotoXY(1, i + 1);
		for (int j = 0; j < 15; j++)
		{
			
			switch (data[i][j])
			{
			case 7:
			{
				Color(12);
			}break;
			case 1:
			{
				Color(10);
			}break;
			case 2:
			{
				Color(11);
			}break;
			default:
				break;
			}
			if (data[i][j] != 0)
				cout << "\xB2\xB2\xB2\xB2";
			else cout << "    ";
			Color(15);
		}
		

	}
}

int Map::freadMap(int level)
{
	char* intStr = new char;
	_itoa(level, intStr, 10);
	
	string str = string(intStr);
	
	string tenfile = "Map" + str + ".txt";
	
	fstream f(tenfile);
	if (f.fail())
	{
		return-1 ;
	}
	return fread(f);
}

int Map::fread(fstream& f)
{
	bricks = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			f >> data[i][j];
			if (data[i][j] == 1) bricks++;
			else if (data[i][j] == 2) bricks += 2;
		}
	}
	return bricks;
}

void Map::fwrite(fstream& f)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			f << data[i][j]<<" ";
		}
		f << "\n";
	}
}

void Map::drawWall()
{
	//vẽ tường trên
	for (int i = 0; i < SCREEN_X + 1; i++)
		cout << "\xDB";
	cout << endl;
	for (int i = 0; i < SCREEN_Y; i++)
	{
		for (int j = 0; j < SCREEN_X + 1; j++)
		{
			// vẽ tường trái
			if (j == 0)
				cout << "\xDB";

			// vẽ tường phải
			else if (j == SCREEN_X)
				cout << "\xDB";
			else cout << " ";
		}
		cout << endl;
	}

	//vễ tường dưới
	for (int i = 0; i < SCREEN_X + 1; i++)
		cout << "^";
	cout << endl;
}



void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
