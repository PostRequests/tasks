#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"

//Создает основное меню
Menu getMainMenu();


int main()
{
	system("chcp 1251>null");
	gitPush("Рефакторинг меню");
	Menu m = getMainMenu();
	
	getShowMenu(m, false);
	clsMenu(m);
	clsInfo(m);
	setCursorPosition(0, 0);
	clearMenu(m);
}



Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Домашняя работа № 24";
	const char* item[] = {
		"Задача 1",
		"Задача 2",
		"Выход",
	};
	const char* textInfo[] = {
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте динамический массив для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте двунаправленный список для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Выход",
	};
	Coordinate startMenu = { 1,  cSize.y / 3 };///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);

	//Формируем шапку меню
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent };//{top, left, down, right}
	

	//Формируем информацию об элементах меню
	Coordinate start{ 1, cSize.y - 12 };
	Coordinate finish{ cSize.x - 2, cSize.y };
	menuColor colorInfo{ c.BlackBG, c.WhiteFG, c.YellowFG };
	int sInfo = sizeof(textInfo) / sizeof(textInfo[0]);

	if (countMenu != sInfo) {
		std::cout << "Возникла ошибка, не совпадение количества элементов" << std::endl;
		abort();
		//Остановка программы в случае, если элементы меню не равны количеству элементов описания
	}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	addInfoMenu(m, start, finish, textInfo, true, colorInfo);
	return m;
}

