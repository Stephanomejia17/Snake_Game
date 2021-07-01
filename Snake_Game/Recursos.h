#ifndef __RECURSOS_H__
#define __RECURSOS_H__
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
#endif