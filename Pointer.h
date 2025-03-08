#pragma once


/// <summary>
/// Добавляем книги для const char
/// </summary>
/// <param name="books">Все книги</param>
/// <param name="count">Количество книг</param>
/// <param name="b">Книга которую нужно добавить</param>
void addBook(char***& books, int& count, char b[][100]);
/// <summary>
/// Добавляем книги для char***
/// </summary>
/// <param name="books">Все книги</param>
/// <param name="count">Количество книг</param>
/// <param name="b">Книга которую нужно добавить</param>
void addBook(char***& books, int& count, char** b);
/// <summary>
/// Показывает все книги
/// </summary>
/// <param name="books">Список книг</param>
/// <param name="count"Количество книг></param>
void showBook(char*** books, int count);
/// <summary>
/// Показать одну книгу
/// </summary>
/// <param name="books">Список книг</param>
/// <param name="count">Количество книг</param>
/// <param name="number">Номер книги которую нужно показать</param>
void showBook(char*** books, int count, int number);
/// <summary>
/// Удаляет книгу
/// </summary>
/// <param name="book">Все книги</param>
/// <param name="count">Количество книг</param>
/// <param name="number">Номер книги которую нужно удалить</param>
void delBook(char*** book, int& count, int number);