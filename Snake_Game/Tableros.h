#ifndef __TABLEROS_H__
#define __TABLEROS_H__
#include "Recursos.h"
#include "Sounds.h"
#include <iostream>
using namespace std;

void tablero2() {
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
void tablero() {
    //Info
    gotoxy(30, 2); printf("Bienvenido a SNAKE");
    gotoxy(87, 2); printf("Guia de Juego");
    gotoxy(82, 4); printf("%c", 4); gotoxy(84, 4); printf("Te aumenta un punto");
    gotoxy(82, 6); printf("%c", 3); gotoxy(84, 6); printf("Te hace mas veloz");
    gotoxy(82, 8); printf("%c", 30); gotoxy(84, 8); printf("Te aumenta el tamanio");
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
void muerte2(int score) {
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
void portada(int score, int tam) {
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
void puntos(int score, int tam) {
    gotoxy(3, 2);
    cout << "Score: " << score;
    gotoxy(65, 2);
    cout << "Length: " << tam;
}



#endif