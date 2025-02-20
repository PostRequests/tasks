#include <iostream>
#include "Header.h"


void startMenu() {
	FullScreenMode();
	TaskStructure menu;
	constructMenu(menu);
	showMenu(menu);
	

	while (true)
	{
		char key = catchKey();
		if (key == 'w' or key == 's') {
			if (menu.cS.x == getConsoleSize().x)
				changeItemMenu(menu, key);
			else {
				menu.cS = getConsoleSize();
				showMenu(menu);
			}
		}
		else if (key == 13 )
			
			if (menu.n == menu.countMenu - 1)break;
			else {
				drawEmptyRectangle(16, 9, menu.cS.y - 10, menu.cS.x -17);
				resetColor();
				switch (menu.n)
				{
				case 0:	task1(menu); break;
				case 1:	task2(menu); break;
				case 2:	task3(menu); break;
				case 3:	task4(menu); break;
				case 4:	task5(menu); break;
				case 5:	task6(menu); break;
				case 6:	task7(menu); break;
				default:break;
				}
			}
				
			
	}

	clearMenu(menu);
}

void clearMenu(TaskStructure &m) {
	for (int i = 0; i < m.countMenu; i++) {
		delete[] m.tNames[i];
		delete[] m.textTasks[i];
	}
	delete[] m.tNames;
	m.tNames = nullptr;
			
	delete[] m.textTasks;
	m.textTasks = nullptr;
	
	delete[] m.head;
	delete[] m.theme;
	m.tNames = nullptr;
	m.head = nullptr;
	m.theme = nullptr;
}
void clearMenu(Menu& m) {
	for (int i = 0; i < m.countMenu; i++) {
		delete[] m.elemMenu[i];
	}
	delete[] m.elemMenu;
	m.elemMenu = nullptr;
}
Menu constructMenu(Coordinate startPos, int countMenu, const char* elemMenu[], int n) {
	Menu m;
	m.startPos = startPos;//Координаты начала места печати меню
	m.countMenu = countMenu; //Количество элементов в меню

	m.elemMenu = new char*[countMenu];//Элементы меню
	for (int i = 0; i < countMenu; i++)
	{
		m.elemMenu[i] = new char[getCharLen(elemMenu[i]) + 1];
		copyStr(m.elemMenu[i], elemMenu[i]);
	}
	m.n = n; //Номер выбранного элемента меню
	return m;
}
void constructMenu(TaskStructure &m) {
	/*Изменяемые поля*/
	m.countMenu = 7;//8й элемент выход
	char h[] = "Домашняя работа № 20";
	char t[] = "Тема: Указатели.";
	const char* tasks[] = {
		"Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B, без повторений.",
		"Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массивов A и B, которые не являются общими для них, без повторений.",
		"Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.",
		"Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.",
		"Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.",
		"Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.",
		"Выход из программы"
	};
	/**/
	m.startPos = setCoordinate(17, 9);
	m.n = 0;
	m.cS = getConsoleSize();
	m.head = h;
	m.theme = t;
	char el[] = "Задание "; //Название элемента меню
	int lenEl = getCharLen(el) + 1;//Длинна строки элемента меню
	
	m.head = new char[getCharLen(h) + 1];
	m.theme = new char[getCharLen(t) + 1];
	copyStr(m.head, h);
	copyStr(m.theme, t);

	m.tNames = new char* [m.countMenu];
	m.textTasks = new char* [m.countMenu];
	for (int i = 0; i < m.countMenu; i++) {
		m.textTasks[i] = new char[getCharLen(tasks[i]) + 1];
		copyStr(m.textTasks[i], tasks[i]);
		if (i + 1 == m.countMenu) continue;
		char* numStr = intToStr(i + 1);
		m.tNames[i] = getGlueTogether(el, numStr);
		delete[] numStr;
	}	

	m.tNames[m.countMenu-1] = new char[getCharLen("Выход")+1];
	copyStr(m.tNames[m.countMenu-1], "Выход");
	
}

Coordinate setCoordinate(int x, int y) {
	Coordinate result;
	result.x = x;
	result.y = y;
	return result;
}

int scrollMenu(Menu m) {
	showItemMenu(m);
	while (true)
	{
		char key = catchKey();
		if (key == 's') {
			(m.n - 1 == -1) ? m.n = m.countMenu - 1 : m.n -= 1;
			showItemMenu(m);
		}
		else if (key == 'w') {
			(m.n + 1 == m.countMenu) ? m.n = 0 : m.n += 1;
			showItemMenu(m);
		}
		else if (key == 13) {
			return m.n;
		}
			
	}
}

void showItemMenu(TaskStructure m) {
	ColorANSI3b color;
	setCursorPosition(3, 7);
	for (int i = 0; i < m.countMenu; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		std::cout << "\n\n   " << m.tNames[i] << "  ";
		if (m.n == i) resetColor();
	}
	showTextMenu(m);
	return;
}
void showItemMenu(Menu m) {
	ColorANSI3b color;
	setCursorPosition(m.startPos);
	for (int i = 0; i < m.countMenu; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		setCursorPosition({ m.startPos.x,  ++m.startPos.y });
		std::cout  << m.elemMenu[i] << "  ";
		if (m.n == i) resetColor();
	}
	return;
}

void showTextMenu(TaskStructure &m) {
	ColorANSI3b color;
	drawEmptyRectangle(16, 9, 15, m.cS.x - 17);
	int maxLineLength = m.cS.x - 17; // Максимальная длина строки
	int lineBreaks = 0; //Количество переносов строки
	int currentLineLength = 5;// Количество уже использованных символов в текущей строке
	Coordinate s = setCoordinate(getCharLen(m.tNames[0]) + 7, 10); //Стартовые координаты печати текста
	char* pt = m.textTasks[m.n]; // Указатель на текст выбранного элемента меню
	setCursorPosition(s.x, s.y);
	std::cout << "     ";
	while (*pt)
	{
		int len = getLengthNextWord(pt);
		currentLineLength += len;
		if (currentLineLength < maxLineLength) {
			for (int i = 0; i < len; i++)
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
}

void showMenu(const TaskStructure m) {
	system("CLS");

	Coordinate cHead = setCoordinate(m.cS.x / 2 - (getCharLen(m.head) / 2), 2);
	Coordinate cTheme = setCoordinate(3, 5);
	ColorANSI3b color;

	drawEmptyRectangle(0, 0, 4, m.cS.x-1, color.RedBG);
	
	setCursorPosition(cHead);
	std::cout << m.head;
	resetColor();

	setCursorPosition(cTheme);
	setColor(color.BlueBG);
	std::cout << m.theme;
	resetColor();
	showItemMenu(m);
	BorderCP866 bord;
	drawVerticalLine(setCoordinate(getCharLen(m.tNames[0]) + 6, 9), bord.V2, m.cS.y - 10);
	drawVerticalLine(setCoordinate(m.cS.x - 1, 9), bord.V2, m.cS.y - 10);
	std::cout << '\n';
}

void changeItemMenu(TaskStructure &m, char direction) {
	if (direction == 'w') 
		(m.n - 1 == -1) ? m.n = m.countMenu - 1 : m.n -= 1;
	else if (direction == 's')
		(m.n + 1 == m.countMenu) ? m.n = 0 : m.n += 1;
	showItemMenu(m);
}


void endTask(TaskStructure& m) {
	setCursorPosition(m.startPos.x, ++m.startPos.y);
	system("pause");
	showItemMenu(m);
}
void nextLine(Coordinate &xy, int howeMach) {
	xy.y += howeMach;
	setCursorPosition(xy);
}

