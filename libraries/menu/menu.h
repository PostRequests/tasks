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
    char** text; //����� ����� ���������� �� �������� ����
    bool border;//���������
    bool visible = false;//���������
    menuColor color;//�������� ������� 
};

struct Head {
    Coordinate start;//���������� ������ ����� ������
    Coordinate finish;//���������� ����� ����� ������
    char* text = nullptr;
    int inTop;//������ ������
    int inLeft;//������ �����
    int inDown;//������ �����
    int inRight;//������ ������
    int width; //������ ����
    int height;//������ ����
    bool border;//��������� ����
    bool visible = false;//���������
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
    bool visible = false;//��������� ����
    bool border;//��������� ����

    /*�� ������������ ���������, �������� ��������*/

    Head head; //����� ����

    Info info; //�������� ���������� ����
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
/// <summary>
/// � ������ ������� ��������� �������� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="start">��������� ����������, ��� ����� �������� ���������� ����</param>
/// <param name="item">�������� ����, ������ �� �����, ��� ������ ������ ������� ����</param>
/// <param name="count">���������� ��������� ����(������ ������� item)</param>
/// <param name="color">�������� ������� ���� (BG,FG,borderFG,hiBG,hiFG )</param>
/// <param name="lineSkip">���������� ����� ����������</param>
/// <param name="place">l - �� ������ ���� r - �� ������� ���� c - �� ������</param>
/// <param name="border">������� ��������� ������ ����</param>
void constructMenu(Menu &m, Coordinate start, const char** item, int count, menuColor color, int lineSkip = 1, char place = 'l', bool border = false);
/// <summary>
/// ��������� ��������� ���� (�� �����������)
/// </summary>
/// <param name="m">��������� ��� ����� ���������� ����</param>
/// <param name="start">��������� ������� ��������� ������ ����</param>
/// <param name="head">�������� ����</param>
/// <param name="margin">������� [������, �����, �����, ������]</param>
/// <param name="border">������� ���������</param>
/// <param name="color">�������� ������� (BG,FG,borderFG,hiBG,hiFG)</param>
void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border, menuColor color = { 0 });
/// <summary>
/// ��������� ���������� �� ��������� ���� (�� �����������)
/// </summary>
/// <param name="m">��������� ����</param>
/// <param name="start">��������� ������� ��������� ����</param>
/// <param name="finish">������ ������ ���� ��������� ����</param>
/// <param name="textInfo">������ �� ��������� ����</param>
/// <param name="border">������� ���������</param>
/// <param name="color">�������� ������� (BG,FG,borderFG,hiBG,hiFG)</param>
void addInfoMenu(Menu& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor color = { 0 });
//������� � ������ ���������� ����
void clsMenu(Menu m);
//������� � ������ ���������� ���������
void clsHead(Menu m);
//������� � ������ ���������� ���������� ��������� ����
void clsInfo(Menu m);
//������������ ������ ��������� ����
void showHeadMenu(Menu m);
