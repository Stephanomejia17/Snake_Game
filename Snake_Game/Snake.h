#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "Recursos.h"
#include <iostream>
using namespace std;

class Snake {
public:
    int x, y;
    int dx, dy;
    char cuerpo;
};
inline void genSnake(Snake serpiente[], int tamaño) {
    int i;
    serpiente[0].x = 30;
    serpiente[0].y = 10;
    serpiente[0].dx = 1;
    serpiente[0].dy = 0;
    serpiente[0].cuerpo = 254;



    for (i = 1; i < tamaño; i++) {
        serpiente[i].x = serpiente[i - 1].x - 1;
        serpiente[i].y = serpiente[i - 1].y;
        serpiente[i].cuerpo = 254;
    }


    for (i = 0; i < tamaño; i++) {
        gotoxy(serpiente[i].x, serpiente[i].y);
        cout << serpiente[i].cuerpo;
    }
}
inline void actualizar(Snake snake[], int tam) {
    int i;
    gotoxy(snake[tam - 1].x, snake[tam - 1].y);
    cout << " ";

    for (i = tam - 1; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    snake[0].x += snake[0].dx;
    snake[0].y += snake[0].dy; //mueve a la serpiente
}
inline void imprimir(Snake snake[], int tam) {
    int i;
    for (i = tam - 1; i >= 0; i--) {
        gotoxy(snake[i].x, snake[i].y);
        cout << snake[i].cuerpo;
    }
}
#endif