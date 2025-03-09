#include <iostream>
#include <Windows.h>
#include "MyLib/console/console.h"
#include "MyLib/menu/menu.h"
#include "MyLib/git hub/git.h"
#include "MyLib/text/text.h"
#include "Pointer.h"
//Создает основное меню
Menu getMainMenu();
//Создает основное меню библиотеки
Menu getLibMenu();
/// <summary>
/// создаем меню поиска
/// </summary>
/// <param name="menu">необходимо, для определения координат от родителя</param>
/// <param name="numPer">номер строки родителя элемента меню</param>
/// <returns></returns>
Menu getSearchMenu(Menu menu, int numPer);
/// <summary>
/// Создаем меню сортировки
/// </summary>
/// <param name="menu">необходимо, для определения координат от родителя</param>
/// <param name="numPer">номер строки родителя элемента меню</param>
/// <returns></returns>
Menu getSortMenu(Menu menu, int numPer);
/// <summary>
/// Формирует начальный архив книг
/// </summary>
/// <param name="count">Количество книг, которые получились</param>
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
	gitPush("Первая задача готова  ДЗ № 24");
	//Добавляем первоначальные книги
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
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Домашняя работа № 24";
	const char* item[] = {
		"структура книг динамическая",
		"структура книг: двунаправленный список",
		"Выход",
	};
	const char* textInfo[] = {
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте динамический массив для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор, издательство, жанр). Создайте двунаправленный список для хранения книг. Реализуйте для него следующие возможности:\n• Добавить книгу\n• Удалить книгу\n• Редактировать книгу\n• Печать всех книг\n• Поиск книг по автору\n• Поиск книги по названию\n• Сортировка массива по названию книг\n• Сортировка массива по автору\n• Сортировка массива по издательству",
		"Выход",
	};
	Coordinate startMenu = { cSize.x / 2 - 19,  cSize.y / 3};///cSize.y/3
	int countMenu = sizeof(item) / sizeof(item[0]);
	menuColor colorMenu = { c.BlueBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'c', true);

	//Формируем шапку меню
	menuColor colorHead = { c.RedBG,c.BlackFG, c.YellowFG };
	Coordinate startHead = { 1,1 };
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent,0,indent + 1 };//{top, left, down, right}
	

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

Menu getLibMenu() {
	
	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"Печать всех книг",
		"Добавить книгу",
		"Удалить книгу",
		"<- Редактировать книгу",
		"<- Поиск книг",
		"<- Сортировка",
		"Назад"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	Coordinate startMenu = { cSize.x - mWidth,  4};
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };
	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);

	//Формируем шапку меню
	menuColor colorHead = { c.CyanBG,c.BlackFG, c.MagentaFG };
	Coordinate startHead = { 1,1 };//Координаты начала рисования названия меню
	int s = strlen(headMenu) / 2;
	int indent = (cSize.x / 2) - s - 2;
	int marginHead[] = { 0,indent+1,0,indent };//{top, left, down, right}
	addHeadMenu(m, startHead, headMenu, marginHead, true, colorHead);
	return m;
}

Menu getSearchMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"По названию",
		"По автору",
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	//Пока указываем произвольное значение начала меню
	//Потом определим куда его ставить
	Coordinate startMenu; 
	//ставим координаты меню относительно родителя
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));
	
	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

Menu getSortMenu(Menu menu, int numPer) {

	ColorANSI3b c;
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"По названию",
		"По автору",
		"По издательству"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	//Пока указываем произвольное значение начала меню
	//Потом определим куда его ставить
	Coordinate startMenu;
	//ставим координаты меню относительно родителя
	startMenu.y = 4 + (numPer * (menu.lineSkip + 1));

	menuColor colorMenu = { c.CyanBG,c.WhiteFG,c.MagentaFG,c.BlackFG, c.RedBG };

	Menu m;
	constructMenu(m, startMenu, item, countMenu, colorMenu, 1, 'r', true);
	m.start.x = menu.start.x - m.width;

	return m;
}

char*** createPointer(int & count) {
	//подготавливаем 5 начальных книг
	char little_prince[][100] = {
	   "Маленький принц",       //Название
	   "Антуан де Сент-Экзюпери", //Автор
	   "Reynal & Hitchcock",     //Издательство
	   "Сказка"      //Жанр
	};

	char ulyss[][100] = {
		"Улисс",                  
		"Джеймс Джойс",           
		"Shakespeare and Company", 
		"Модернистский роман"     
	};

	char atlas_shrugged[][100] = {
		"Атлант расправил плечи", 
		"Айн Рэнд",               
		"Random House",           
		"Философский роман, антиутопия" 
	};

	char shadow_of_the_wind[][100] = {
		"Тень ветра",             
		"Карлос Руис Сафон",      
		"Planeta",               
		"Мистический роман" 
	};

	char hunger_games[][100] = {
		"Голодные игры",         
		"Сьюзен Коллинз",        
		"Scholastic",            
		"Научная фантастика, антиутопия"
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
	Coordinate cSize = getConsoleSize(); //Максимальный размер консоли
	//Формируем элементы меню
	char headMenu[] = "Динамический массив хранения книг";
	const char* item[] = {
		"Название",
		"Автор",
		"Издательство",
		"Жанр"
	};
	int countMenu = sizeof(item) / sizeof(item[0]);
	int mWidth = strMaxLen(item, countMenu) + 4; //Ширина меню
	//Пока указываем произвольное значение начала меню
	//Потом определим куда его ставить
	Coordinate startMenu;
	//ставим координаты меню относительно родителя
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
		if (mLib.n == 4) {//Поиск книг
			int iSearch = getShowMenu(mSearch);
			setCursorPosition(0, 5);
			std::cout << "Введите поиск: ";
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
				std::cout << "Не найдено совпадений \n";
				system("pause");
				drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			}
			setCursorPosition(0, 5);
			system("pause");
			drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			drawEmptyRectangle(0, 8, (count + 2) * 3, cSize.x - 27, 0);
			showBook(books, count);
		}
		else if (mLib.n == 5)//Сортировка книг
		{
			int iSort = getShowMenu(mSort);
			sortBooks(books, count, iSort);
			showBook(books, count);
		}
			
		else if (mLib.n == 3) {//Редактировать книгу
			int iChange = getShowArrows(count);
			if (iChange < -1) continue;
			int whatChange = getShowMenu(mEdit);
			setCursorPosition(0, 5);
			std::cout << "Введите изменение: ";
			const int limitSymbol = 4 * 1024;
			char str[limitSymbol];
			std::cin.getline(str, limitSymbol);
			drawEmptyRectangle(0, 4, 4, mLib.start.x - 1, 0);
			editBook(books, count, iChange, whatChange, str);
			showBook(books, count);
		}
		else if (mLib.n == 2) {//Удалить  книгу
			showBook(books, count);
			int iDel = getShowArrows(count);
			if (iDel > -1)
				delBook(books, count, iDel);
			showBook(books, count);
		}
		else if (mLib.n == 0) {//Печать всех книг
			showBook(books, count);
		}
		else if (mLib.n == 1) { //Добавить книгу
			char** newB = new char* [4];
			ColorANSI3b c;
			const int limitSymbol = 4 * 1024;
			char str[limitSymbol];
			setCursorPosition(0, 4);
			std::cout << " Название: ";
			std::cin.getline(str, limitSymbol);
			newB[0] = new char[strlen(str) + 1];
			strcpy_s(newB[0], strlen(str) + 1, str);
			setColor(c.RedFG);
			std::cout << " автор: ";
			std::cin.getline(str, limitSymbol);
			newB[1] = new char[strlen(str) + 1];
			strcpy_s(newB[1], strlen(str) + 1, str);
			setColor(c.BlueFG);
			std::cout << " издательство: ";
			std::cin.getline(str, limitSymbol);
			newB[2] = new char[strlen(str) + 1];
			strcpy_s(newB[2], strlen(str) + 1, str);
			setColor(c.GreenFG);
			std::cout << " жанр: ";
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
		else if (mLib.n == 6) { //Назад
			clsHead(mLib);
			clsMenu(mLib);
			system("cls");
			break;
		}
	}
}