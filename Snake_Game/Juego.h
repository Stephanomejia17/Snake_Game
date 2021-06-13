#include <iostream>
#include "Snake.h"
#include "Fruta.h"
#include "Fruta2.h"
#include "Wall.h"

class Juego {
public:
    void main();
private:
    int score, velocidad;
    Snake snake[100];
    Fruta fruta;
    Fruta2 fruta2;
    Wall wall[10];
    int tam = 4;
    int c = 25, f = 77; //limites
    bool gameover = false;
    void tablero();
    void tablero2();
    void genFruta(); //generar fruta
    void genSnake(); //generar snake
    void genWall(); //generar pared
    void loop(); //while
    void tecla();
    void actualizar(); //borra la colita
    void imprimir();
    void cfruta(); //comer fruta
    void muerte(); //muerte si pasa los limites o choca con su cuerpo
    void puntos(); //score
    void portada(); //dibujo de snake
    void muerte2(); //dibujo de gameover
    bool ReproducirMusica1();
    bool ReproducirMusica2();
    bool ReproducirMusica3();
};