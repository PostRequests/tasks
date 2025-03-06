#include "menu.h"
#include <iostream>


void clearMenu(Menu& m) {
	for (int i = 0; i < m.count; i++) {
		delete[] m.item[i];
	}
	delete[] m.item;
	m.item = nullptr;
	if (m.info.visible) {
		for (int i = 0; i < m.count; i++) {
			delete[] m.info.text[i];
		}
		delete m.info.text;
		m.info.text = nullptr;
	}
	if (m.head.visible) {
		delete[] m.head.text;
		m.head.text = nullptr;
	}
}
//Задаем цветную палитру элемента меню
void setItemColor(int color1, int color2) {
	if (color1)
		((color2) ? setColor(color1, color2) : setColor(color1));
	else if (color2)
		setColor(color2);
	else resetColor();
}
//Перерисовываем выделенный элемент меню
void redrawItem(Menu m) {
	m.start.y += (m.n) * (m.lineSkip + 1);
	setCursorPosition(m.start);
	std::cout << m.item[m.n];
	setCursorPosition(0, 0);
}
/// <summary>
/// Печатает элементы меню на экране
/// </summary>
/// <param name="m">Структура меню</param>
void showItemMenu(Menu m) {

	if (m.border) {
		setItemColor(m.color.BG, m.color.borderFG);
		drawFillRectangle(m.start, m.finish);
		m.start.x++;
		m.start.y++;
	}
	Coordinate  temp = m.start;
	setItemColor(m.color.BG, m.color.FG);
	setCursorPosition(temp);
	for (int i = 0; i < m.count; i++) {
		setCursorPosition(temp);
		std::cout << m.item[i];
		temp.y += 1 * (m.lineSkip + 1);
	}
	if (m.lineSkip) { //Закрашиваем пустоты между строк, если имеются
		setColor(m.color.borderFG);
		temp = m.start;
		for (int i = 0; i < m.count - 1; i++)
		{
			temp.y++; //Пропускаем нарисованный элемент меню
			setCursorPosition(temp);
			for (int j = 0; j < m.lineSkip; j++)
			{
				for (int k = 0; k < m.width - 2; k++)
					std::cout << '-';
				temp.y++;
				setCursorPosition(temp);

			}
		}
	}
	setItemColor(m.color.hiBG, m.color.hiFG);
	redrawItem(m);
	setCursorPosition(0, 0);
	resetColor();
}



void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border, menuColor color) {
	if (color.BG)
		m.head.color = color;
	else
		m.head.color = m.color;
	m.head.visible = true;
	m.head.start = start;
	m.head.text = new char[(strlen(head) + 1)];//Выделяю память
	strcpy_s(m.head.text, strlen(head) + 1, head);//Копирую содержимое
	m.head.inTop = margin[0];
	m.head.inLeft = margin[1];
	m.head.inDown = margin[2];
	m.head.inRight = margin[3];
	m.head.border = border;
	m.head.width = strlen(head) + m.head.inLeft + m.head.inRight + ((border) ? 2 : 0);
	m.head.height = 1 + m.head.inTop + m.head.inDown + ((border) ? 2 : 0);
	m.head.finish = { m.head.start.x + m.head.width - 1,
							m.head.start.y + m.head.height - 1 };
}

void addInfoMenu(Menu& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor color) {
	if (color.BG)
		m.info.color = color;
	else
		m.info.color = m.color;
	m.info.visible = true;
	m.info.start = start;
	m.info.finish = finish;
	m.info.height = finish.y - start.y - ((border) ? 2 : 0);
	m.info.width = finish.x - start.x - ((border) ? 2 : 0);
	char** pInfo = new char* [m.count];
	for (int i = 0; i < m.count; i++) {
		pInfo[i] = new char[strlen(textInfo[i]) + 1]; //Выделяем память под элементы меню + Для \0
		strcpy_s(pInfo[i], strlen(textInfo[i]) + 1, textInfo[i]);
	}
	m.info.text = pInfo;

	//m.info = i;
}

void clsMenu(Menu m) {
	drawEmptyRectangle(m.start.x, m.start.y, m.height, m.width);
	setCursorPosition(1, 1);
}


void showHeadMenu(Menu m) {
	Head h = m.head; //Для удобства, чтобы было меньше текста
	setCursorPosition(h.start);
	if (m.head.border) {//Рисуем рамку, если она есть
		setItemColor(h.color.BG, h.color.borderFG);
		drawFillRectangle(m.head.start, m.head.finish);
		h.start.x++;
		h.start.y++;
		h.finish.x--;
		h.finish.y--;
	}
	if (h.color.BG)//Заливаем оставшуюся область цветом фона
		drawEmptyRectangle(h.start, h.finish, h.color.BG);
	setCursorPosition(h.start.x + h.inLeft,
		h.start.y + h.inTop);
	setItemColor(h.color.BG, h.color.FG);
	std::cout << h.text;

}
int getLengthNextWord(char* t) {
	int len = 0; // Вычисляемая длинна слова до пробела или конца текста
	for (; *t && *t != ' '; len++, t++);
	return len;
}

void showIfoMenu(Menu m) {
	setItemColor(m.info.color.BG, m.info.color.FG);
	setCursorPosition(m.info.start);
	if (m.head.border) {//Рисуем рамку, если она есть
		setItemColor(m.info.color.BG, m.info.color.borderFG);
		drawFillRectangle(m.info.start, m.info.finish);
		m.info.start.y++;
		m.info.start.x++;
		m.info.finish.y--;
		m.info.finish.x--;
	}
	drawEmptyRectangle(m.info.start, m.info.finish, m.info.color.BG);
	Coordinate s = m.info.start;
	setCursorPosition(m.info.start);
	char* pt = m.info.text[m.n];
	int lineBreaks = 0; //Количество переносов строки
	int currentLineLength = 0;// Количество уже использованных символов в текущей строке
	while (*pt)
	{
		int len = getLengthNextWord(pt);
		currentLineLength += len;
		if (currentLineLength < m.info.width) {
			for (int i = 0; i < len; i++)
				if (*pt == '\n') {
					lineBreaks++;
					currentLineLength = 0;
					setCursorPosition(s.x, s.y + lineBreaks);
					pt++;
				}
				else
					std::cout << *pt++;
			while (*pt == ' ') {
				currentLineLength++;
				std::cout << *pt++;
			}
		}
		else {
			lineBreaks++;
			currentLineLength = 0;
			setCursorPosition(s.x, s.y + lineBreaks);
		}
	}
	resetColor();
}

void clsHead(Menu m) {
	drawEmptyRectangle(m.head.start, m.head.finish, 0);
}
void clsInfo(Menu m) {
	drawEmptyRectangle(m.info.start, m.info.finish, 0);
}

int getShowMenu(Menu m, bool closeEnd) {

	if (m.head.visible)
		showHeadMenu(m);
	showItemMenu(m);
	if (m.info.visible)
		showIfoMenu(m);
	if (m.border) {
		m.start.x++;
		m.start.y++;
	}
	while (true)
	{
		char key = catchKey();
		if (key == 'w') {
			setItemColor(m.color.BG, m.color.FG);
			redrawItem(m);
			(m.n - 1 == -1) ? m.n = m.count - 1 : m.n -= 1;
			setItemColor(m.color.hiBG, m.color.hiFG);
			redrawItem(m);
			if (m.info.visible)
				showIfoMenu(m);
		}
		else if (key == 's') {
			setItemColor(m.color.BG, m.color.FG);
			redrawItem(m);
			(m.n + 1 == m.count) ? m.n = 0 : m.n += 1;
			setItemColor(m.color.hiBG, m.color.hiFG);
			redrawItem(m);
			if (m.info.visible)
				showIfoMenu(m);
		}
		else if (key == 13) {
			resetColor();
			if (closeEnd) {
				if (m.border) {
					m.start.x--;
					m.start.y--;
				}
				clsMenu(m);
				clsHead(m);
				clsInfo(m);
			}
			setCursorPosition(0, 0);
			return m.n;
		}
	}
}

void constructMenu(Menu &m,Coordinate start, const char** item, int count, menuColor color, int lineSkip, char place, bool border) {
	m.start = start;
	m.count = count;
	m.n = 0;
	m.color = color;
	m.lineSkip = lineSkip;
	m.visible = false;
	m.border = border;
	int maxWidthItem = strlen(item[0]); //Ширина самого длинного элемента меню в символах
	//Вычисляем длину самого длинного элемента
	for (int i = 1; i < count; i++) {
		int width = strlen(item[i]);
		if (maxWidthItem < width)
			maxWidthItem = width;
	}
	maxWidthItem += 2; //Добавляем отступ по краям и место для \0
	m.width = maxWidthItem + ((border) ? 2 : 0); //Рассчитываем ширину меню
	m.height = count * (lineSkip + 1) + ((border) ? 2 : 0) - lineSkip; //рассчитываем высоту
	m.finish = { m.start.x + m.width - 1,
							m.start.y + m.height - 1 };
	char** pItem = new char* [count];
	for (int i = 0; i < count; i++)
		pItem[i] = new char[maxWidthItem + 1]; //Выделяем память под элементы меню + Для \0

	//Заполняем элементы меню
	//Согласно указанному центрированию
	if (place == 'l')//Выравнивание по левому краю
		for (int i = 0; i < count; i++)
		{
			int j = 1;
			int len = strlen(item[i]);
			pItem[i][0] = ' ';
			for (; j < len + 1; j++)
				pItem[i][j] = item[i][j - 1];
			for (; j < maxWidthItem; j++)
				pItem[i][j] = ' ';
			pItem[i][j] = '\0';
		}
	else if (place == 'r')//Выравнивание по правому краю
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]);
			int space = maxWidthItem - len - 1;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; item[i][j - space]; j++)
				pItem[i][j] = item[i][j - space];
			pItem[i][j++] = ' ';
			pItem[i][j] = '\0';
		}
	else if (place == 'c')//Выравнивание по центру
		for (int i = 0; i < count; i++)
		{
			int j = 0;
			int len = strlen(item[i]); //Длинна элемента
			int space = (maxWidthItem - len) / 2;

			for (; j < space; j++)
				pItem[i][j] = ' ';
			for (; item[i][j - space]; j++)
				pItem[i][j] = item[i][j - space];
			for (; j < maxWidthItem; j++)
				pItem[i][j] = ' ';
			pItem[i][j] = '\0';
		}
	m.item = pItem;
}