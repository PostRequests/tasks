#include <iostream>
#include <Windows.h>
#include "MyLib/console/console.h"
#include "MyLib/menu/menu.h"
#include "MyLib/git hub/git.h"
#include "MyLib/text/text.h"
#include "Pointer.h"
//������� �������� ����
Menu getMainMenu();
//������� �������� ���� ����������
Menu getLibMenu();
/// <summary>
/// ������� ���� ������
/// </summary>
/// <param name="menu">����������, ��� ����������� ��������� �� ��������</param>
/// <param name="numPer">����� ������ �������� �������� ����</param>
/// <returns></returns>
Menu getSearchMenu(Menu menu, int numPer);
/// <summary>
/// ������� ���� ����������
/// </summary>
/// <param name="menu">����������, ��� ����������� ��������� �� ��������</param>
/// <param name="numPer">����� ������ �������� �������� ����</param>
/// <returns></returns>
Menu getSortMenu(Menu menu, int numPer);
/// <summary>
/// ��������� ��������� ����� ����
/// </summary>
/// <param name="count">���������� ����, ������� ����������</param>
/// <returns></returns>
char*** createPointer(int& count);



int main()
{
	system("chcp 1251>null");
	gitPush("���������� ������ �������� �� � 24");
	int count = 0;
	char*** books = createPointer(count);
	delBook(books, count, 4);
	showBook(books, count);
	/////
	Menu m = getMainMenu();
	Menu mLib = getLibMenu();
	Menu mSearch = getSearchMenu(mLib, 4);
	Menu mSort = getSortMenu(mLib, 5);
	getShowMenu(m);
	while (true)
	{
		mLib.n = getShowMenu(mLib, false);
		 
		if (mLib.n == 4)
			getShowMenu(mSearch);
		else if(mLib.n == 5)
			getShowMenu(mSort);
	}

	clearMenu(mSearch);
	clearMenu(mLib);
	clearMenu(m);
}



Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "�������� ������ � 24";
	const char* item[] = {
		"��������� ���� ������������",
		"��������� ����: ��������������� ������",
		"�����",
	};
	const char* textInfo[] = {
		"������������ ��������� �����������. �������� ��������� ������ (��������, �����, ������������, ����). �������� ������������ ������ ��� �������� ����. ���������� ��� ���� ��������� �����������:\n� �������� �����\n� ������� �����\n� ������������� �����\n� ������ ���� ����\n� ����� ���� �� ������\n� ����� ����� �� ��������\n� ���������� ������� �� �������� ����\n� ���������� ������� �� ������\n� ���������� ������� �� ������������",
		"������������ ��������� �����������. �������� ��������� ������ (��������, �����, ������������, ����). �������� ��������������� ������ ��� �������� ����. ���������� ��� ���� ��������� �����������:\n� �������� �����\n� ������� �����\n� ������������� �����\n� ������ ���� ����\n� ����� ���� �� ������\n� ����� ����� �� ��������\n� ���������� ������� �� �������� ����\n� ���������� ������� �� ������\n� ���������� ������� �� ������������",
		"�����",
	};
	Coordinate startMenu = { 1,  cSize.y / 3 };///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);

	//��������� ����� ����
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent + 1 };//{top, left, down, right}
	

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
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	addInfoMenu(m, start, finish, textInfo, true, colorInfo);
	return m;
}

Menu getLibMenu() {
	
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "������������ ������ �������� ����";
	const char* item[] = {
		"������ ���� ����",
		"�������� �����",
		"������� �����",
		"������������� �����",
		"����� ����",
		"����������",
		"�����"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //������ ����
	Coordinate startMenu = { cSize.x - mWidth,  4};
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);

	//��������� ����� ����
	menuColor colorHead = { c.CyanBG,c.BlackFG, c.MagentaFG };
	Coordinate startHead = { 1,1 };//���������� ������ ��������� �������� ����
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent };//{top, left, down, right}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}

Menu getSearchMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "������������ ������ �������� ����";
	const char* item[] = {
		"�� ������",
		"�� ��������",
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //������ ����
	//���� ��������� ������������ �������� ������ ����
	//����� ��������� ���� ��� �������
	Coordinate startMenu; 
	//������ ���������� ���� ������������ ��������
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));
	
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

Menu getSortMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "������������ ������ �������� ����";
	const char* item[] = {
		"�� ��������",
		"�� ������",
		"�� ������������"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //������ ����
	//���� ��������� ������������ �������� ������ ����
	//����� ��������� ���� ��� �������
	Coordinate startMenu;
	//������ ���������� ���� ������������ ��������
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));

	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

char*** createPointer(int & count) {
	//�������������� 5 ��������� ����
	char little_prince[][100] = {
	   "��������� �����",       //��������
	   "������ �� ����-��������", //�����
	   "Reynal & Hitchcock",     //������������
	   "����������� ������"      //����
	};

	char ulyss[][100] = {
		"�����",                  
		"������ �����",           
		"Shakespeare and Company", 
		"������������� �����"     
	};

	char atlas_shrugged[][100] = {
		"������ ��������� �����", 
		"��� ����",               
		"Random House",           
		"����������� �����, ����������" 
	};

	char shadow_of_the_wind[][100] = {
		"���� �����",             
		"������ ���� �����",      
		"Planeta",               
		"����������� �����, ������������ ��������" 
	};

	char hunger_games[][100] = {
		"�������� ����",         
		"������ �������",        
		"Scholastic",            
		"������� ����������, ����������"
	};
	char*** books = nullptr;
	addBook(books, count, hunger_games);
	addBook(books, count, shadow_of_the_wind);
	addBook(books, count, atlas_shrugged);
	addBook(books, count, ulyss);
	addBook(books, count, little_prince);
	return books;
}
