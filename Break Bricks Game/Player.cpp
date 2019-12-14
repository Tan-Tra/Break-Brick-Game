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
	cin >> name;
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
	gotoXY(68 + 23-name.length()/2, 12);
	Color(14);
	cout <<name;
	gotoXY(68 + 10, 15);
	cout << "SCORE: ";
	gotoXY(68 + 10, 18);
	cout << "LEVEL: " << level;
}

void Player::printScore()
{
	gotoXY(70 + 17, 15);
	cout << score<<"       ";
}

int Player::fread()
{
	getInfor();
	
	fstream f(name + ".txt");
	if (f.fail()) return - 1;
	f >> score >> level;
	map.fread(f);

	return 1;
}

void Player::fwrite()
{
	fstream f(name+".txt", ios::out);
	if (f.fail()) return;
	f << score << " " << level << "\n";
	map.fwrite(f);
}

