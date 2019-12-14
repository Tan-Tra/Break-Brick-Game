#include "GameManager.h"

void GameManager::guide()
{
	fstream f("Guide.txt");
	if (f.fail())
	{
		cout << "Khong mo duoc file Guide." << endl;
		return;
	}
	char a[501];
	Color(14);
	int i = 5;
	while (!f.eof())
	{
		f.getline(a, 500);
		gotoXY(20, i++);
		cout << a << endl;
	}
	system("pause>nul");
}


int GameManager::play(bool& playing, int& broken_bricks)
{
	ball.setDirection(UP);
	ball.draw();
	pad.draw();
	system("pause>nul");
	srand(time(NULL));
	while (playing)
	{
		player.map.printMap();
		ball.conllision(player.map, pad,player.score,player.broken_bricks);
		ball.conllision(player.map, pad,player.score,player.broken_bricks);
		
		player.printScore();
		ball.move();
		Sleep(30);


		pad.setDirection(STOP);


		if (GetAsyncKeyState(27))
		{
			playing = false;
		}

		if (GetAsyncKeyState(37))
		{
			pad.moveLeft();
			pad.setDirection(LEFT);
		}

		if (GetAsyncKeyState(39))
		{
			pad.moveRight();
			pad.setDirection(RIGHT);
		}


		if (ball.getPosition().y > SCREEN_Y)
		{

			playing = false;
			return 0;
		}

		if (player.map.bricks == player.broken_bricks)
		{
			playing = false;
			player.level++;
			menu.passLevel();
			return 1;
		}
	}
}

int GameManager::autoPlay(bool& playing, int& broken_bricks)
{

	ball.setDirection(UP);
	ball.draw();
	pad.draw();

	system("pause>nul");
	srand(time(NULL));
	while (playing)
	{
		player.map.printMap();
		ball.conllision(player.map, pad, player.score,player.broken_bricks);
		ball.conllision(player.map, pad, player.score,player.broken_bricks);
		
		player.printScore();
		ball.move();
		Sleep(20);


		if (GetAsyncKeyState(27))
		{
			playing = false;
		}


		if (ball.getPosition().x < pad.getPosition().x-PADDLE_SPEED)
		{
			pad.moveLeft();
		}

		if (ball.getPosition().x > pad.getPosition().x+PADDLE_SPEED)
		{
			pad.moveRight();
		}

		eDir r = (eDir)(rand() % 3);
		pad.setDirection(r);

		if (ball.getPosition().y > SCREEN_Y)
		{
			playing = false;
			return 0;
		}
			
		if (player.map.bricks == player.broken_bricks)
		{
			playing = false;
			player.level++;
			return 1;
		}
	}
}

void GameManager::runGame()
{
	//menu.printTitle();
	dsuser.loadFromFile();
	int check = player.fread();
	if (check == -1)
	{
		player.level = 1;
		player.score = 0;
		User* user = new User(player.ten, player.score, player.level);
		dsuser.addUser(*user);
	}
	int lenh=100;
	do
	{
		system("cls");
		lenh = menu.startMenu();
		bool playing = true;
		do
		{			
			switch (lenh)
			{
			case 1:
			{
				/*system("cls");
				player.map.drawWall();
				player.map.freadMap(player.level);
				player.map.printMap();
				player.printMenuScore();
				player.printScore();
				play(playing);*/
				player.level = 1;
				player.score = 0;
				ball.resset();
				pad.reset();
				player.map.freadMap(player.level);
			}
			case 2:
			{
				
				do
				{
					system("cls");
					player.map.drawWall();
					player.map.printMap();
					player.printMenuScore();
					player.printScore();
					if (play(playing,player.broken_bricks) == 0)
					{
						system("cls");
						lenh = menu.resultMenu(player.score, player.level);
						if (lenh == 1) playing = true;
						break;
					}
					if (player.level <= 3)
					{
						player.map.freadMap(player.level);
						playing = true;
					}
					else {
						//in khung hình chúc mừng win game
						menu.winGame();
						playing = false;
						return;
					}
				} while (true);
				
			}break;
			case 3:
			{
				do
				{
					system("cls");
					player.map.drawWall();
					player.map.printMap();
					player.printMenuScore();
					player.printScore();
					if (autoPlay(playing, player.broken_bricks) == 0)
					{
						system("cls");
						lenh = menu.resultMenu(player.score, player.level);
						if (lenh == 1) playing = true;
						break;
					}
					if (player.level <= 3)
					{
						player.map.freadMap(player.level);
						playing = true;
					}
					else {
						//in khung hình chúc mừng win game
						menu.winGame();
						playing = false;
						return;
					}
				} while (true);
			}break;
			case 4:
			{
				system("cls");
				dsuser.printHightScore();
				system("pause>nul");
				lenh = -1;
			}break;
			case 5:
			{
				system("cls");
				guide();
				system("pause>nul");
				lenh = -1;
			}break;
			default:
				lenh = 0;
				break;
			}
		} while (lenh!=0&&lenh!=-1);
		
	} while (lenh!=0);

	player.fwrite();
	dsuser.updateUser(player.ten, player.score, player.level);
	dsuser.fwriteGoal();
}
