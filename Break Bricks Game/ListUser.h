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
	//thêm User vào danh sách User
	void addUser(User& user);
	//Cập nhật lại User có tên, điểm level được truyền vào
	void updateUser(string name, int diem, int level);
	//đọc danh sách User từ file
	void loadFromFile();
	//viết danh sách User vào file
	void fwriteGoal();
	//in danh sách điểm cao
	void printHightScore();
	//lấy vector danh sách User
	vector<User> getDS();
};

