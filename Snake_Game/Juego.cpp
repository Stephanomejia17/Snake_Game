#include "Juego.h"
#include "Recursos.h"
#include "Tableros.h"
#include <iostream>
#include <time.h>
using namespace std;


void Juego::tecla() {
    char key;

    if (_kbhit()) {
        key = _getch();
        if ((key == 72) && snake[0].dy != 1) {
            snake[0].dx = 0;
            snake[0].dy = -1;
        }
        if ((key == 80) && snake[0].dy != -1) {
            snake[0].dx = 0;
            snake[0].dy = 1;
        }
        if ((key == 75) && snake[0].dx != 1) {
            snake[0].dx = -1;
            snake[0].dy = 0;
        }
        if ((key == 77) && snake[0].dx != -1) {
            snake[0].dx = 1;
            snake[0].dy = 0;
        }
    }
}
void Juego::muerte() {
    if (snake[0].x == 2 || snake[0].x == 77 || snake[0].y == 4 || snake[0].y == 25)
        gameover = true;
    for (int i = 1; i < tam && gameover == false; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameover = true;
        }
    }
}

void Juego::genFruta() {
    if (score % 10 == 0 && score != 0) {
        fruta2.cuerpo = 3;
        fruta2.x = 3 + (rand() % 73);
        fruta2.y = 5 + (rand() % 19);
        gotoxy(fruta2.x, fruta2.y);
        cout << fruta2.cuerpo;
    }
    else if (tam % 10 == 0) {
        fruta3.cuerpo = 30;
        fruta3.x = 3 + (rand() % 73);
        fruta3.y = 5 + (rand() % 19);
        gotoxy(fruta3.x, fruta3.y);
        cout << fruta3.cuerpo;
    }
    else {
        fruta.cuerpo = 4;
        fruta.x = 3 + (rand() % 73);
        fruta.y = 5 + (rand() % 19);
        gotoxy(fruta.x, fruta.y);
        cout << fruta.cuerpo;
    }

}
void Juego::cfruta() {
    if (snake[0].x == fruta.x && snake[0].y == fruta.y) {
        ReproducirMusica1();
        tam += 1;
        snake[tam - 1].cuerpo = 254; //aumenta el tamaño de la serpiente
        score += 1;
        genFruta();
    }
    else if (snake[0].x == fruta2.x && snake[0].y == fruta2.y) {
        ReproducirMusica3();
        tam += 1;
        snake[tam - 1].cuerpo = 254;
        score += 1;
        velocidad -= 20;
        genFruta();
    }
    else if (snake[0].x == fruta3.x && snake[0].y == fruta3.y) {
        ReproducirMusica1();
        tam += 1;
        snake[tam - 1].cuerpo = 254;
        tam += 1;
        snake[tam - 1].cuerpo = 254;
        score += 1;
        genFruta();
    }
}



void Juego::loop() {
    while (!gameover) {

        cfruta();
        puntos(score, tam);
        actualizar(snake, tam);
        imprimir(snake, tam);
        tecla();
        tecla();
        tecla();
        muerte();
        Sleep(velocidad);
    }

}

void Juego::main() {

    system("Title SNAKE GAME!");
    system("color 0b");
    gameover = false;
    portada(score, tam);
    system("cls");
    score = 0;
    velocidad = 110;
    tam = 4;
    tablero();
    srand(time(NULL));
    genSnake(snake, tam);
    genFruta();
    loop();
    muerte2(score);
    main();
}