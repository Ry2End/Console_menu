#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

const char UP = 72;
const char DOWN = 80;
const char ESC = 27;

//using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли

// Функция, задающая положение Текстового курсора в точку x,y
void GoToXY(short x, short y)
{
SetConsoleCursorPosition(hStdOut, {x, y});
}

//Настройка видимости (show) и размера (size) курсора
void ConsoleCursorVisible(bool show, short size)
{
CONSOLE_CURSOR_INFO structCursorInfo;
GetConsoleCursorInfo(hStdOut, &structCursorInfo);
structCursorInfo.bVisible = show; // изменяем видимость курсора
structCursorInfo.dwSize = size; // изменяем размер 
SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

int main()
{

    setlocale(0, "Rus");
    ConsoleCursorVisible(false, 100);
    SetConsoleTitleW(L"Меню!");
    //Меню
    std::string Menu[] = {"Elka.exe", "BJ.exe", "Exit"}; //Пункты меню
    int active_menu = 0; 


    char ch;
    while(true)
    {
       
        int x_menu = 40, y_menu = 12; //Переменные координат стартового меню    
        GoToXY(x_menu,y_menu); //Перевод курсора в заданную позицию

        for (int i = 0; i < std::size(Menu); i++)  //Построчный вывод массива пунктов меню
        {   
            if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //Если пункт меню "активный", то он ЯРКИЙ синий
            else 
                SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE); //Если пункт меню "неактивный", то он просто синий
            GoToXY(x_menu, y_menu++);
            std::cout<< Menu[i] << std::endl;
        }        

        ch = _getch();
        if (ch == -32) ch = _getch(); //отлавливаем стрелочки
        //GoToXY(x_menu, y_menu);
        switch (ch)
        {
            case ESC:
                exit(0);
            case UP:
                //system("CLS");
                if (active_menu > 0) --active_menu; //Чтобы не вылететь за границы массива меню. Нажимая вверх, "Курсор" не уйдёт с верхнего пункта меню
                //std::cout<< "Up, Code" << (int)ch << std::endl;
                break;
            case DOWN:
                //system("CLS");
                if (active_menu < (std::size(Menu) - 1)) ++active_menu; //Чтобы не вылететь за границы массива меню. Нажимая вниз, "Курсор" не уйдёт с нижнего пункта меню
                //std::cout<< "Down, Code" << (int)ch << std::endl;
                break;
            default:
                //system("CLS");
                GoToXY(x_menu, y_menu + (std::size(Menu) + 2));
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
                std::cout << "Code pressed buttons is " << (int)ch << "       " << std::endl;
        }
        //system("CLS");
        //cout << " Код " << (int)ch << endl;
    }

}