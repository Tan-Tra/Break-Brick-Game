#include "GameManager.h"
#include <ctime>


void main()
{
	Map map;
	map.freadMap();
	map.drawWall();
	map.printMap();
	bool playing = true;
	play(map, playing);
	

	


}