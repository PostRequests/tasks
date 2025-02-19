#pragma once
#include <iostream>
#include "Print.h"
#include "Random.h"
#include "Matrix.h"
#include "Struct.h"

/*Helper*/

/// <summary>
/// ������� ����� ����� � ������ ������
/// </summary>
/// <returns>���������� true � ������ ������� ������, false ���� ������ ���</returns>
bool clearCinOnError();
/// <summary>
/// ������� ����������� � ������������ ���� ������ ����� � ��������� ��� �� ������������.
/// </summary>
/// <param name="p">���������, ������� ����� �������� ������������ ��� ������� �����.</param>
/// <returns>���������� ��������� ��������� ����� �����.</returns>
int getValidInt(const char p[]);

/*Calc*/

/// <summary>
/// ���� ������������ �������� �� ���� �����
/// </summary>
/// <param name="a">������ �����</param>
/// <param name="b">������ �����</param>
/// <returns>���������� ��������� �� ������� �����</returns>
int* findMax(int* a, int* b);
/// <summary>
/// ���� ����������� �������� �� ���� �����
/// </summary>
/// <param name="a">������ �����</param>
/// <param name="b">������ �����</param>
/// <returns>���������� ��������� �� ������� �����</returns>
int* findMin(int* a, int* b);
/// <summary>
/// ���������� ��������� ����� ���� ����� ����� � �������� ��������� [a, b].
/// </summary>
/// <param name="a">������ ����� ���������</param>
/// <param name="b">������ ����� ���������</param>
/// <returns>����� ���� ����� � ��������� �� a �� b ������������</returns>
int calculateRangeSum(int a, int b);
/// <summary>
/// ���������� � �������
/// </summary>
/// <param name="d">��������� �������</param>
/// <param name="e">���������� �������</param>
/// <returns>��������� ������� ���������� ������� �����</returns>
int getPower(int d, int e);
/// <summary>
/// ���������� ��������� ����� ��������� �������
/// </summary>
/// <param name="arr">�������� ������</param>
/// <param name="size">������ �������</param>
/// <param name="i">��������� ������ ���������</param>
/// <param name="j">�������� ������ ���������</param>
/// <returns>C���� ��������� ������� � ��������� ��������� ��������</returns>
int getSumRangeArr(int arr[], int size, int i, int j);
/// <summary>
/// ���������� ���������� �������� � ������ int
/// </summary>
/// <param name="n">��������������� �����</param>
/// <returns>���������� �������� ��� ������ ����� � �������</returns>
int getNumLength(int n);
/// <summary>
/// �������� � orig ������ copy ������
/// </summary>
/// <param name="orig">��������� �� ������ int, � ������� ����� ����������� ������</param>
/// <param name="copy">��������� �� ������ int, � ������� ����� ����������� ������</param>
/// <param name="sOrig">������ orig ������� (���������� ���������, ������� ����� �����������)</param>
void copyNumArr(int* orig, int* copy, int sOrig);
/// <summary>
/// ������� ��������� ���������� �� ������ ������������ ������ �� ���������
/// </summary>
/// <param name="a">��������� �� ������ ������� �������</param>
/// <param name="size">������ �������</param>
void show(int* a, int size);
/// <summary>
/// ������� ��������� ������������� �������� ������
/// </summary>
/// <param name="arr">��������� �� ������ ������� �������</param>
/// <param name="size">������ �������</param>
void reverseNumArr(int* arr, int size);
/// <summary>
/// �������� �������������� �������� �������������� �������
/// </summary>
/// <param name="arr">��������� �� ������� � ������� ��������</param>
/// <param name="arr2">��������� �� ���������� �������</param>
/// <param name="size">������ �������(������� ������ ���������)</param>
void copyReverseNumArr(int* copy, int* orig, int size);

/*Print*/

/// <summary>
/// ������� �������� ������� � �������
/// </summary>
/// <typeparam name="T">��� �������</typeparam>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������, ������� ���������� �������</param>
template<typename T, size_t N> void show(T(&a)[N]);
template<typename T, size_t N>void show(T(&a)[N], int s, int e);
template<typename T, size_t N, size_t M>
/// <summary>
/// ������� �������� ������� � �������
/// </summary>
/// <typeparam name="T">��� �������</typeparam>
/// <typeparam name="N">������ ������� �����</typeparam>
/// <typeparam name="M">������ ������� �������</typeparam>
/// <param name="a">������ �� ������, ������� ���������� �������</param>
void show(T(&a)[N][M]);

/*Random*/

/// <summary>
/// ��������� ������ ���������� ���������� � �������� ��������� [s, e]
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� ���������</param>
/// <param name="s">������ ������� ��������� ��������� ����� (������������)</param>
/// <param name="e">������� ������� ��������� ��������� ����� (������������)</param>
template<size_t N>void randArr(char(&arr)[N], char s, char e);
/// ��������� ������ ���������� ���������� � �������� ��������� [s, e]
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� ���������</param>
/// <param name="s">������ ������� ��������� ��������� ����� (������������)</param>
/// <param name="e">������� ������� ��������� ��������� ����� (������������)</param>
template<typename T, size_t N>void randArr(T(&a)[N], T s, T e);
/// ��������� ��������� ������ ���������� ���������� � �������� ��������� [s, e]
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� ���������</param>
/// <param name="s">������ ������� ��������� ��������� ����� (������������)</param>
/// <param name="e">������� ������� ��������� ��������� ����� (������������)</param>
template<typename T, size_t N, size_t M>void randArr(T(&a)[N][M], T s, T e);

/*Matrix*/

/// <summary>
/// ���������� ����������� ������� � �������
/// </summary>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <returns>����������� ������� ����� � �������</returns>
template<typename T, size_t N>T getMin(T(&a)[N]);
/// <summary>
/// ���������� ����������� ������� � ��������� �������
/// </summary>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <returns>����������� ������� ����� � �������</returns>
template<typename T, size_t N, size_t M>T getMin(T(&a)[N][M]);
/// <summary>
/// ���������� ������������ ������� � �������
/// </summary>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <returns>����������� ������� ����� � �������</returns>
template<typename T, size_t N>T getMax(T(&a)[N]);
/// <summary>
/// ���������� ������������ ������� � ��������� �������
/// </summary>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <returns>����������� ������� ����� � �������</returns>
template<typename T, size_t N, size_t M>T getMax(T(&a)[N][M]);
/// <summary>
/// ������ ���������� ������� ������� ��������
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� �������������</param>
template<typename T, size_t N>void sortStone(T (&a)[N]);
/// <summary>
/// ������ ���������� ������� ������� �������
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� �������������</param>
template <typename T, size_t N>void sortInsert(T(&a)[N]);
/// <summary>
/// ������ ���������� ���������� ������� ������� �������
/// </summary>
/// <typeparam name="T">��� ��������� �������</typeparam>
/// <typeparam name="N">������ ������� (������������ �������������)</typeparam>
/// <param name="a">������ �� ������, ������� ����� �������������</param>
template <typename T, size_t N, size_t M>void sortInsert(T(&a)[N][M]);


/*Text*/

/// <summary>
/// ���������� ����� ������
/// </summary>
/// <param name="t">��������� �� ������ ������� �������������� ������</param>
/// <returns>���������� ����� ������</returns>
int getCharLen(char* t);
/// <summary>
/// ���������� ����� ������
/// </summary>
/// <param name="t">��������� �� ������ ������� �������������� ������</param>
/// <returns>���������� ����� ������</returns>
int getCharLen(const char* t);
/// <summary>
/// ��������� ������ ������
/// </summary>
/// <param name="a">��������� �� ������ ������ ������</param>
/// <param name="b">��������� �� ������ ������ ������</param>
/// <returns>����� ��������� �� ����� ������ �� ��������� 2� �����</returns>
char* getGlueTogether(char* a, char* b);
/// <summary>
/// ��������� ����� � ������
/// </summary>
/// <param name="num">����� ������� ����� ���������� � ������</param>
/// <returns>��������� �� ������ ���������� �� �����</returns>
char* intToStr(int num);
/// <summary>
/// ��������� ���������� ������ �� ����� ������ � ������
/// </summary>
/// <param name="a">��������� �� ������ �����</param>
/// <param name="b">��������� �� ������ ��������</param>
void copyStr(char* copy, char* orig);
/// <summary>
/// ��������� ���������� ������ �� ����� ������ � ������
/// </summary>
/// <param name="a">��������� �� ������ �����</param>
/// <param name="b">��������� �� ������ ��������</param>
void copyStr(char* copy, const char* orig);
/// <summary>
/// ��������� ����� ���������� ����� �� ������� ��� �� ����� ������
/// </summary>
/// <param name="t">��������� �� ��������� ����� ������ �����</param>
/// <returns>���������� ���������� �������� � ��������� �����</returns>
int getLengthNextWord(char* t);

/*Win*/

/// <summary>������������ ������� ������� �� ������� � ���������� ������� ��� </summary>
/// <param name="key">������ ������� � ����� ��������������</param>
/// <returns>������������ ������ �������� �==�==W==(w) ���������� w</returns>
char convertKey(char key);
/// <summary> ������������� ������ � ������ ������� </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void setCursorPosition(int x, int y);
/// <summary>
/// ������������� ������ � ������ �������
/// </summary>
/// <param name="xy">��������� ��������� ������� xy.x xy.y</param>
void setCursorPosition(Coordinate xy);
/// <summary>
/// ���������� � ����� ������� ������ ���������� ������
/// </summary>
/// <returns>���������� ��������� ��������� Coordinate.x Coordinate.y</returns>
Coordinate getCursorPosition();
/// <summary>
/// ���������� ������� ������ ������ � ��������
/// </summary>
/// <returns>���������� ��������� ��������� ������������ ����� Coordinate.x/y</returns>
Coordinate getConsoleSize();
/// <summary>
/// ���������� ������� � ������ �����
/// </summary>
void FullScreenMode();
/// <returns>���������� ������� ������</returns>
char catchKey();

/*Draw*/

/// <summary>
/// ������ �������������� �����
/// </summary>
/// <param name="c">���������� ������</param>
/// <param name="e">������ �����</param>
/// <param name="s">���������� ��������� �����</param>
void drawVerticalLine(Coordinate c, char e, int s);
/// <summary>
/// ������������� 1 ���� �������
/// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
/// </summary>
/// <param name="color">����</param>
void setColor(int color);
/// <summary>
/// ������������� 2 ����� �������, ��� ���� � ��� �������
/// </summary>
/// <param name="color1">����1</param>
/// <param name="color2">����2</param>
void setColor(int color1, int color2);
/// <summary>/// ���������� ��� ����� ������� �� �����������/// </summary>
void resetColor();
/// <summary>
/// �������� �����
/// </summary>
/// <param name="s">������ �����</param>
/// <param name="symbol">������� ����������</param>
/// <param name="color1">���� ������� ANSI</param>
/// <param name="color2">���� ������� ANSI</param>
void printRowChars(int s, char symbol, int color1 = 0, int color2 = 0);
/// <summary>
/// �������� �����
/// </summary>
/// <param name="s">������ �����</param>
/// <param name="l">������ ������ � �����</param>
/// <param name="c">������ ������� ����� ��������� ����� �����</param>
/// <param name="r">��������� ������ �����</param>
/// <param name="color1">���� ������� ANSI (�� ������������ ��������)</param>
/// <param name="color2">���� ������� ANSI (�� ������������ ��������)</param>
void printRowChars(int s, char l, char c, char r, int color1 = 0, int color2 = 0);
/// <summary>
/// �����������/������� ������� ������������� 
/// </summary>
/// <param name="posX">������� ������</param>
/// <param name="posY">������� �������</param>
/// <param name="rows">���������� ������������� �����</param>
/// <param name="cols">���������� ������������� �������</param>
/// <param name="color">�������� ����� (��������� ������ ������ ���)</param>
void drawEmptyRectangle(int posX, int posY, int rows, int cols, int color = 0);
/// <summary>
/// �������� 2������ ������ �� �����������, ����� ������������ 2 �����
/// </summary>
/// <param name="arr">��������� �� 2������ ������</param>
/// <param name="posX">������� ������</param>
/// <param name="posY">������� �������</param>
/// <param name="rows">����������� ������� � �������</param>
/// <param name="cols">����������� ������� � ��������</param>
/// <param name="color1">���� 1 (�� ������������ ��������)</param>
/// <param name="color2">���� 2 (�� ������������ ��������)</param>
void drawArr(char* arr, int posX, int posY, int rows, int cols, int color1 = 0, int color2 = 0);

/*Win*/

/// <summary> ������������� ������ � ������ ������� </summary>
/// <param name="x"> - ����������</param>
/// <param name="y">- ����������</param>
void setCursorPosition(int x, int y);
/// <summary>
/// ������������� ������ � ������ �������
/// </summary>
/// <param name="xy">��������� ��������� ������� xy.x xy.y</param>
void setCursorPosition(Coordinate xy);
/// <summary>
/// ���������� � ����� ������� ������ ���������� ������
/// </summary>
/// <returns>���������� ��������� ��������� Coordinate.x Coordinate.y</returns>
Coordinate getCursorPosition();
/// <summary>
/// ���������� ������� ������ ������ � ��������
/// </summary>
/// <returns>���������� ��������� ��������� ������������ ����� Coordinate.x/y</returns>
Coordinate getConsoleSize();
/// <summary>
/// ���������� ������� � ������ �����
/// </summary>
void FullScreenMode();
/// <returns>���������� ������� ������</returns>
char catchKey();

/*Task Menu*/

/// <summary>
/// ������� ��� ��������� � ����
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(Menu& m);
/// <summary>
/// ��������������� ������� ������������� ������ � ����
/// </summary>
void startMenu();
/// <summary>
/// ������ �������������� ������ � �������
/// </summary>
/// <param name="m">��������� ����</param>
void constructMenu(Menu& m);
/// <summary>
/// ��������� ���������� ���������� ��� ��������� ���������
/// </summary>
/// <param name="x">���������� �� �</param>
/// <param name="y">���������� �� y</param>
/// <returns>���������� � ����������� x � y</returns>
Coordinate setCoordinate(int x, int y);
/// <summary>
/// �������� �������� ���� �� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showItemMenu(Menu m);
/// <summary>
/// ������� ������
/// </summary>
/// <param name="xy">���������� �� ������� ���������� �����</param>
/// <param name="howeMach">�� ������� ������� ���� �������</param>
void nextLine(Coordinate& xy, int howeMach = 1);
/// <summary>
/// ���������� ��������� task
/// </summary>
/// <param name="m"></param>
void endTask(Menu& m);
/// <summary>
/// ������ �� ������ ������� ��� �������� ����
/// </summary>
/// <param name="m">��������� ����</param>
void showMenu(const Menu m);
/// <summary>
/// �������, ����������� ������� �1
/// </summary>
void task1(Menu);
/// <summary>
/// �������, ����������� ������� �2
/// </summary>
void task2(Menu);
/// <summary>
/// �������, ����������� ������� �3
/// </summary>
void task3(Menu);
/// <summary>
/// �������, ����������� ������� �4
/// </summary>
void task4(Menu);
/// <summary>
/// �������, ����������� ������� �5
/// </summary>
void task5(Menu);
/// <summary>
/// �������, ����������� ������� �6
/// </summary>
void task6(Menu);
/// <summary>
/// �������, ����������� ������� �7
/// </summary>
void task7(Menu);
/// <summary>
/// �������� ����� �������� �������� ���� � �������������� ���
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="direction">����������� w - �����, s - ����</param>
void changeItemMenu(Menu &m, char direction);
/// <summary>
/// �������� ����� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showTextMenu(Menu &m);
