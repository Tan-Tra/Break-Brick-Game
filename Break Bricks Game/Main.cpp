#include "GameManager.h"



void main()
{

	Nocursortype();
	Map map;
	map.freadMap();
	map.drawWall();
	map.printMap();
	bool playing = true;
	autoPlay(map, playing);
	

	


}