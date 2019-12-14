#pragma once
#include<string>
#include<iostream>
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
	bool operator<(const User& a)const
	{
		return(diem < a.diem);
	}
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
	void setDiem(int diem)
	{
		this->diem = diem;
	}
	void setLevel(int level)
	{
		this->level = level;
	}
};