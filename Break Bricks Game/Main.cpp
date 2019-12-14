#pragma comment(lib, "winmm.lib")
#include "GameManager.h"





void main()
{
	bool isPlay = PlaySound("PongMusic", NULL, SND_ASYNC);
	
	Nocursortype();
	GameManager breakBricks;
	breakBricks.runGame();
}