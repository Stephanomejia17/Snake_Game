#include "Juego.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace sf;

Music musica_fondo;
Music coin;
Music choque;

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
bool Juego::ReproducirMusica1() {
    while (!musica_fondo.openFromFile("mario-coin.wav")) {
        return false;
    }
    musica_fondo.play();
}
bool Juego::ReproducirMusica2() {
    while (!musica_fondo.openFromFile("choque.wav")) {
        return false;
    }
    musica_fondo.play();
}
bool Juego::ReproducirMusica3() {
    while (!musica_fondo.openFromFile("cascabel.wav")) {
        return false;
    }
    musica_fondo.play();
}

void Juego::tablero2() {
    ///lineas horizontales
    for (int i = 2; i < 78; i++) {
        gotoxy(i, 0); printf("%c", 205);
        gotoxy(i, 25); printf("%c", 205);
    }
    //lineas verticales
    for (int i = 1; i < 25; i++) {
        gotoxy(2, i); printf("%c", 186);
        gotoxy(77, i); printf("%c", 186);
    }

    //Esquinas
    gotoxy(2, 0); printf("%c", 201);
    gotoxy(2, 25); printf("%c", 200);
    gotoxy(77, 0); printf("%c", 187);
    gotoxy(77, 25); printf("%c", 188);
}
void Juego::tablero() {
    //Info
    gotoxy(30, 2); printf("Bienvenido a SNAKE");
    gotoxy(94, 2); printf("Guia de Juego");
    gotoxy(90, 4); printf("%c", 4); gotoxy(92, 4); printf("Te aumenta un punto");
    gotoxy(90, 6); printf("%c", 3); gotoxy(92, 6); printf("Te hace mas veloz");
    gotoxy(90, 8); printf("%c", 30); gotoxy(92, 8); printf("Te aumenta el tamanio");
    //lineas horizontales
    for (int i = 2; i < 78; i++) {
        gotoxy(i, 0); printf("%c", 205);
        gotoxy(i, 25); printf("%c", 205);
    }
    for (int i = 2; i < 78; i++) {
        gotoxy(i, 4); printf("%c", 205);
    }
    //lineas verticales
    for (int i = 1; i < 25; i++) {
        gotoxy(2, i); printf("%c", 186);
        gotoxy(77, i); printf("%c", 186);
    }

    //Esquinas
    gotoxy(2, 0); printf("%c", 201);
    gotoxy(2, 25); printf("%c", 200);
    gotoxy(77, 0); printf("%c", 187);
    gotoxy(77, 25); printf("%c", 188);
}

void Juego::muerte2() {
    ReproducirMusica2();
    system("cls"); //limpiar pantalla
    int c = 25, f = 77, r;
    char key;
    tablero2();


    string g4meover[] = { "  ____                       ___"," / ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ ",
    "| |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__|","| |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ | ",
    " \\____|\\__,_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|" };
    r = 2;
    for (int i = 0; i < 5; i++) {
        gotoxy(15, r);
        r++;
        cout << g4meover[i] << endl;
    }
    for (int i = 0; i < 11; i++) {
        gotoxy(20, r);

        r++;

    }
    gotoxy(33, r);
    cout << "Score: " << score;
    r++;
    gotoxy(8, 23);
    cout << "Presione ESC para salir o cualquier otra tecla para seguir jugando";
    key = _getch();
    if (key == 27) //si se presiona ESC cierra el juego
        exit(1);
}


void Juego::portada() {
    system("cls"); // limpiar pantalla
    int c = 24, f = 79, r;
    char t = 178;
    tablero2();
    string snkd[] = { "       ---_ ......._-_--.","      (|\\ /      / /| \\  \\","      /  /     .'  -=-'   `.",
            "     /  /    .'             )","   _/  /   .'        _.)   /","  / o   o        _.-' /  .'",
            "  \\          _.-'    / .'*|","   \\______.-'//    .'.' \\*|","    \\|  \\ | //   .'.' _ |*|",
            "     `   \\|//  .'.'_ _ _|*|","      .  .// .'.' | _ _ \\*|","      \\`-|\\_/ /    \\ _ _ \\*\\",
            "                     \\ _ _ \\*","                      \\ _ _ \\ ","                       \\_" };

    r = 2;
    for (int i = 0; i < 14; i++) {
        gotoxy(20, r);
        r++;
        cout << snkd[i] << endl;
    }

    string snkl[] = { "                     __     ","   _________  ____ _/ /_____","  / ___/ __ \\/ __ `/ //_/ _ \\",
    " (__  ) / / / /_/ / ,< /  __/","/____/_/ /_/\\__,_/_/|_|\\___/" };
    for (int i = 0; i < 5; i++) {
        gotoxy(22, r);
        r++;
        cout << snkl[i] << endl;
    }
    gotoxy(23, 23);
    cout << "Precione ENTER para empezar";
    system("pause>dsdsd");
}


void Juego::puntos() {
    gotoxy(3, 2);
    cout << "Score: " << (score - 1);
    gotoxy(65, 2);
    cout << "Length: " << tam;



}


void Juego::genFruta() {
    if (score % 5 == 0) {
        
        fruta2.x = 3 + (rand() % 73);
        fruta2.y = 5 + (rand() % 19);
        gotoxy(fruta2.x, fruta2.y);
        cout << fruta2.cuerpo;
    }
    else if (tam % 3 == 0) {
        fruta3.x = 3 + (rand() % 73);
        fruta3.y = 5 + (rand() % 19);
        gotoxy(fruta3.x, fruta3.y);
        cout << fruta3.cuerpo;
    }
    else {
        fruta.x = 3 + (rand() % 73);
        fruta.y = 5 + (rand() % 19);
        gotoxy(fruta.x, fruta.y);
        cout << fruta.cuerpo;
    }

}


void Juego::muerte() {
    if (snake[0].x == 2 || snake[0].x == 77 || snake[0].y == 4 || snake[0].y == 25)
        gameover = true;
    /*for (int i = 0; i < 10; i++)
    {
        if (snake[0].x == wall[i].x && snake[0].y == wall[i].y){
            gameover = true;
        }
    }*/
    for (int i = 1; i < tam && gameover == false; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameover = true;
        }

    }
}

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
void Juego::genSnake() {
    int i;
    snake[0].x = 30;
    snake[0].y = 10;
    snake[0].dx = 1;
    snake[0].dy = 0;
    snake[0].cuerpo = 254;



    for (i = 1; i < tam; i++) {
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;
        snake[i].cuerpo = 254;
    }


    for (i = 0; i < tam; i++) {
        gotoxy(snake[i].x, snake[i].y);
        cout << snake[i].cuerpo;
    }
}
/*void Juego::genWall() {
    wall[0].x = 3 + (rand() & 73);
    wall[0].y = 5 + (rand() & 19);
    wall[0].cuerpo = 205;

    for (int i = 0; i < sizeof(wall) / sizeof(wall[0]); i++) {
        wall[i].x = wall[i - 1].x - 1;
        wall[i].y = wall[i - 1].y;
        wall[i].cuerpo = 205;
    }
    for (int i = 0; i < sizeof(wall) / sizeof(wall[0]); i++) {
        gotoxy(wall[i].x, wall[i].y);
        cout << wall[i].cuerpo;
    }
}*/

void Juego::cfruta() {
    if (snake[0].x == fruta.x && snake[0].y == fruta.y) {
        ReproducirMusica1();
        tam += 1;
        snake[tam - 1].cuerpo = 254; //aumenta el tamaño de la serpiente
        score += 1;
        genFruta();
    }
    else if(snake[0].x == fruta2.x && snake[0].y == fruta2.y) {
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

void Juego::actualizar() { //borrar el cuerpo
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

void Juego::imprimir() {
    int i;
    for (i = tam - 1; i >= 0; i--) {
        gotoxy(snake[i].x, snake[i].y);
        cout << snake[i].cuerpo;
    }
}

void Juego::loop() {
    while (!gameover) {

        cfruta();
        puntos();
        actualizar();
        imprimir();
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
    portada();
    system("cls");
    score = 1;
    velocidad = 110;
    tam = 4;
    tablero();
    srand(time(NULL));
    genSnake();
    genFruta();
    //genWall();
    loop();
    muerte2();
    main();
}