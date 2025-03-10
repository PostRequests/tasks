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

//��������� � ������ ����� �������
void add_to_prev(Mlist& lst, LBook* data);
//��������� � ������ ������
void to_start(Mlist& lst);
//��������� � ����� ������
void to_end(Mlist& lst);
//��������� � ���������� �������� ������
void to_next(Mlist& lst);
//��������� � ����������� �������� ������
void to_prev(Mlist& lst);
//�������� ������� ������� ������
LBook* get_cur(Mlist& lst);
//���������, ������ ��������� ������� ������?
bool is_end(Mlist& lst);
//���������, ������ ������ ������� ������?
bool is_start(Mlist& lst);
//���������� ���� ������
void show(Mlist& lst);
//������� ������� �������
void del_cur(Mlist& lst);
//������� ��� ��������
void cls_list(Mlist& lst);
//��������� � ������ ����� �������
void add_to_start(Mlist& lst, LBook* data);
//�������� ����� �������� ��������
void add_to_next(Mlist& lst, LBook* data);
//��������� ��������������� ��������� ������ ����� ����
void go_to(Mlist& lst, int index);
/// <summary>
/// ���� ����� � ������, ������������ �������, � ������������� ��������� � ��������� ������
/// </summary>
/// <param name="lst">�����</param>
/// <param name="numIndex">����� ������� �������� �� �������� �������������� �����
///  0 - ��������, 1 - �����, 2 - ������������, 3 - ����</param>
/// <param name="what">����� ��� ����� ������ �� �������� �������������� �����</param>
/// <returns>true, ���� ����� ������</returns>
bool get_search(Mlist& lst, int numIndex, char* what);
/// <summary>
/// ����������� ������� ������� �� ���������� �������
/// </summary>
/// <param name="lst">�����</param>
/// <param name="num"></param>
/// <param name="numIndex"></param>
/// <param name="text"></param>
void edit_cur(Mlist& lst, int num, int numIndex, char* text);
/// <summary>
/// ��������� �����, �� ���������� �������
/// </summary>
/// <param name="lst">�����</param>
/// <param name="index">����� ������� �������� �� �������� �������������� ����������
///  0 - ��������, 1 - �����, 2 - ������������, 3 - ����</param></param>
void sort_list(Mlist& lst, int index);
