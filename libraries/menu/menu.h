#pragma once
#include "../console/console.h"
//+-------------------------------------------------+
//|�� �������� ��� �����������                      |
//|#include "../console/console.h"                  |
//|� �������� �����                                 |
//+-------------------------------------------------+

//�������� ������� ���� (BG,FG,borderFG,hiBG,hiFG )
struct menuColor {
    int BG; //���� ���� ��������� ����
    int FG; //���� ������ �������� ����
    int borderFG; //���� ��������� ����
    int hiBG; //���� ����������� ���� �������� ����
    int hiFG; //���� ����������� ������ �������� ����
};

//�������������� ����� ��������� ����
struct Info { 
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    int width; //�������� ������ ������ ������
    int height;//�������� ������ ������ ������+
    int* filledLines; //���������� ����������� �����
    char** text; //����� ����� ���������� �� �������� ����
    bool border;//���������
    bool visible;//���������
    menuColor color;//�������� ������� 
};

struct Head {
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    char* text;
    int inTop;//������ ������
    int inLeft;//������ �����
    int inDown;//������ �����
    int inRight;//������ ������
    int width; //������ ����
    int height;//������ ����
    bool border;//��������� ����
    bool visible;//���������
    menuColor color;//�������� ������� 
    
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

    Info info; //�������� ��������� ����
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
void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border, menuColor color = {0});
void daaInfoMenu(Menu& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor color = {0});
//������� � ������ ���������� ����
void clsMenu(Menu m);
void showHeadMenu(Menu m);