#include "Pointer.h"
#include "MyLib/console/console.h"
#include <iostream>


void addBook(char***& books, int& count, char** b) {
	char*** newBook = new char** [count + 1]; //Количество книг
	for (int i = 0; i < count + 1; i++)
		newBook[i] = new char* [4]; //В каждой книге 4 элемента

	if (books) {//Переносим все элементы в новый указатель
		for (int i = 0; i < count; i++)
			for (int j = 0; j < 4; j++) //В каждой книге 4 элемента
			{
				newBook[i][j] = new char[strlen(books[i][j]) + 1];
				strcpy_s(newBook[i][j], strlen(books[i][j]) + 1, books[i][j]);
			}

		for (int i = 0; i < count; i++) {//Удаляем старые значения
			for (int j = 0; j < 4; j++) //В каждой книге 4 элемента
				books[i][j];
			delete[] books[i];
		}
		delete books;
		books = nullptr;
	}

	for (int i = 0; i < 4; i++)
	{
		newBook[count][i] = new char[strlen(b[i]) + 1];
		strcpy_s(newBook[count][i], strlen(b[i]) + 1, b[i]);
	}
	count++;
	books = newBook;
}

void addBook(char***& books, int& count, char b[][100]) {
	char** temp = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		int len = strlen(b[i]) + 1;
		temp[i] = new char[len];
		strcpy_s(temp[i], len, b[i]);
	}
	addBook(books, count, temp);
	for (int i = 0; i < 4; i++)
	{
		delete[] temp[i];
	}
	delete[] temp;
}
void showBook(char*** books, int count, int number) {
	
	ColorANSI3b c;
	std::cout << "\t" << books[number][0];
	setColor(c.RedFG);
	std::cout << "\n\t Автор: ";
	resetColor();
	std::cout << books[number][1];
	setColor(c.BlueFG);
	std::cout << " Издательство: ";
	resetColor();
	std::cout << books[number][2];
	setColor(c.GreenFG);
	std::cout << " Жанр: ";
	resetColor();
	std::cout << books[number][3] << std::endl;
	std::cout << "\t----------------------------------------------\n";
}
void showBook(char*** books, int count) {
	Coordinate cSize = getConsoleSize();
	drawEmptyRectangle(0, 8, (count + 1) * 3, cSize.x - 27, 0);
	setCursorPosition(0, 8);
	for (int i = 0; i < count; i++)
		showBook(books, count, i);
}

void delBook(char*** &book, int& count, int number) {
	if (!book) return;
	for (int j = 0; j < 4; j++) {
		delete[] book[number][j];
	}
	delete[] book[number];

	for (int i = number; i < count - 1; i++) {
		book[i] = book[i + 1];
	}
	count--;
}
void editBook(char *** &book, int count, int numBook, int numIndex, char* textedit) {
	if (!count or numIndex > count) return;

	strcpy_s(book[numBook][numIndex], strlen(textedit) + 1, textedit);
}