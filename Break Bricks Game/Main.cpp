#include "GameManager.h"
#include"Player.h"
#include"Menu.h"

#include <ctime>


void main()
{

	startMenu();
	Nocursortype();
	Map map;
	map.freadMap();
	map.drawWall();
	map.printMap();
	bool playing = true;
	play(map, playing);
	

}