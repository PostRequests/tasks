#pragma once
#include "../console/console.h"
//|-------------------------------------------------|
//|�� �������� ��� �����������                      |
//|#include "../console/console.h"                  |
//|� �������� �����                                 |
//|_________________________________________________|

//�������� ������� ���� (BG,FG,hiBG,hiFG, borderFG)
struct menuColor {
    int BG; //���� ���� ��������� ����
    int FG; //���� ������ �������� ����
    int hiBG; //���� ����������� ���� �������� ����
    int hiFG; //���� ����������� ������ �������� ����
    int borderFG; //���� ��������� ����
};

struct Head {
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    char* head;
    int inTop;//������ ������
    int inLeft;//������ �����
    int inDown;//������ �����
    int inRight;//������ ������
    int width; //������ ����
    int height;//������ ����
    bool border;//��������� ����
    bool visible;//���������
    
};

//����
struct Menu {
    Coordinate start;//���������� ������ ����� ������ ����
    Coordinate finish;//���������� ����� ����� ������ ����
    char** item = nullptr;//�������� ����
    int count; //���������� ��������� � ����
    int n; //����� ���������� �������� ����
    menuColor color;//�������� ������� ����
    int lineSkip; //���������� ����������� ����� ����� ���������� ����
    int width; //������ ����
    int height;//������ ����
    bool visible;//��������� ����
    bool border;//��������� ����

    /*�� ������������ ���������, �������� ��������*/

    Head head; //����� ����
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
void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border);
//������� � ������ ���������� ����
void clsMenu(Menu m);