#pragma once


/// <summary>
/// ��������� ����� ��� const char
/// </summary>
/// <param name="books">��� �����</param>
/// <param name="count">���������� ����</param>
/// <param name="b">����� ������� ����� ��������</param>
void addBook(char***& books, int& count, char b[][100]);
/// <summary>
/// ��������� ����� ��� char***
/// </summary>
/// <param name="books">��� �����</param>
/// <param name="count">���������� ����</param>
/// <param name="b">����� ������� ����� ��������</param>
void addBook(char***& books, int& count, char** b);
/// <summary>
/// ���������� ��� �����
/// </summary>
/// <param name="books">������ ����</param>
/// <param name="count"���������� ����></param>
void showBook(char*** books, int count);
/// <summary>
/// �������� ���� �����
/// </summary>
/// <param name="books">������ ����</param>
/// <param name="count">���������� ����</param>
/// <param name="number">����� ����� ������� ����� ��������</param>
void showBook(char*** books, int count, int number);
/// <summary>
/// ������� �����
/// </summary>
/// <param name="book">��� �����</param>
/// <param name="count">���������� ����</param>
/// <param name="number">����� ����� ������� ����� �������</param>
void delBook(char*** book, int& count, int number);