#pragma once
#include"Map.h"
class Player
{
public:
	Map map;// ma trận trò chơi
	int score,level;//điểm và số cửa qua được
	string name;//tên
	int broken_bricks;// số gạch đã phá

	//lấy thông tin người chơi
	void getInfor();
	//in khung điểm
	void printMenuScore();
	//in điểm
	void printScore();
	//đọc người chơi từ file
	int fread();
	//viết người chơi xuống file.
	void fwrite();
};

