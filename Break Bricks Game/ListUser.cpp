#include "ListUser.h"

void ListUser::addUser(User& user)
{
	if (user.getTen() != "")
		dsuser.push_back(user);
}

void ListUser::updateUser(string name, int diem, int level)
{
	for (int i = 0; i < dsuser.size(); i++)
	{
		if (dsuser[i].getTen() == name)
		{
			dsuser[i].setLevel(level);
			dsuser[i].setDiem(diem);
			return;
		}
	}
	User* user = new User(name, diem, level);
	if (user->getTen() != "")
		dsuser.push_back(*user);
}

void ListUser::loadFromFile()
{
	fstream f("HightScore.txt");
	if (f.fail())
	{
		return;
	}
	while (!f.eof())
	{
		string name;  int level, diem;
		f >> name >> diem >> level;
		User* a = new User(name, diem, level);
		if(a->getTen()!="")
			dsuser.push_back(*a);
		delete a;
	}
	f.close();
	sort(dsuser.begin(), dsuser.end());
}

void ListUser::fwriteGoal()
{
	fstream f("HightScore.txt", ios::out);
	if (f.fail())
	{
		cout << "Khog mo duoc file luu thanh tich." << endl;
		return;
	}
	for (int i = 0; i < dsuser.size(); i++)
	{
		f << dsuser[i].getTen() << " " << dsuser[i].getDiem() << " " << dsuser[i].getLevel() << "\n";
	}
	f.close();
}

void ListUser::printHightScore()
{
	Color(14);
	gotoXY(30, 7);
	cout << "=================================================================" << endl;
	gotoXY(30, 8);
	cout << "|                         HIGHTSCORE                            |" << endl;
	gotoXY(30, 9);
	cout << "=================================================================" << endl;
	gotoXY(30, 10);
	cout << "|             Name                           Score              |" << endl;
	gotoXY(30, 11);
	cout << "|    1.                                                         |" << endl;
	gotoXY(30, 12);
	cout << "|    2.                                                         |" << endl;
	gotoXY(30, 13);
	cout << "|    3.                                                         |" << endl;
	gotoXY(30, 14);
	cout << "|    4.                                                         |" << endl;
	gotoXY(30, 15);
	cout << "|    5.                                                         |" << endl;
	gotoXY(30, 16);
	cout << "=================================================================" << endl;

	int dem = ((dsuser.size() < 5) ? dsuser.size() : 5);
	for (int i = 0; i <dem; i++)
	{
		gotoXY(44, 11 + i);
		cout << dsuser[i].getTen();
		gotoXY(80, 11 + i);
		cout << dsuser[i].getDiem();
	}
}

vector<User> ListUser::getDS()
{
	return dsuser;
}
