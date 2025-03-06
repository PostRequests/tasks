#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"

//������� �������� ����
Menu getMainMenu();


int main()
{
	system("chcp 1251>null");
	gitPush("���� ������ �� �����");
	Menu m = getMainMenu();
	
	getShowMenu(m, true);

	clearMenu(m);
}



Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "�������� ������ � 24";
	const char* item[] = {
		"������ 1",
		"������ 2",
		"�����",
	};
	const char* textInfo[] = {
		"������������ ��������� �����������. �������� ��������� ������ (��������, �����, ������������, ����). �������� ������������ ������ ��� �������� ����. ���������� ��� ���� ��������� �����������:\n� �������� �����\n� ������� �����\n� ������������� �����\n� ������ ���� ����\n� ����� ���� �� ������\n� ����� ����� �� ��������\n� ���������� ������� �� �������� ����\n� ���������� ������� �� ������\n� ���������� ������� �� ������������",
		"������������ ��������� �����������. �������� ��������� ������ (��������, �����, ������������, ����). �������� ��������������� ������ ��� �������� ����. ���������� ��� ���� ��������� �����������:\n� �������� �����\n� ������� �����\n� ������������� �����\n� ������ ���� ����\n� ����� ���� �� ������\n� ����� ����� �� ��������\n� ���������� ������� �� �������� ����\n� ���������� ������� �� ������\n� ���������� ������� �� ������������",
		"�����",
	};
	Coordinate startMenu = { 1,  4 };///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	//��������� ����� ����
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };

	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent };
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);

	//��������� ���������� �� ��������� ����
	Coordinate start{ 1, cSize.y - 12 };
	Coordinate finish{ cSize.x - 2, cSize.y };
	menuColor colorInfo{ c.BlackBG, c.WhiteFG, c.YellowFG };
	int sInfo = sizeof(textInfo) / sizeof(textInfo[0]);
	if (countMenu != sInfo) {
		std::cout << "�������� ������, �� ���������� ���������� ���������" << std::endl;
		abort();
		//��������� ��������� � ������, ���� �������� ���� �� ����� ���������� ��������� ��������
	}
	addInfoMenu(m, start, finish, textInfo, true, colorInfo);
	return m;
}

