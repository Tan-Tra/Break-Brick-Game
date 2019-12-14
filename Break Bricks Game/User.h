#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class User
{
private:
	string name; int diem, level;
public:
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
	bool operator<(const User& a)const
	{
		return(diem < a.diem);
	}
	string getTen()
	{
		return name;
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