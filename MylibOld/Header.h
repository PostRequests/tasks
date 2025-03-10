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
/// <summary>
/// ���������� ���������� � git hub
/// </summary>
/// <param name="text">����� �����������</param>
void gitPush(const char* text);
/// <summary>
/// ������� ����������� � ������������ ���� ������ ����� � ��������� ��� �� ������������. 
/// </summary>
/// <param name="p">���������, ������� ����� �������� ������������ ��� ������� �����.</param>
/// <returns>���������� ��������� ��������� ����� �����.</returns>
/// /// <param name="m">��������� ����</param>
int getValidInt(TaskStructure &m, const char text[]);
/*Calc*/

/// <summary>
/// ������� ������� �� ���������� ������������� ������� �� ��������� �������.
/// </summary>
/// <param name="array">������ �� ��������� �� ��������� ������.</param>
/// <param name="rows">���������� ����� � �������.</param>
/// <param name="cols">���������� �������� � �������.</param>
/// <param name="delPos">������� �������, ������� ����� �������. </param>
void delColumn(int**& array, int rows, int& cols, int delPos);
/// <summary>
/// ��������� ������� � ��������� ������������ ������ �� ��������� �������.
/// </summary>
/// <param name="array">������ �� ��������� �� ��������� ������.</param>
/// <param name="rows">���������� ����� � �������. ������ ���� ������ 0.</param>
/// <param name="cols">���������� �������� � �������.</param>
/// <param name="insertPos">�������, �� ������� ����� �������� ����� �������.</param>
/// <param name="defaultValue">��������, ������� ����� �������� ����� �������. </param>
void addColumn(int**& array, int rows, int& cols, int insertPos, int defaultValue = 0);
/// <summary>
/// ������� ���������� �� ������� ��������� � �������
/// </summary>
/// <param name="arr">������ ������� �����������</param>
/// <param name="size">������ �������</param>
/// <returns>���������� ���������� ��������� �� ������� �����</returns>
int getCountNoPrime(int* arr, int size);
/// <summary>
/// ������� ���������� ������� ��������� � �������
/// </summary>
/// <param name="arr">������ ������� �����������</param>
/// <param name="size">������ �������</param>
/// <returns>���������� ���������� ��������� ������� �����</returns>
int getCountPrime(int* arr, int size);
/// <summary>
/// ��������� �������� �� ����� �������
/// </summary>
/// <param name="num">����������� �����</param>
/// <returns>���������� true ���� ����� �������</returns>
bool isPrime(int num);
/// <summary>
/// ������� ������� ����� �� �������
/// </summary>
/// <param name="arr">������ �</param>
/// <param name="size">������ ������� �</param>
void deletePrimeElement(int*& arr, int& size);
/// <summary>
/// ������� ������������� ����� �� �������
/// </summary>
/// <param name="arr">������ �</param>
/// <param name="size">������ ������� �</param>
void deletePositiveElement(int*& arr, int& size);
/// <summary>
/// ������� ������������� ����� �� �������
/// </summary>
/// <param name="arr">������ �</param>
/// <param name="size">������ ������� �</param>
void deleteNegativeElement(int* &arr, int& size);
/// <summary>
///������� ���������� ������������� �������� � �������
/// </summary>
/// <param name="arr">������ �</param>
/// <param name="size">������ ������� �</param>
/// <returns>���������� ���������� ������������� ��������� �������</returns>
int getPositiveCount(int* arr, int size);
/// <summary>
///������� ���������� ������������� �������� � �������
/// </summary>
/// <param name="arr">������ �</param>
/// <param name="size">������ ������� �</param>
/// <returns>���������� ���������� ������������� ��������� �������</returns>
int getNegativeCount(int* arr, int size);
/// <summary>
/// ���������� ��������� �� ������ � �������������� ���������� �� ���� �������� (�������������� ����� ���������� ���������� ������������� ���������)
/// </summary>
/// <param name="arr1">������ �</param>
/// <param name="size1">������ ������� �</param>
/// <param name="arr2">������ B</param>
/// <param name="size2">������ ������� B</param>
/// <param name="repeated">���������� ������������� ��������� �������</param>
/// <returns>���������� ��������� �� ������ � �������������� ���������� �� ���� ��������</returns>
int* getRepeatedElements(int* arr1, int size1, int* arr2, int size2, int repeated);
/// <summary>
/// ������� ���������� ������������� ��������� �� 2� ��������
/// </summary>
/// <param name="arr1">������ 1</param>
/// <param name="size1">����������� ������� 1</param>
/// <param name="arr2">������ 2</param>
/// <param name="size2">����������� ������� 2</param>
/// <returns>���������� ������������� ��������� � �������</returns>
int getRepeatedCount(int* arr1, int size1, int* arr2, int size2);
/// <summary>
/// ��������� ��� ������������� ������� � ����
/// </summary>
/// <param name="arr1">������ 1</param>
/// <param name="size1">����������� ������� 1</param>
/// <param name="arr2">������ 2</param>
/// <param name="size2">����������� ������� 2</param>
/// <returns>��������� �� 2 ��������� ������� � ����</returns>
int* joinArrays(int* arr1, int size1, int* arr2, int size2);
/// <summary>
/// ���������� ��������� �� ������ � ����������� ���������� �� ���� �������� (�������������� ����� ���������� ���������� ���������� ���������)
/// </summary>
/// <param name="A">������ �</param>
/// <param name="M">������ ������� �</param>
/// <param name="B">������ B</param>
/// <param name="N">������ ������� B</param>
/// <param name="unique">���������� ���������� ��������� �������</param>
/// <returns>���������� ��������� �� ������ � ����������� ���������� �� ���� ��������</returns>
int* getUniqueElements(int* A, int M, int* B, int N, int unique);
/// <summary>
/// ������� ���������� ���������� ��������� �� 2� ��������
/// </summary>
/// <param name="A">������ �</param>
/// <param name="M">������ ������� �</param>
/// <param name="B">������ B</param>
/// <param name="N">������ ������� B</param>
/// <returns>���������� ���������� ��������� � �������</returns>
int getUniqueCount(int* A, int M, int* B, int N);
/// <summary>
/// ��������� ������� ��������� ������ ������������� ��������
/// </summary>
/// <param name="arr">������ ��� ����������</param>
/// <param name="size">������ �������</param>
/// <param name="min">����������� ����� ��� ����������</param>
/// <param name="max">������������ ����� ��� ����������</param>
void randIntArr(int arr[], int size, int min, int max);
/// <summary>
/// ��������� ����� ��������� �������������� �������
/// </summary>
/// <param name="arr">��������� �� ������ ������� �������</param>
/// <param name="size">����������� �������</param>
/// <returns>����� ��������� �������</returns>
int getSumRange(int* arr, int size);
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
/// ������������� �������.
/// </summary>
/// <typeparam name="T">��� ��������� �������.</typeparam>
/// <param name="matrix">�������� �������.</param>
/// <param name="rows">���������� ����� � �������� �������.</param>
/// <param name="cols">���������� �������� � �������� �������.</param>
/// <returns>��������� �� ����������������� �������.</returns>
template<typename T>
void transposeMatrix(T** &matrix, int rows, int cols);
/// <summary>
/// ��������� �������������� ����� �������
/// </summary>
/// <typeparam name="T">��� �������</typeparam>
/// <typeparam name="N">������ �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <param name="d">����������� ������ 'a'-����� 'd'-������</param>
template<typename T>void MassShift(T* a, int N, char d);
/// <summary>
/// ��������� ����� 2� ������� �������
/// </summary>
/// <typeparam name="T">��� �������</typeparam>
/// <typeparam name="N">������ ������� �����</typeparam>
/// <typeparam name="M">������ ������� �������</typeparam>
/// <param name="a">������ �� ������</param>
/// <param name="d">����������� w-����� a-����� s-���� d-������</param>
template<typename T>void MassShift(T**a, int N, int M, char d);
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
/// ��������� �������� �� ������ �����������
/// </summary>
/// <param name="str">������</param>
/// <returns>true ���� ������ ���������</returns>
bool isPalindrome(char* str);
/// <summary>
/// ��������� �������� �� ������ ������
/// </summary>
/// <param name="symbol">������</param>
/// <returns>True ���� ������ == �����</returns>
bool isLetter(char symbol);
/// <summary>
/// ������� ���������� ���� � ������� ��������
/// </summary>
/// <param name="str">������ ��������</param>
/// <returns>���������� ����</returns>
int getCountWords(char* str);
/// <summary>
/// ��������� ��������� ���������� �������� � ������
/// </summary>
/// <param name="arr">������ �� ��������� ������</param>
/// <param name="symbol">������ ������� ����� ���������</param>
/// <returns>���������� ���������� �������� � ��������� �������</returns>
int getCountChar(char arr[], char symbol);
/// <summary>
/// �������� 1 ������ � ������ �� ������
/// </summary>
/// <param name="text">����� � ������� ����� �������� �������</param>
/// <param name="replaceable">���������� ������</param>
/// <param name="inserted">����������� ������</param>
void replase(char* text, char replaceable, char inserted);
/// <summary>
/// ��������� ������ � ��������� �������
/// </summary>
/// <param name="text">������� �����</param>
/// <param name="size">������ ������</param>
/// <param name="text2">����� ������� ����� ��������</param>
/// <param name="pos">������� � ������� ����� �������� �����</param>
void addStr(char*& text, int& size, char* text2, int pos);
/// <summary>
/// ������� �� ������������� ������� ��� ������� symbol
/// </summary>
/// <param name="text">����� �� �������� ����� ������� �������</param>
/// <param name="size">������ ������ ������� ����� ����������</param>
/// <param name="symbol">������ ������� �� ������� �� ������.</param>
void deleteCharsInText(char*& text, char symbol);
/// <summary>
/// ������������ ���������� �������� � ������
/// </summary>
/// <param name="text">����� � ������� ����� ��������� �������</param>
/// <param name="symbol">������ ������� ���� � ������</param>
/// <returns>���������� ���������� ���������� �������</returns>
int getCharInTextCount(char* text, char symbol);
/// <summary>
/// ������� ����� ������������ ������ � ���������� ������
/// </summary>
/// <param name="text">����� �� �������� ������� ������ ��������</param>
/// <param name="size">���������� ��������, � ���� ��������������� ������ �������</param>
/// <returns>��������� �� ��������� ������ ��������</returns>
char* newChars(const char* text);
/// <summary>
/// ������� ������ �� ��������� ������
/// </summary>
/// <param name="text">������</param>
/// <param name="size">������ ������</param>
/// <param name="pos">������� � ������</param>
void deleteSymbol(char* text, int pos);
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
/// <summary>
/// ���������, �������� �� text ������ �������� �� content
/// </summary>
/// <param name="text">����������� �����</param>
/// <param name="content">����������� �������</param>
/// <returns>True, ���� ��� ������� �� text ������������ � content, ����� false</returns>
bool includeContainsOnly(char* text, const char* content);
/// <summary>
///  ���������, ����� �� ����� ������������ � ������������� �����
/// </summary>
/// <param name="text">����������� �����</param>
/// <returns>���������� true ���� text �������� ������� "1234567890-"</returns>
bool isNumber(char* text);
/// <summary>
/// ��������� ����� � �����, ���� ���������� ������
/// </summary>
/// <param name="a">����� � ������� ���������</param>
/// <param name="b">����� ������� ���������</param>
void addStr(char* a, const char* b);
/// <summary>
/// ����������� ����� � ����� (����� ��������������� �������� bool isNumber(char* text))
/// </summary>
/// <param name="num">�����</param>
/// <returns>���������� ��������������� ����� �� ������</returns>
int strToInt(char* num);

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

void show(TaskStructure& m, int** array, int rows, int columns);
/// <summary>
/// ����������� ��������� ����
/// </summary>
/// <param name="startPos">���������� ������ �������� ���� ����</param>
/// <param name="countMenu">���������� ��������� ����</param>
/// <param name="elemMenu">������ �� ������ ����</param>
/// <param name="n">�������, ��������� ������� ����</param>
/// <returns>���������� ��������� ����</returns>
Menu constructMenu(Coordinate startPos, int countMenu, const char* elemMenu[], int n);
/// <summary>
/// ������� ��� ��������� � ����
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(TaskStructure& m);
/// <summary>
/// ��������������� ������� ������������� ������ � ����
/// </summary>
void startMenu();
/// <summary>
/// ������ �������������� ������ � �������
/// </summary>
/// <param name="m">��������� ����</param>
void constructMenu(TaskStructure& m);
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
void showItemMenu(TaskStructure m);
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
void endTask(TaskStructure& m);
/// <summary>
/// ������ �� ������ ������� ��� �������� ����
/// </summary>
/// <param name="m">��������� ����</param>
void showMenu(const TaskStructure m);

void task1(TaskStructure);

void task2(TaskStructure);

void task3(TaskStructure);

void task4(TaskStructure);

void task5(TaskStructure);

void task6(TaskStructure);

void task7(TaskStructure);

void task8(TaskStructure);
/// <summary>
/// �������� ����� �������� �������� ���� � �������������� ���
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="direction">����������� w - �����, s - ����</param>
void changeItemMenu(TaskStructure &m, char direction);
/// <summary>
/// �������� ����� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showTextMenu(TaskStructure &m);
/// <summary>
/// ��������� ����������� �� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <returns>���������� ����� �������� ���������� � ����</returns>
int scrollMenu(Menu m);
/// <summary>
/// ������� ��������� � ����
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(Menu& m);
void showWrappedText(TaskStructure& m, char* text);

/*List*/

//��������� � ������ ������
void to_start(Mlist& lst);
//��������� � ����� ������
void to_end(Mlist& lst);
//��������� � ���������� �������� ������
void to_next(Mlist& lst);
//��������� � ����������� �������� ������
void to_prev(Mlist& lst);
//�������� ������� ������� ������
void* get_cur(Mlist& lst);
//���������, ������ ��������� ������� ������?
bool is_end(Mlist& lst);
//���������� ���� ������
void show(Mlist& lst);
//���������� ���� ������
void show(Mlist& lst, Coordinate& xy);
//��������� � ������ ����� �������
void add_to_start(Mlist& lst, char* data);
//��������� � ������ ����� �������
void add_to_start(Mlist& lst, const char* data);
//�������� ����� ������� ���������
void add_to_prev(Mlist& lst, char* data);
//�������� ����� �������� ��������
void add_to_next(Mlist& lst, char* data);
//������� ������� �������
void del_cur(Mlist& lst);
//������� ��� ��������
void cls_list(Mlist& lst);

/*Stack*/
//��������� ����� ������� �� ������� �����.
void push(Mstack& s, int data);
//���������� ��� �������� ������
void show(Mlist& lst);
//������� ������� � ������� ����� � ���������� ��� ��������
int pop(Mstack& s);
//���������� �������� �������� �� ������� �����
int heap(Mstack& s);


/*Phone number*/

/// <summary>
/// �������� ������� �������
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="cur">�������, ��������� �������</param>
/// <param name="name">��� ������� ����� ������</param>
/// <param name="phone">������� ������� ����� ������</param>
void changeData(char***& data, int& countNow, int cur, char* name, char* phone);
/// <summary>
/// ������� ������� �������
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="cur">�������, ��������� �������</param>
void delCurData(char***& data, int& countNow, int& cur);
/// <summary>
/// �������� ����� ������� � ���������� �����
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="name">���</param>
/// <param name="phone">����� ��������</param>
void addUser(char***& data, int& countNow, char* name, char* phone);
/// <summary>
/// �������� ����� ������� � ���������� �����
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="name">���</param>
/// <param name="phone">����� ��������</param>
void addUser(char***& data, int& countNow, const char* cName, const char* cPhone);
/// <summary>
/// ������� �� ����� ������ ���������� �����
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="cur">�������, ��������� �������</param>
/// <param name="m"></param>
void showData(char*** data, int countNow, int cur, TaskStructure& m);
/// <summary>
/// ���������� ��������� ����� � ��������
/// </summary>
/// <param name="ABC">������ ������� ����� ��������������</param>
/// <returns>�������� ������</returns>
char toLowerRus(char ABC);
/// <summary>
/// ��������� �� ���������� ��������� �������
/// </summary>
/// <param name="text1">��� ����</param>
/// <param name="text2">��� ����</param>
/// <returns>true ���� ��������� text1 � ������� text2</returns>
bool textMatch(const char* text1, const char* text2);
/// <summary>
/// ���� ���������� � ���������� �����
/// </summary>
/// <param name="data">��������� �� ���������� �����</param>
/// <param name="countNow">���������� ��������� � ���������� �����</param>
/// <param name="what">����� ������� ����</param>
/// <returns>���������� -1 � ������ �� ���������� ��������, ���� ����� ������� �������� ������� �������� �� ������</returns>
int searchData(char*** data, int countNow, char* what);

