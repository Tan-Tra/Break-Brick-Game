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
	bool bom = false;

	ball.draw(bom);
	pad.draw();

	system("pause>nul");
	srand(time(NULL));

	clock_t t1 = clock();
	clock_t t2;
	Item item;

	while (playing)
	{

		t2 = clock();

		//tao item
		if ((int)(t2 - t1) > TIME_TO_APPEAR_ITEM)
		{
			item.createItem(player.map);
			t1 = t2;
		}

		if ((int)(t2 - t1) > TIME_ITEM_EXIST)
		{
			item.existed = false;
		}

		if (item.existed)
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{

					if (((ball.getPosition().x + i == item.position.x) || (ball.getPosition().x + i == item.position.x + 1)) && (ball.getPosition().y + j == item.position.y))
					{
						switch (item.kind)
						{
							////
						case x2:
							player.score *= 2;
						
							break;
						case d2:
							player.score /= 2;
						 
							break;
							
						case BOM:
							bom = true;
							item.t0 = clock();
							break;
						case TARGET:
							player.score += 1000;
							 
							return 1;
						default:
							break;
						}
						item.existed = false;
						i = 2; j = 2;
						item.printFill();
					}
				}

			}
		}

		if ((int)(t2 - item.t0) > TIME_SUPERBALL)
		{
			bom = false;
		}

		player.map.printMap();
		if (item.existed)
		{
			item.print();
		}

		ball.conllision(player.map, pad,player.score,player.broken_bricks,bom);
		ball.conllision(player.map, pad,player.score,player.broken_bricks,bom);

		
		player.printScore();
		ball.move(bom);

		pad.setDirection(STOP);


		if (GetAsyncKeyState(27))
		{
			playing = false;
			return -1;
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
			return 1;
		}
		Sleep(20);
		if (item.existed)
		{
			item.printFill();
		}
	}
}

int GameManager::autoPlay(bool& playing, int& broken_bricks)
{
	bool bom = false;
	ball.setDirection(UP);
	ball.draw(bom);
	pad.draw();

	system("pause>nul");
	srand(time(NULL));

	clock_t t1 = clock();
	clock_t t2;
	Item item;

	while (playing)
	{

		t2 = clock();

		//tao item
		if ((int)(t2 - t1) > TIME_TO_APPEAR_ITEM)
		{
			item.createItem(player.map);
			t1 = t2;
		}

		if ((int)(t2 - t1) > TIME_ITEM_EXIST)
		{
			item.existed = false;
		}

		if (item.existed)
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{

					if (((ball.getPosition().x + i == item.position.x) || (ball.getPosition().x + i == item.position.x + 1)) && (ball.getPosition().y + j == item.position.y))
					{
						switch (item.kind)
						{
							////
						case x2:
							player.score *= 2; break;
						case d2:
							player.score /= 2; break;

						case BOM:
							bom = true;
							item.t0 = clock();
							break;
						case TARGET:
							player.score += 1000;
								player.level++;
							return 1;
						default:
							break;
						}
						item.existed = false;
						i = 2; j = 2;
						item.printFill();
					}
				}

			}
		}

		if ((int)(t2 - item.t0) > TIME_SUPERBALL)
		{
			bom = false;
		}


		player.map.printMap();
		if (item.existed)
		{
			item.print();
		}

		ball.conllision(player.map, pad, player.score,player.broken_bricks,bom);
		ball.conllision(player.map, pad, player.score,player.broken_bricks,bom);
		
		
		player.printScore();
		ball.move(bom);



		if (GetAsyncKeyState(27))
		{
			playing = false;
			return -1;
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
		Sleep(20);
		if (item.existed)
		{
			item.printFill();
		}
	}
}

void GameManager::runGame()
{
	resizeConsole(880, 450);
	menu.printTitle();
	resizeConsole(813, 675);
	dsuser.loadFromFile();
	int check1 = player.fread();
	bool isPlay = PlaySound("PongMusic", NULL, SND_ASYNC);
	if (check1 == -1)
	{
		player.level = 1;
		player.score = 0;
		player.map.freadMap(player.level);
		User* user = new User(player.name, player.score, player.level);
		dsuser.addUser(*user);
		delete user;
	}
	int lenh;
	do
	{
		system("cls");
		lenh = menu.startMenu();
		bool playing = true;
		bool replay = false;
		do
		{			
			switch (lenh)
			{
			case 1://new game
			{
				if (replay)
				{
					replay = false;
					player.score = 0;
					ball.reset();
					pad.reset();
					player.map.freadMap(player.level);
				}
				else
				{
					player.level = 1;
					player.score = 0;
					ball.reset();
					pad.reset();
					player.map.freadMap(player.level);
				}
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
					ball.reset();
					pad.reset();
					int check = play(playing, player.broken_bricks);
					if ( check == 0)
					{
						system("cls");
						lenh = menu.resultMenu(player.score, player.level);
						if (lenh == 1) {
							playing = true;
							replay = true;
						}
						break;
					}
					if (check == -1)
					{
						break;
					}
					if (player.level <= 3)
					{
						menu.passLevel();
						menu.textLevel(player.level);
						system("pause>nul");
						player.broken_bricks = 0;
						player.map.freadMap(player.level);
						playing = true;
					}
					else {
						//in khung hình chúc mừng win game
						menu.winGame();
						playing = false;
						lenh = -1;
						break;
					}
				} while (true);
				player.fwrite();
				dsuser.updateUser(player.name, player.score, player.level);
				dsuser.fwriteGoal();
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
					ball.reset();
					pad.reset();
					int check = autoPlay(playing, player.broken_bricks);
					if (check == 0)
					{
						system("cls");
						lenh = menu.resultMenu(player.score, player.level);
						if (lenh == 1) {
							replay = true;
							playing = true;
						}
						break;
					}
					if (check == -1)
					{
						break;
					}
					if (player.level <= 3)
					{
						menu.passLevel();
						menu.textLevel(player.level);
						system("pause>nul");
						player.broken_bricks = 0;
						player.map.freadMap(player.level);
						playing = true;
					}
					else {
						//in khung hình chúc mừng win game
						menu.winGame();
						playing = false;
						lenh = -1;
						break;
					}
				} while (true);
				player.fwrite();
				dsuser.updateUser(player.name, player.score, player.level);
				dsuser.fwriteGoal();
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

	
	
}
