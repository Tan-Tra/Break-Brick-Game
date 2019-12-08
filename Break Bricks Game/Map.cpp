#include "Map.h"

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
	gotoXY(SCREEN_X + 2, SCREEN_Y + 2);
}

void Map::printMap()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			switch (data[i][j])
			{
			case 7:
			{
				Color(8);
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
				cout << "\xDB";
			else cout << " ";
			Color(15);
		}
		gotoXY(1, i + 1);

	}
}

void Map::freadMap()
{
	fstream f("Map1.txt");
	if (f.fail())
	{
		return;
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			f >> data[i][j];
		}

	}
}

void Map::drawWall()
{
	//vẽ tường trên
	for (int i = 0; i < SCREEN_X + 1; i++)
		cout << "\xB2";
	cout << endl;
	for (int i = 0; i < SCREEN_Y; i++)
	{
		for (int j = 0; j < SCREEN_X + 1; j++)
		{
			// vẽ tường trái
			if (j == 0)
				cout << "\xB2";

			// vẽ tường phải
			else if (j == SCREEN_X)
				cout << "\xB2";
			else cout << " ";
		}
		cout << endl;
	}

	//vễ tường dưới
	for (int i = 0; i < SCREEN_X + 1; i++)
		cout << "_";
	cout << endl;
}
