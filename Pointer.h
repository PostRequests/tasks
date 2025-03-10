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
void delBook(char*** &book, int& count, int number);
/// <summary>
/// Позволяет изменить один из элементов книги
/// </summary>
/// <param name="book">Массив книг</param>
/// <param name="count">Количество книг</param>
/// <param name="numBook">Номер книги которую нужно изменить</param>
/// <param name="numIndex">Номер индекса книги, который нужно изменить
///  0 - название, 1 - автор, 2 - издательство, 3 - жанр.</param>
/// <param name="textedit">Текст на который меняем содержимое</param>
void editBook(char***& book, int count, int numBook, int numIndex, char* textedit);
/// <summary>
/// Позволяет найти первую книгу по совпадению
/// </summary>
/// <param name="books">Массив книг</param>
/// <param name="count">Количество книг</param>
/// <param name="numIndex">Номер индекса элемента по которому осуществляется поиск
///  0 - название, 1 - автор, 2 - издательство, 3 - жанр.</param>
/// <param name="what">Текст или часть текста по которому осуществляется поиск</param>
/// <returns>Возвращает индекс найденного элемента</returns>
int searchBook(char*** books, int count, int numIndex, char* what);
void sortBooks(char*** books, int count, int sortIndex);
bool textMatch(const char* text1, const char* text2);