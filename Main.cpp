#include <iostream>

#include "libraries/console/console.h"
#include "libraries/menu/menu.h"
#include "libraries/git hub/git.h"

//—оздает основное меню
Menu getMainMenu();


int main()
{
	system("chcp 1251>null");
	gitPush("меню готово но криво");
	Menu m = getMainMenu();
	
	getShowMenu(m, true);

	clearMenu(m);
}



Menu getMainMenu() {
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //ћаксимальный размер консоли
	//‘ормируем элементы меню
	char headMenu[] = "ƒомашн€€ работа є 24";
	const char* item[] = {
		"«адача 1",
		"«адача 2",
		"¬ыход",
	};
	const char* textInfo[] = {
		"–азработайте программу ЂЅиблиотекаї. —оздайте структуру Ђ нигаї (название, автор, издательство, жанр). —оздайте динамический массив дл€ хранени€ книг. –еализуйте дл€ него следующие возможности:\nХ ƒобавить книгу\nХ ”далить книгу\nХ –едактировать книгу\nХ ѕечать всех книг\nХ ѕоиск книг по автору\nХ ѕоиск книги по названию\nХ —ортировка массива по названию книг\nХ —ортировка массива по автору\nХ —ортировка массива по издательству",
		"–азработайте программу ЂЅиблиотекаї. —оздайте структуру Ђ нигаї (название, автор, издательство, жанр). —оздайте двунаправленный список дл€ хранени€ книг. –еализуйте дл€ него следующие возможности:\nХ ƒобавить книгу\nХ ”далить книгу\nХ –едактировать книгу\nХ ѕечать всех книг\nХ ѕоиск книг по автору\nХ ѕоиск книги по названию\nХ —ортировка массива по названию книг\nХ —ортировка массива по автору\nХ —ортировка массива по издательству",
		"¬ыход",
	};
	Coordinate startMenu = { 1,  4 };///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);
	//‘ормируем шапку меню
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };

	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent };
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);

	//‘ормируем информацию об элементах меню
	Coordinate start{ 1, cSize.y - 12 };
	Coordinate finish{ cSize.x - 2, cSize.y };
	menuColor colorInfo{ c.BlackBG, c.WhiteFG, c.YellowFG };
	int sInfo = sizeof(textInfo) / sizeof(textInfo[0]);
	if (countMenu != sInfo) {
		std::cout << "¬озникла ошибка, не совпадение количества элементов" << std::endl;
		abort();
		//ќстановка программы в случае, если элементы меню не равны количеству элементов описани€
	}
	addInfoMenu(m, start, finish, textInfo, true, colorInfo);
	return m;
}

