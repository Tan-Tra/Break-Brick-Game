#include "Player.h"

void Player::printScore()
{
	Color(11);
	gotoXY(70 + 7, 11);
	cout << "=======================================";
	gotoXY(70 + 7, 12);
	cout << "|                                     |";
	gotoXY(70 + 7, 13);
	cout << "=======================================";
	gotoXY(70 + 7, 14);
	cout << "|                                     |";
	gotoXY(70 + 7, 15);
	cout << "|                                     |";
	gotoXY(70 + 7, 16);
	cout << "|                                     |";
	gotoXY(70 + 7, 17);
	cout << "|                                     |";
	gotoXY(70 + 7, 18);
	cout << "|                                     |";
	gotoXY(70 + 7, 19);
	cout << "=======================================";
	gotoXY(70 + 17, 12);
	Color(14);
	cout << "BREAK BRICKS GAME";
	gotoXY(70 + 10, 15);
	cout << "SCORE: " << this->score;
	gotoXY(SCREEN_X + 2, SCREEN_Y+1);
}

Map Player::getMap()
{
	return map;
}