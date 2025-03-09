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

//��������� � ������ ����� �������
void add_to_prev(Mlist& lst, lBook* data);
//��������� � ������ ������
void to_start(Mlist& lst);
//��������� � ����� ������
void to_end(Mlist& lst);
//��������� � ���������� �������� ������
void to_next(Mlist& lst);
//��������� � ����������� �������� ������
void to_prev(Mlist& lst);
//�������� ������� ������� ������
lBook* get_cur(Mlist& lst);
//���������, ������ ��������� ������� ������?
bool is_end(Mlist& lst);


//���������� ���� ������
void show(Mlist& lst);
//���������� ���� ������
void show(Mlist& lst, Coordinate& xy);

//void add_to_start(Mlist& lst, void* data);
//��������� � ������ ����� �������
//�������� ����� ������� ���������
//void add_to_prev(Mlist& lst, void* data);
//�������� ����� �������� ��������
//void add_to_next(Mlist& lst, void* data);
//������� ������� �������
void del_cur(Mlist& lst);
//������� ��� ��������
void cls_list(Mlist& lst);