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