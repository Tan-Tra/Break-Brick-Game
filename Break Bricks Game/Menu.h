#ifndef _MENU_H_
#define _MENU_H_
#include"Map.h"
#include<time.h>
#include<Windows.h>
#include<iostream>
using namespace std;

void printTitle();
int startMenu();
void textLevel(int level);
int resultMenu(int score, int level);


#endif


void main()
{
	printTitle();
	system("cls");
	startMenu();
	system("cls");
	resultMenu(100, 3);

}
