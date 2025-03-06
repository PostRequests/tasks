#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"

//������� �������� ����
Menu getMainMenu();


int main()
{
	system("chcp 1251>null");
	gitPush("��������� ����� ����");
	Menu m = getMainMenu();
	getShowMenu(m, true);
}

Menu getMainMenu() {
	ColorANSI3b c;

	Coordinate startMenu = { 5,6 };
	const char* item[] = {
		"������ � 1",
		"������ � 1",
		"�����",
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m = constructMenu(startMenu, item, countMenu, colorMenu, 1, 'c', true);
	menuColor colorHead = {c.YellowBG,c.BlackFG, c.GreenFG};
	Coordinate startHead = { 5,3 };
	char headMenu[] = "Menu %1";
	int marginHead[] = { 0,4,0,5 };
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);

	return m;
}

