#include  "Menu.h "


void printTitle()
{
		Color(14);
		gotoXY(0, 10);
		cout <<"  88888888ba                                        88            88888888ba                88             88 ";
		Sleep(500);
		gotoXY(1, 11);
		cout << "  88      8b                                       88             88       8b                             88 " << endl;
		Sleep(500);
		cout <<"  88,   8P                                         88             88,      8P                             88 ";
		Sleep(500);
		gotoXY(1, 12);
		cout <<"  88aaaaaa8P'  8b,dPPYba,   ,adPPYba,  ,adPPYYba,  88   ,d8       88aaaaaa8P'  8b, dPPYba, 88,  adPPYba,  88,   d8,    ,adPPYba, ";
		Sleep(500);
		gotoXY(1, 13);
		cout <<"  88       8b, 88P'    Y8  a8P_____88         `Y8  88 ,a8         88      8b,  88P'    Y8  88  a8      ""   88, a8      I8[       ";
		Sleep(500);
		gotoXY(1, 14);
		cout <<"  88      `8b  88          8PP         ,adPPPPP88  8888[          88      `8b  88          88  8b         8888[       ` Y8baa, ";
		Sleep(500);
		gotoXY(1, 15);
		cout <<"  88      a8P  88           8b,   ,aa  88,    ,88  88` Yba,       88     a8P   88          88   8a,   ,aa 88` Yba,    aa    ]8I ";
		Sleep(500);
		gotoXY(1, 16);
		cout << "  88888888P    88           ` Ybbd8 '  ` 8bbdP Y8  88   `Y8a      88888888P    88          88   ""Ybbd8 '   88   `Y8a   'YbbdPa''";
		gotoXY(50, 25);
		system("pause");
}

int startMenu()
{
	int lenh;
	Color(14);
	gotoXY(37, 7);
	cout << "================================================================" << endl;
	gotoXY(37, 8);
	cout << "|                       BREAK BRICKS GAME                      |" << endl;
	gotoXY(37, 9);
	cout << "================================================================" << endl;
	gotoXY(37, 10);
	cout << "|           1. PLAY                                            |" << endl;
	gotoXY(37, 11);
	cout << "|           2. RESUME                                          |" << endl;
	gotoXY(37, 12);
	cout << "|           3. AUTO PLAY                                       |" << endl;
	gotoXY(37, 13);
	cout << "|           4. HOW TO PLAY                                     |" << endl;
	gotoXY(37, 14);
	cout << "|           5. QUIT GAME                                       |" << endl;
	gotoXY(37, 15);
	cout << "================================================================" << endl;
	gotoXY(37, 16);
	cout << "YOUR CHOICE: ";
	cin >> lenh;
	return lenh;
}

void textLevel(int level)
{
	switch (level)
	{
	case 1:
	{
		Color(14);
		gotoXY(40, 5);
		cout << "db      d88888b db    db d88888b db         db" << endl;
		gotoXY(40, 6);
		cout << "88      88'     88    88 88'     88        o88" << endl;
		gotoXY(40, 7);
		cout << "88      88ooooo Y8    8P 88ooooo 88         88" << endl;
		gotoXY(40, 8);
		cout << "88      88~~~~~`8b   d8' 88~~~~~ 88         88" << endl;
		gotoXY(40, 9);
		cout << "88booo. 88.      `8bd8'  88.     88booo.    88" << endl;
		gotoXY(40, 10);
		cout << "Y88888P Y88888P    YP    Y88888P Y88888P    VP" << endl;
	}break;
	case 2:
	{
		Color(14);
		gotoXY(40, 5);
		cout << "db      d88888b db    db d88888b db	  .d888b." << endl;
		gotoXY(40, 6);
		cout << "88      88'     88    88 88'     88        VP  `8D" << endl;
		gotoXY(40, 7);
		cout << "88      88ooooo Y8    8P 88ooooo 88           odD'" << endl;
		gotoXY(40, 8);
		cout << "88      88~~~~~`8b   d8' 88~~~~~ 88         .88'" << endl;
		gotoXY(40, 9);
		cout << "88booo. 88.      `8bd8'  88.     88booo.   j88." << endl;
		gotoXY(40, 10);
		cout << "Y88888P Y88888P    YP    Y88888P Y88888P   888888D" << endl;

	}break;
	case 3:
	{
		Color(14);
		gotoXY(40, 5);
		cout << "db      d88888b db    db d88888b db        d8888b." << endl;
		gotoXY(40, 6);
		cout << "88      88'     88    88 88'     88        VP  `8D" << endl;
		gotoXY(40, 7);
		cout << "88      88ooooo Y8    8P 88ooooo 88          oooY'" << endl;
		gotoXY(40, 8);
		cout << "88      88~~~~~`8b   d8' 88~~~~~ 88          ~~~b." << endl;
		gotoXY(40, 9);
		cout << "88booo. 88.      `8bd8'  88.     88booo.   db   8D" << endl;
		gotoXY(40, 10);
		cout << "Y88888P Y88888P    YP    Y88888P Y88888P   Y8888P'" << endl;

	}break;
	default:
		break;
	}
	

}

int resultMenu(int score, int level)
{
	switch (level)
	{
	default:
	case 1:
		textLevel(1);
		break;
	case 2:
		textLevel(2);
		break;
	case 3:
		textLevel(3);
		break;
	}
	int lenh;
	Color(14);
	gotoXY(44, 15); 
	cout << "====================================";
	gotoXY(44, 16);
	cout << "|        YOUR SCORES:              |";
	gotoXY(70, 16);
	cout << score;
	gotoXY(44, 17);
	cout << "|           1. REPLAY              |";
	gotoXY(44, 18);
	cout << "|           2. QUIT GAME           |";
	gotoXY(44, 19); 
	cout << "====================================";
	gotoXY(44, 20);
	cout << "YOUR CHOICE: "; cin >> lenh;
	system("pause>nul");
	return lenh;
}



