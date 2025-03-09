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
Menu getEditMenu(Menu menu, int numPer);
void task1(char***& books, int& count, Menu& mLib, Menu& mSearch, Menu& mSort, Menu& mEdit);

int getShowArrows(int count);

int main()
{
	system("chcp 1251>null");
	FullScreenMode();
	Coordinate cSize = getConsoleSize();
	gitPush("������ ������ ������  �� � 24");
	//��������� �������������� �����
	int count = 0;
	char*** books = createPointer(count);
	/////;
	Menu m = getMainMenu();
	Menu mLib = getLibMenu();
	Menu mSearch = getSearchMenu(mLib, 4);
	Menu mSort = getSortMenu(mLib, 5);
	Menu mEdit = getEditMenu(mLib, 3);
	while (true)
	{
	int input = getShowMenu(m);
	if (input == 0) {
		task1(books, count, mLib, mSearch, mSort, mEdit);
	}
	else if (input == 1)
		break;
	else if (input == 2)
		break;
	}
	clearMenu(mSearch);
	clearMenu(mLib);
	clearMenu(m);
	/*for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 4; j++)
			delete[] books[i][4];
		delete[] books[i];
	}
	delete books;*/
	system("cls");
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
	Coordinate startMenu = { cSize.x / 2 - 19,  cSize.y / 3};///cSize.y/3
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
		"<- ������������� �����",
		"<- ����� ����",
		"<- ����������",
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
	int marginHead[] = { 0,indent+1,0,indent };//{top, left, down, right}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}

Menu getSearchMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "������������ ������ �������� ����";
	const char* item[] = {
		"�� ��������",
		"�� ������",
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
	   "������"      //����
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
		"����������� �����" 
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

Menu getEditMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //������������ ������ �������
	//��������� �������� ����
	char headMenu[] = "������������ ������ �������� ����";
	const char* item[] = {
		"��������",
		"�����",
		"������������",
		"����"
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

int getShowArrows(int count) {
	if (!count) return -1;
	int result = 0;
	setCursorPosition(0, 8);
	std::cout << "-->";
	while (true)
	{
		char key = catchKey();
		if (key == 'w' or key == 's') {
			
			if (key == 'w') (result - 1 == -1) ? result = count - 1 : result -= 1;
			else if (key == 's') (result + 1 == count) ? result = 0 : result += 1;
			drawEmptyRectangle(0, 8, count * 3, 4, 0);
			setCursorPosition(0, 8 + (result * 3));
			std::cout << "-->";
		}
		else if (key == 13) {
			resetColor();
			drawEmptyRectangle(0, 8, count * 3, 4, 0);
			setCursorPosition(0, 0);
			return result;
		}
	}

}

void task1(char *** &books, int &count, Menu &mLib, Menu &mSearch, Menu &mSort, Menu &mEdit) {
	Coordinate cSize = getConsoleSize();
	showBook(books, count);
	while (true)
	{
		mLib.n = getShowMenu(mLib, false);
		if (mLib.n == 4) {//����� ����
			int iSearch = getShowMenu(mSearch);
			setCursorPosition(0, 5);
			std::cout << "������� �����: ";
			const int limitSymbol = 4 * 1024;
			char str[limitSymbol];
			std::cin.getline(str, limitSymbol);

			int iFound = searchBook(books, count, iSearch, str);
			if (iFound > -1)
			{
				drawEmptyRectangle(0, 8, (count + 2) * 3, cSize.x - 27, 0);
				setCursorPosition(0, 8);
				showBook(books, count, iFound);
				drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			}
			else {
				std::cout << "�� ������� ���������� \n";
				system("pause");
				drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			}
			setCursorPosition(0, 5);
			system("pause");
			drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			drawEmptyRectangle(0, 8, (count + 2) * 3, cSize.x - 27, 0);
			showBook(books, count);
		}
		else if (mLib.n == 5)//���������� ����
		{
			int iSort = getShowMenu(mSort);
			sortBooks(books, count, iSort);
			showBook(books, count);
		}
			
		else if (mLib.n == 3) {//������������� �����
			int iChange = getShowArrows(count);
			if (iChange < -1) continue;
			int whatChange = getShowMenu(mEdit);
			setCursorPosition(0, 5);
			std::cout << "������� ���������: ";
			const int limitSymbol = 4 * 1024;
			char str[limitSymbol];
			std::cin.getline(str, limitSymbol);
			drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			editBook(books, count, iChange, whatChange, str);
			showBook(books, count);
		}
		else if (mLib.n == 2) {//�������  �����
			showBook(books, count);
			int iDel = getShowArrows(count);
			if (iDel > -1)
				delBook(books, count, iDel);
			showBook(books, count);
		}
		else if (mLib.n == 0) {//������ ���� ����
			showBook(books, count);
		}
		else if (mLib.n == 1) { //�������� �����
			char** newB = new char* [4];
			ColorANSI3b c;
			const int limitSymbol = 4 * 1024;
			char str[limitSymbol];
			setCursorPosition(0, 4);
			std::cout << " ��������: ";
			std::cin.getline(str, limitSymbol);
			newB[0] = new char[strlen(str) + 1];
			strcpy_s(newB[0], strlen(str) + 1, str);
			setColor(c.RedFG);
			std::cout << " �����: ";
			std::cin.getline(str, limitSymbol);
			newB[1] = new char[strlen(str) + 1];
			strcpy_s(newB[1], strlen(str) + 1, str);
			setColor(c.BlueFG);
			std::cout << " ������������: ";
			std::cin.getline(str, limitSymbol);
			newB[2] = new char[strlen(str) + 1];
			strcpy_s(newB[2], strlen(str) + 1, str);
			setColor(c.GreenFG);
			std::cout << " ����: ";
			std::cin.getline(str, limitSymbol);
			newB[3] = new char[strlen(str) + 1];
			strcpy_s(newB[3], strlen(str) + 1, str);

			drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, c.BlackBG);
			addBook(books, count, newB);
			for (int i = 0; i < 4; i++)
				delete[] newB[i];
			delete[] newB;
			showBook(books, count);
		}
		else if (mLib.n == 6) { //�����
			clsHead(mLib);
			clsMenu(mLib);
			system("cls");
			break;
		}
	}
}