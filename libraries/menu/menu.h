#pragma once
#include "../console/console.h"
//+-------------------------------------------------+
//|Не работает без подключения                      |
//|#include "../console/console.h"                  |
//|В основном файле                                 |
//+-------------------------------------------------+

//Цветовая палитра меню (BG,FG,borderFG,hiBG,hiFG )
struct menuColor {
    int BG; //Цвет фона элементов меню
    int FG; //Цвет текста элемента меню
    int borderFG; //Цвет окантовки меню
    int hiBG; //Цвет выделенного фона элемента меню
    int hiFG; //Цвет выделенного текста элемента меню
};

//Информационный текси элементов меню
struct Info { 
    Coordinate start;//Координаты начала места печати
    Coordinate finish;//Координаты конца места печати
    int width; //Полезная ширина вывода текста
    int height;//Полезная высота вывода текста+
    int* filledLines; //Количество заполненных линий
    char** text; //Текст текст информации по элементу меню
    bool border;//Окантовка
    bool visible;//Видимость
    menuColor color;//Цветовая палитра 
};

struct Head {
    Coordinate start;//Координаты начала места печати
    Coordinate finish;//Координаты конца места печати
    char* text;
    int inTop;//Отступ сверху
    int inLeft;//Отступ слева
    int inDown;//Отступ снизу
    int inRight;//Отступ справа
    int width; //Ширина окна
    int height;//Высота окна
    bool border;//Окантовка меню
    bool visible;//Видимость
    menuColor color;//Цветовая палитра 
    
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

    Info info; //Элемениы иформации меню
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
void addHeadMenu(Menu& m, Coordinate start, char* head, int margin[4], bool border, menuColor color = {0});
void daaInfoMenu(Menu& m, Coordinate start, Coordinate finish, const char** textInfo, bool border, menuColor color = {0});
//Очищает с экрана содержание меню
void clsMenu(Menu m);
void showHeadMenu(Menu m);