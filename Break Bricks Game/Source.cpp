#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
using namespace std;
#define SCREEN_X 72
#define SCREEN_Y 22

class User
{
private:
	string ten; int diem, level;
public:
	User() { ten = ""; diem = level = 0; }
	User(const User& u)
	{
		ten = u.ten;
		diem = u.diem;
		level = u.level;
	}
	User(string ten, int diem, int level)
	{
		this->ten = ten;
		this->diem = diem;
		this->level = level;
	}
	~User() {}
	string getTen()
	{
		return ten;
	}
	int getDiem()
	{
		return diem;
	}
	int getLevel()
	{
		return level;
	}
};


void loadFromFile(vector<User>& dsuser)
{
	fstream f("HightScore.txt");
	if (f.fail())
	{
		cout << "Khog mo duoc file luu thanh tich." << endl;
		return;
	}
	while (!f.eof())
	{
		string ten;  int level, diem;
		f >> ten >> diem >> level;
		User* a = new User(ten, diem, level);
		dsuser.push_back(*a);
		delete a;
	}
	f.close();
}

void fwriteGoal(vector<User> dstk)
{

	fstream f("HightScore.txt", ios::out);
	if (f.fail())
	{
		cout << "Khog mo duoc file luu thanh tich." << endl;
		return;
	}
	for (int i = 0; i < dstk.size(); i++)
	{
		f << dstk[i].getTen() << " " << dstk[i].getDiem() << " " << dstk[i].getLevel() << "\n";
	}
	f.close();
}
void Color(int cl)// hàm thay đổi màu sắc chữ
{
	//hàm tham khảo tiêu chuẩn
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, cl);
}

void gotoXY(int x, int y)// hàm đưa con trỏ đến một vị trí bất kì trên màn hình và thực hiện các thao tác tiếp theo như in màn hình từ vị trí đó về sau
{
	// hàm tham khảo theo code tiêu chuẩn
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);

}

void printMap(int map[15][70])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			switch (map[i][j])
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
			if (map[i][j] != 0)
				cout << "\xDB";
			else cout << " ";
			Color(15);
		}
		gotoXY(1, i+1);

	}
}

void freadMap(int& level, int map[15][70])
{
	fstream f("Map2.txt");
	if (f.fail())
	{
		return;
	}
	
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			f >> map[i][j];
		}

	}
}
void drawWall()
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
		cout << "\xB2";
	cout << endl;
}

int main()
{
	
	int map[15][70], level=0;
	drawWall();

	gotoXY(1, 1);
	freadMap(level, map);
	printMap(map);
	system("pause>nul");
	return 1;

}