#pragma once
#include"User.h"
#include"Map.h"
#include<vector>
#include<string>
#include<algorithm>
class ListUser
{
private:
	vector<User> dsuser;
public:
	void addUser(User& user);
	void updateUser(string ten, int diem, int level);
	void loadFromFile();
	void fwriteGoal();
	void printHightScore();
	vector<User> getDS();
};

