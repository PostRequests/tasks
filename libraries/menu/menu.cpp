#include "menu.h"
#include <iostream>


void clearMenu(Menu& m) {
	for (int i = 0; i < m.count; i++) {
		delete[] m.item[i];
	}
	delete[] m.item;
	m.item = nullptr;
}
/// <summary>
/// �������� �������� ���� �� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showItemMenu(Menu m) {
	ColorANSI3b color;
	setCursorPosition(m.start);
	for (int i = 0; i < m.count; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		m.start.y++;
		setCursorPosition(m.start);
		std::cout << m.item[i];
		if (m.n == i) resetColor();
	}
	return;
}

int getShowMenu(Menu m, bool closeEnd) {
	showItemMenu(m);
	while (true)
	{
		char key = catchKey();
		if (key == 'w') {
			(m.n - 1 == -1) ? m.n = m.count - 1 : m.n -= 1;
			showItemMenu(m);
		}
		else if (key == 's') {
			(m.n + 1 == m.count) ? m.n = 0 : m.n += 1;
			showItemMenu(m);
		}
		else if (key == 13) {
			return m.n;
		}

	}
}

Menu constructMenu(Coordinate start, const char** item, int count, menuColor color, int lineSkip, char place, bool border) {
	Menu menu;
	menu.start = start;
	menu.count = count;
	menu.n = 0;
	menu.color = color;
	menu.lineSkip = lineSkip;
	menu.visible = false;
	menu.border = border;
	int maxWidthItem = strlen(item[0]); //������ ������ �������� �������� ���� � ��������
	//��������� ����� ������ �������� ��������
	for (int i = 1; i < count; i++){
		int width = strlen(item[i]);
		if (maxWidthItem < width)
			maxWidthItem = width;
	}
	maxWidthItem += 2; //��������� ������ �� ����� � ����� ��� \0
	menu.width = maxWidthItem + ((border)? 4:0); //����������� ������ ����

	
	char** pItem = new char *[count];
	for (int i = 0; i < count; i++)
		pItem[i] = new char[maxWidthItem + 1]; //�������� ������ ��� �������� ���� + ��� \0

	//��������� �������� ����
	//�������� ���������� �����������
	if (place == 'l')
		for (int i = 0; i < count; i++)
		{
			int j = 1;
			int len = strlen(item[i]); //������ ��������
			pItem[i][0] = ' ';
			for (;j < len +1; j++)
				pItem[i][j] = item[i][j - 1];
			for (; j < maxWidthItem; j++)
				pItem[i][j] = ' ';
			pItem[i][j] = '\0';
		}
	else if (place == 'r')
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]); //������ ��������
			int space = maxWidthItem - len - 1;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; j < maxWidthItem -1; j++)
				pItem[i][j] = item[i][j - space];
			pItem[i][j++] = ' ';
			pItem[i][j] = '\0';
			std::cout << pItem[i] << std::endl;
		}
	else if (place == 'c')
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]); //������ ��������
			int space = maxWidthItem - len - 1;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; j < maxWidthItem - 1; j++)
				pItem[i][j] = item[i][j - space];
			pItem[i][j++] = ' ';
			pItem[i][j] = '\0';
			std::cout << pItem[i] << std::endl;
		}
	menu.item = pItem;
	
	return menu;
}