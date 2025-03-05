#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"


int main()
{
	system("chcp 1251>null");
	gitPush("Полное обновление проекта");
	Coordinate startMenu = { 5,5 };
	const char* item[] = {
		"one",
		"Второе",
		"Третье"
	};
	int countMenu = 3;
	menuColor colorMenu = { 0,0,0,0,0 };
	Menu m =constructMenu(startMenu, item, countMenu, colorMenu, 0, 'c');
	getShowMenu(m);
}