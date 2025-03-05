#pragma once
#include "../console/console.h"
//|-------------------------------------------------|
//|�� �������� ��� �����������                      |
//|#include "../console/console.h"                  |
//|� �������� �����                                 |
//|_________________________________________________|

//�������� ������� ����
struct menuColor {
    int BG; //���� ���� �������� ����
    int FG; //���� ������ �������� ����
    int hiBG; //���� ����������� ���� �������� ����
    int hiFG; //���� ����������� ������ �������� ����
    int borderFG; //���� ��������� ����
};

//����
struct Menu {
    Coordinate start;//���������� ������ ����� ������ ����
    char** item = nullptr;//�������� ����
    int count; //���������� ��������� � ����
    int n; //����� ���������� �������� ����
    menuColor color;//�������� ������� ����
    int lineSkip; //���������� ����������� ����� ����� ���������� ����
    int width; //������ ����
    int height;//������ ����
    bool visible;//��������� ����
    bool border;//��������� ����
};

/// <summary>
/// ��������� ����������� �� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="closeEnd">��������� ����� ������ �������� ����? True �� ��������� ���������</param>
/// <returns>���������� ����� �������� ���������� ������ ����</returns>
int getShowMenu(Menu m, bool closeEnd = true);
/// <summary>
/// ������� ��������� � ����. �� ������� �������� ��� ��������� ������.
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(Menu& m);
Menu constructMenu(Coordinate start, const char** item, int count, menuColor color, int lineSkip = 1, char place = 'l', bool border = false);