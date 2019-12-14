#include "Player.h"

void Player::getInfor()
{
	broken_bricks = 0;
	Color(11);
	gotoXY(30 + 7, 11);
	cout << "=======================================";
	gotoXY(30 + 7, 12);
	cout << "|    Ban can nhap ten de tiep tuc     |";
	gotoXY(30 + 7, 13);
	cout << "=======================================";
	gotoXY(30 + 7, 14);
	cout << "| Ten nguoi choi:                     |";
	gotoXY(30 + 7, 15);
	cout << "=======================================";
	gotoXY(30 + 25, 14);
	cin >> ten;
}

void Player::printMenuScore()
{
	Color(11);
	gotoXY(68 + 7, 11);
	cout << "=======================================";
	gotoXY(68 + 7, 12);
	cout << "|                                     |";
	gotoXY(68 + 7, 13);
	cout << "=======================================";
	gotoXY(68 + 7, 14);
	cout << "|                                     |";
	gotoXY(68 + 7, 15);
	cout << "|                                     |";
	gotoXY(68 + 7, 16);
	cout << "|                                     |";
	gotoXY(68 + 7, 17);
	cout << "|                                     |";
	gotoXY(68 + 7, 18);
	cout << "|                                     |";
	gotoXY(68 + 7, 19);
	cout << "=======================================";
	gotoXY(68 + 17, 12);
	Color(14);
	cout << "BREAK BRICKS GAME";
	gotoXY(68 + 10, 15);
	cout << "SCORE: ";
	gotoXY(SCREEN_X + 2, SCREEN_Y+1);
}

void Player::printScore()
{
	gotoXY(70 + 17, 15);
	cout << score<<"       ";
}

int Player::fread()
{
	getInfor();
	
	fstream f(ten + ".txt");
	if (f.fail()) return - 1;
	f >> score >> level;
	map.fread(f);
	return 1;
}

void Player::fwrite()
{
	fstream f(ten+".txt", ios::out);
	if (f.fail()) return;
	f << score << " " << level << "\n";
	map.fwrite(f);
}

