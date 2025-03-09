#include "Pointer.h"
#include "MyLib/console/console.h"
#include "MyLib/text/text.h"
#include <iostream>


void addBook(char***& books, int& count, char** b) {
	char*** newBook = new char** [count + 1]; //���������� ����
	for (int i = 0; i < count + 1; i++)
		newBook[i] = new char* [4]; //� ������ ����� 4 ��������

	if (books) {//��������� ��� �������� � ����� ���������
		for (int i = 0; i < count; i++)
			for (int j = 0; j < 4; j++) //� ������ ����� 4 ��������
			{
				newBook[i][j] = new char[strlen(books[i][j]) + 1];
				strcpy_s(newBook[i][j], strlen(books[i][j]) + 1, books[i][j]);
			}

		for (int i = 0; i < count; i++) {//������� ������ ��������
			for (int j = 0; j < 4; j++) //� ������ ����� 4 ��������
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
	std::cout << "\n\t �����: ";
	resetColor();
	std::cout << books[number][1];
	setColor(c.BlueFG);
	std::cout << " ������������: ";
	resetColor();
	std::cout << books[number][2];
	setColor(c.GreenFG);
	std::cout << " ����: ";
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
bool textMatch(const char* text1, const char* text2) {
	for (int i = 0; i < strlen(text1); i++)
		if (toLowerRus(text1[i]) != toLowerRus(text2[i])) return false;
	return true;
}
int searchBook(char*** books, int count, int numIndex, char* what) {
	for (int i = 0; i < count; i++)
	{
		char* item = books[i][0];
		if (textMatch(what, books[i][numIndex])) return i;
	}
	return -1;
}
void sortBooks(char*** books, int count, int sortIndex) {
	for (int k = 0; k < count - 1; k++)
	{
		bool sort = true;
		for (int i = 0; i < count - 1; i++)
		{
			int temp1 = strlen(books[i][sortIndex]);//������ ������
			int temp2 = strlen(books[i + 1][sortIndex]);//������ ��������� ������
			int min = ((temp1 > temp2) ? temp2 : temp1);//����������� ������ ������

			for (int j = 0; j < min; j++)
			{
				if (books[i][sortIndex][j] == books[i + 1][sortIndex][j]) 
					continue;//���� ������� �����, ��������� � ����������
				else if (books[i][sortIndex][j] * -1  < books[i + 1][sortIndex][j] * -1) {//���� ������ � ������ ������ ��� � �����������
					
					std::swap(books[i], books[i + 1]);//������ ������� �����
					sort = false;
					break;
				}
				break;
			}
		}
		if (sort) {
			break;
		}
	
	}
}