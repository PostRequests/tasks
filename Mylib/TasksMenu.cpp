#include <iostream>
#include "Header.h"
#ifdef max
#undef max
#endif

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
				case 7:	task8(menu); break;
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
	m.countMenu = 9;//8й элемент выход
	char h[] = "Домашняя работа № 21";
	char t[] = "Тема: Строки.";
	const char* tasks[] = {
		"Написать функцию, которая удаляет из строки символ с заданным номером.",
		"Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.",
		"Написать функцию, которая вставляет в строку в указанную позицию заданный символ.",
		"Написать программу, которая заменяет все символы точки \".\" в строке, введенной пользователем, на символы восклицательного знака \"!\".",
		"Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.",
		"Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.",
		"Подсчитать количество слов во введенном предложении.",
		"Дана строка символов. Необходимо проверить является ли эта строка палиндромом.",
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
	drawEmptyRectangle(16, 9, m.startPos.y, m.cS.x - 17);
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
void showWrappedText(TaskStructure& m, char* text) {
	int maxLineLength = m.cS.x - 30; // Максимальная длина строки
	int lineBreaks = 0; //Количество переносов строки
	int currentLineLength = 5;// Количество уже использованных символов в текущей строке
	Coordinate& s = m.startPos; //Стартовые координаты печати текста
	setCursorPosition(s.x, s.y);
	while (*text)
	{
		int len = getLengthNextWord(text);
		currentLineLength += len;

		if (currentLineLength < maxLineLength) {
			for (int i = 0; i < len; i++)
				if (*text == '\n') {
					lineBreaks++;
					currentLineLength = 0;
					setCursorPosition(s.x, s.y + lineBreaks);
					text++;
				}
				else
					std::cout << *text++;
			while (*text == ' ') {
				currentLineLength++;
				std::cout << *text++;
			}
		}
		else {
			lineBreaks++;
			currentLineLength = 0;
			setCursorPosition(s.x, s.y + lineBreaks);
		}
	}
	lineBreaks++;
	m.startPos = { s.x, s.y + lineBreaks };
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
	//std::cout << "Для продолжения нажмите любую клавишу . . .";
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Сбрасываем буфер потока, иначе в цикле не даст повторно ввести symbol
	showItemMenu(m);
}
void nextLine(Coordinate &xy, int howeMach) {
	xy.y += howeMach;
	setCursorPosition(xy);
}

