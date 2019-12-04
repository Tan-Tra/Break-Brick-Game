#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

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
	sort(dstk.begin(), dstk.end());
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
int main()
{

}