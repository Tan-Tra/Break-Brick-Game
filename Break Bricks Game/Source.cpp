#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
#include "Map.h"
using namespace std;

void gotoXY(int x, int y)// hàm đưa con trỏ đến một vị trí bất kì trên màn hình và thực hiện các thao tác tiếp theo như in màn hình từ vị trí đó về sau
{
	// hàm tham khảo theo code tiêu chuẩn
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}


