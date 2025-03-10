#pragma once
#include "../console/console.h"
/*List*/

struct LBook {
    char* title = nullptr;
    char* author = nullptr;
    char* publishing = nullptr;
    char* genre = nullptr;
};
struct Mitem {
    LBook* data = nullptr;
    Mitem* next = nullptr;
    Mitem* prev = nullptr;
};

struct Mlist {
    Mitem* start = nullptr;
    Mitem* end = nullptr;
    Mitem* cur = nullptr;
    int count = 0;
};

//Добавляет в начало новый элемент
void add_to_prev(Mlist& lst, LBook* data);
//Переходит в начало списка
void to_start(Mlist& lst);
//Переходим в конец списка
void to_end(Mlist& lst);
//Переходим к следующему элементу списка
void to_next(Mlist& lst);
//Переходим к предыдущему элементу списка
void to_prev(Mlist& lst);
//Получаем текущий элемент списка
LBook* get_cur(Mlist& lst);
//Проверяем, выбран последний элемент списка?
bool is_end(Mlist& lst);
//Проверяем, выбран первый элемент списка?
bool is_start(Mlist& lst);
//Показывает весь список
void show(Mlist& lst);
//Удаляет текущий элемент
void del_cur(Mlist& lst);
//Удаляет все элементы
void cls_list(Mlist& lst);
//Добавляет в начало новый элемент
void add_to_start(Mlist& lst, LBook* data);
//Добавить после текущего элемента
void add_to_next(Mlist& lst, LBook* data);
//Позволяет визуализировать пролистку текста вверх вниз
void go_to(Mlist& lst, int index);
/// <summary>
/// Ищет текст в книгах, относительно индекса, и устанавливает указатель в найденном тексте
/// </summary>
/// <param name="lst">Книги</param>
/// <param name="numIndex">Номер индекса элемента по которому осуществляется поиск
///  0 - название, 1 - автор, 2 - издательство, 3 - жанр</param>
/// <param name="what">Текст или часть текста по которому осуществляется поиск</param>
/// <returns>true, если текст найден</returns>
bool get_search(Mlist& lst, int numIndex, char* what);
/// <summary>
/// Редактирует текущий элемент по указанному индексу
/// </summary>
/// <param name="lst">Книги</param>
/// <param name="num"></param>
/// <param name="numIndex"></param>
/// <param name="text"></param>
void edit_cur(Mlist& lst, int num, int numIndex, char* text);
/// <summary>
/// Сортирует книги, по выбранному индексу
/// </summary>
/// <param name="lst">Книги</param>
/// <param name="index">Номер индекса элемента по которому осуществляется сортировка
///  0 - название, 1 - автор, 2 - издательство, 3 - жанр</param></param>
void sort_list(Mlist& lst, int index);
