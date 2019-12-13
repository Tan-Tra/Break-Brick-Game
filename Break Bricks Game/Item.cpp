#include "Item.h"
#include "..\..\..\GitHub\Break-Brick-Game\Break Bricks Game\Item.h"

Item::Item()
{
	existed = false;
	t0 = clock();
}

Item::~Item()
{
	existed = false;
}

void Item::createItem(Map& map)
{
	///kind = (eItem)(rand() % 3);
	kind = BOM;
	existed = true;
	do
	{
		position.x = (rand() % (SCREEN_X - 2)) + 1;
		position.y = (rand() % (SCREEN_Y - 10)) + 1;
	} while (position.y < 16 && (map.data[position.y - 1][(position.x - 1) / 4] != 0 || (position.x - 1) % 4 == 3));
}

void Item::print()
{
	gotoXY(position.x, position.y);
	switch (kind)
	{
	case x2:
		Color(3);
		break;
	case d2:
		Color(4);
		break;
	case BOM:
		Color(5);
		break;
	default:
		break;
	}
	cout << "@@";
	Color(15);
}

void Item::printFill()
{
	gotoXY(position.x, position.y);
	cout << "  ";
}
