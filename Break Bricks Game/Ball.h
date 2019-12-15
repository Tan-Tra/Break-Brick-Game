#pragma once
#include "Paddle.h"
#define BALL_SPEED 1
#define BALL_SPEED_MAX 2


class Ball
{
private:
	vector2D position;
	float speed;
	eDir direction;
public:
	Ball();
	~Ball();
	//đặt ví trí cho ball bằng vector2D
	void setPosition(vector2D& pos);
	// đặt vị trí ball bằng int, int
	void setPosition(int pos_y, int pos_x);
	//đặt hướng chuyển động cho ball
	void setDirection(eDir dir);
	//lấy vị trí cho ball
	vector2D getPosition();
	//lấy hướng hiện tại cả bóng
	eDir getDirection();
	//vẽ bóng
	void draw(bool& bom);
	//xóa bóng
	void printFill();
	//di chuyển bóng
	void move(bool& bom);
	//xử lý va chạm cho bóng
	void conllision(Map& map, Paddle& pad, int& score, int& broken_bricks, bool& bom);
	//thiết lập lại trạng thái ban đầu cho bóng.
	void reset();
};

