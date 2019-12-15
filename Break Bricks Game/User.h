#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class User
{
public:
	string name; int diem, level;
	User() { name = ""; diem = level = 0; }
	User(const User& u)
	{
		name = u.name;
		diem = u.diem;
		level = u.level;
	}
	User(string name, int diem, int level)
	{
		this->name = name;
		this->diem = diem;
		this->level = level;
	}
	~User() {}
	//lấy tên người dùng
	string getTen()
	{
		return name;
	}
	//lấy điểm
	int getDiem()
	{
		return diem;
	}
	//lấy màn chơi
	int getLevel()
	{
		return level;
	}
	//thiết lập điểm
	void setDiem(int diem)
	{
		this->diem = diem;
	}
	//thiết lập màn chơi
	void setLevel(int level)
	{
		this->level = level;
	}
};
bool compareUser(User i1, User i2);

