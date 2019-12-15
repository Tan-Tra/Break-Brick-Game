#pragma once
#include "Map.h"

#define PADDLE_SIZE 6
#define PADDLE_SPEED 3
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 5, UP = 3, UPRIGHT = 4, RIGHT = 2, DOWNRIGHT = 6, DOWN = 7, DOWNLEFT = 8 };// Khai báo kiểu liệt kê

class Paddle
{
private:
	vector2D position;
	eDir direction;

public:
	int size;	//khoảng cách từ giữa đến biên

	Paddle();
	~Paddle();
	//đặt vị trí cho paddle
	void setPosition(vector2D& pos);
	//đặt hướng di chuyển cho thanh trượt
	void setDirection(eDir dir);
	//lấy tọa độ thanh trượt
	vector2D getPosition();
	//lấy hướng di chuyển của thanh trượt
	eDir getDirection();

	//di chuyển trái
	void moveLeft();
	//di chuyển phải
	void moveRight();
	//vẽ thanh trượt
	void draw();
	//in che thanh trượt = xóa thanh trượt
	void drawFill();
	//thiết lập lại trnagj thái ban đầu cho thanh trượt
	void reset();
};

