#include <iostream>
#include "Header.h"


void startMenu() {
	FullScreenMode();
	Menu menu;
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
			
			if (menu.n == menu.numTasks - 1)break;
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

void clearMenu(Menu &m) {
	for (int i = 0; i < m.numTasks; i++) {
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

void constructMenu(Menu &m) {
	/*Изменяемые поля*/
	m.numTasks = 8;//8й элемент выход
	char h[] = "Домашняя работа № 19";
	char t[] = "Тема: Ссылки. Указатели.";
	const char* tasks[] = {
		"Используя два указателя на массив целых чисел, скопировать один массив в другой. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.",
		"Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.",
		"Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы во втором массиве элементы находились в обратном порядке. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.",
		"Используя указатели и оператор разыменования, определить наибольшее из двух чисел.",
		"Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.",
		"Используя указатели и оператор разыменования, обменять местами значения двух переменных.",
		"Используя указатель на массив целых чисел, посчитать сумму элементов массива. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.",
		" "
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

	m.tNames = new char* [m.numTasks];
	m.textTasks = new char* [m.numTasks];
	for (int i = 0; i < m.numTasks; i++) {
		m.textTasks[i] = new char[getCharLen(tasks[i]) + 1];
		copyStr(m.textTasks[i], tasks[i]);
		if (i + 1 == m.numTasks) continue;
		char* numStr = intToStr(i + 1);
		m.tNames[i] = getGlueTogether(el, numStr);
		delete[] numStr;
	}	

	m.tNames[m.numTasks-1] = new char[getCharLen("Выход")+1];
	copyStr(m.tNames[m.numTasks-1], "Выход");
	
}

Coordinate setCoordinate(int x, int y) {
	Coordinate result;
	result.x = x;
	result.y = y;
	return result;
}

void showItemMenu(Menu m) {
	ColorANSI3b color;
	setCursorPosition(3, 7);
	for (int i = 0; i < m.numTasks; i++) {
		if (m.n == i) setColor(color.WhiteBG, color.BlackFG);
		std::cout << "\n\n   " << m.tNames[i] << "  ";
		if (m.n == i) resetColor();
	}
	showTextMenu(m);
	return;
}

void showTextMenu(Menu &m) {
	ColorANSI3b color;
	drawEmptyRectangle(16, 9, 10, m.cS.x - 17);
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

void showMenu(const Menu m) {
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

void changeItemMenu(Menu &m, char direction) {
	if (direction == 'w') 
		(m.n - 1 == -1) ? m.n = m.numTasks - 1 : m.n -= 1;
	else if (direction == 's')
		(m.n + 1 == m.numTasks) ? m.n = 0 : m.n += 1;
	showItemMenu(m);
}


void endTask(Menu& m) {
	setCursorPosition(m.startPos.x, ++m.startPos.y);
	system("pause");
	showItemMenu(m);
}
void nextLine(Coordinate &xy, int howeMach) {
	xy.y += howeMach;
	setCursorPosition(xy);
}

