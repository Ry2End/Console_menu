#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

const char UP = 72;
const char DOWN = 80;
const char ESC = 27;

using namespace std;

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
    GoToXY(15, 10);
    std::cout << "This programm show button code";
    GoToXY(15, 11);
    std::cout << "Press Esc button for exit";
    GoToXY(15, 12);
    std::cout << "PS: Esc button code: 27 :)" << std::endl;
    //system("CLS"); //Очистка экрана
    ConsoleCursorVisible(false, 100);
    SetConsoleTitleW(L"Моё консольное окно!");

    char ch;
    while(true)
    {
        ch = _getch();
        if (ch == -32) ch = _getch(); //отлавливаем стрелочки
        GoToXY(15, 10);
        switch (ch)
        {
            case 27:
                exit(0);
            case UP:
                system("CLS");
                GoToXY(15, 10);
                std::cout<< "Up, Code" << (int)ch << std::endl;
                break;
            case 80:
                system("CLS");
                GoToXY(15, 10);
                std::cout<< "Down, Code" << (int)ch << std::endl;
                break;
            case 75:
                system("CLS");
                GoToXY(15, 10);
                std::cout<< "Left, Code" << (int)ch << std::endl;
                break;
            case 77:
                system("CLS");
                GoToXY(15, 10);
                std::cout<< "Right, Code" << (int)ch << std::endl;
                break;
            default:
                system("CLS");
                GoToXY(15, 10);
                cout << " Code is " << (int)ch << endl;
        }
        //system("CLS");
        //cout << " Код " << (int)ch << endl;
    }

    //getch();
}