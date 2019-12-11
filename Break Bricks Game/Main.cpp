#include "GameManager.h"
#include"Player.h"
#include <ctime>


void main()
{
	/*Map map;
	map.freadMap(1);
	map.drawWall();
	map.printMap();
	bool playing = true;
	play(map, playing);*/
	Player player;
	player.getMap().drawWall();
	player.printScore();
	
}