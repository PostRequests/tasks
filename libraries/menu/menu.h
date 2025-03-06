#pragma once
#include "../console/console.h"
//|-------------------------------------------------|
//|Не работает без подключения                      |
//|#include "../console/console.h"                  |
//|В основном файле                                 |
//|_________________________________________________|

//Цветовая палитра меню (BG,FG,hiBG,hiFG, borderFG)
struct menuColor {
    int BG; //Цвет фона элементов меню
    int FG; //Цвет текста элемента меню
    int hiBG; //Цвет выделенного фона элемента меню
    int hiFG; //Цвет выделенного текста элемента меню
    int borderFG; //Цвет окантовки меню
};

struct Head {
    Coordinate start;//Координаты начала места печати
    Coordinate finish;//Координаты конца места печати
    char* head;
    int inTop;//Отступ сверху
    int inLeft;//Отступ слева
    int inDown;//Отступ снизу
    int inRight;//Отступ справа
    int width; //Ширина окна
    int height;//Высота окна
    bool border;//Окантовка меню
    bool visible;//Видимость
    
};

//Меню
struct Menu {
    Coordinate start;//Координаты начала места печати меню
    Coordinate finish;//Координаты конца места печати меню
    char** item = nullptr;//Элементы меню
    int count; //Количество элементов в меню
    int n; //Номер выбранного элемента меню
    menuColor color;//Цветовая палитра меню
    int lineSkip; //Количество пропущенных строк между элементами меню
    int width; //Ширина меню
    int height;//Высота меню
    bool visible;//Видимость меню
    bool border;//Окантовка меню

    /*Не обязательные параметры, задаются отдельно*/

    Head head; //Шапка меню
};

/// <summary>
/// Анимирует перемещение по меню
/// </summary>
/// <param name="m">Структура меню</param>
/// <param name="closeEnd">Закрывать после выбора элемента меню? True по умолчанию закрывать</param>
/// <returns>Возвращает номер элемента выбранного пункта меню</returns>
int getShowMenu(Menu m, bool closeEnd = true);
/// <summary>
/// Очищает указатели в меню. Не требует очищения без выделения памяти.
/// </summary>
/// <param name="m">Структура меню</param>
void clearMenu(Menu& m);
Menu constructMenu(Coordinate start, const char** item, int count, menuColor color, int lineSkip = 1, char place = 'l', bool border = false);
void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border);
//Очищает с экрана содержание меню
void clsMenu(Menu m);