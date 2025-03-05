#include "menu.h"
#include <iostream>


void clearMenu(Menu& m) {
	for (int i = 0; i < m.count; i++) {
		delete[] m.item[i];
	}
	delete[] m.item;
	m.item = nullptr;
}

void showItemMenu(Menu m) {
	ColorANSI3b color;
	setCursorPosition(m.start);
	for (int i = 0; i < m.count; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		m.start.y++;
		setCursorPosition(m.start);
		std::cout << m.item[i] << "  ";
		if (m.n == i) resetColor();
	}
	return;
}

int scrollMenu(Menu m) {
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

Menu constructMenu(Coordinate start, char** item, int count, menuColor color, char place, bool border, int lineSkip) {
	Menu menu;
	menu.border = border;
	menu.color = color;
	menu.count = count;
	menu.start = start;
	menu.visible = false;
	menu.lineSkip = lineSkip;
	menu.n = 0;
	int maxWidthItem = strlen(item[0]); //Ширина самого длинного элемента меню в символах
	//Вычисляем длину самого длинного элемента
	for (int i = 1; i < count; i++){
		int width = strlen(item[i]);
		if (maxWidthItem < width)
			maxWidthItem = width;
	}
	maxWidthItem += 2; //Добавляем отступ по краям

	//Проверяем позиционирование меню, по какому краю выравнивать, либо по центру
	if (!place || place == 'l')
		maxWidthItem = 0; //Если по левому краю, то нам не нужна длинна
	
	return menu;
}