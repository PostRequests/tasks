#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"

//Создает основное меню
Menu getMainMenu();


int main()
{
	system("chcp 1251>null");
	gitPush("Реализация меню");
	Menu m = getMainMenu();
	getShowMenu(m, true);
}

Menu getMainMenu() {
	ColorANSI3b c;

	Coordinate startMenu = { 5,5 };
	const char* item[] = {
		"Первый элемент",
		"Второй",
		"Третий",
		"Четвертый"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.RedBG,c.BlackFG,c.MagentaFG };
	Menu m = constructMenu(startMenu, item, countMenu, colorMenu, 1, 'c', true);

	Coordinate startHead = { 1,1 };
	char headMenu[] = "Menu #1";
	int marginHead[] = { 1,1,1,1 };
	addHeadMenu(m, startHead, headMenu, marginHead, true);

	return m;
}