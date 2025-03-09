#pragma once
#include "../console/console.h"
/*List*/

struct lBook {
    char* title = nullptr;
    char* author = nullptr;
    char* publishing = nullptr;
    char* genre = nullptr;
};
struct Mitem {
    lBook* data = nullptr;
    Mitem* next = nullptr;
    Mitem* prev = nullptr;
};

struct Mlist {
    Mitem* start = nullptr;
    Mitem* end = nullptr;
    Mitem* cur = nullptr;
};

//Добавляет в начало новый элемент
void add_to_prev(Mlist& lst, lBook* data);
//Переходит в начало списка
void to_start(Mlist& lst);
//Переходим в конец списка
void to_end(Mlist& lst);
//Переходим к следующему элементу списка
void to_next(Mlist& lst);
//Переходим к предыдущему элементу списка
void to_prev(Mlist& lst);
//Получаем текущий элемент списка
lBook* get_cur(Mlist& lst);
//Проверяем, выбран последний элемент списка?
bool is_end(Mlist& lst);


//Показывает весь список
void show(Mlist& lst);
//Показывает весь список
void show(Mlist& lst, Coordinate& xy);

//void add_to_start(Mlist& lst, void* data);
//Добавляет в начало новый элемент
//Добавить перед текущим элементом
//void add_to_prev(Mlist& lst, void* data);
//Добавить после текущего элемента
//void add_to_next(Mlist& lst, void* data);
//Удаляет текущий элемент
void del_cur(Mlist& lst);
//Удаляет все элементы
void cls_list(Mlist& lst);