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
};

//����
struct Menu {
    Coordinate startPos;//���������� ������ ����� ������ ����
    int countMenu; //���������� ��������� � ����
    char** elemMenu = nullptr;//�������� ����
    int n; //����� ���������� �������� ����
    menuColor color;//�������� ������� ����
    int lineSkip; //���������� ����������� ����� ����� ���������� ����
    int width; //������ ����
    bool visible = false;//��������� ����
    void* border = nullptr;//��������� ����
};


/// <summary>
/// �������� �������� ���� �� ������
/// </summary>
/// <param name="m">��������� ����</param>
void showItemMenu(Menu m);
/// <summary>
/// ��������� ����������� �� ����
/// </summary>
/// <param name="m">��������� ����</param>
/// <returns>���������� ����� �������� ���������� � ����</returns>
int scrollMenu(Menu m);
/// <summary>
/// ������� ��������� � ����. �� ������� �������� ��� ��������� ������.
/// </summary>
/// <param name="m">��������� ����</param>
void clearMenu(Menu& m);