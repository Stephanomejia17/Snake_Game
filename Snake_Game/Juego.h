#ifndef __JUEGO_H__
#define __JUEGO_H__

#include <iostream>
#include "Snake.h"
#include "Fruta.h"

class Juego {
public:
    void main();
private:
    int score, velocidad;
    int nivel;
    Snake snake[100];
    Fruta fruta;
    Fruta2 fruta2;
    Fruta3 fruta3;
    int tam = 4;
    int c = 25, f = 77; //limites
    bool gameover = false;
    inline void genFruta(); //generar fruta
    inline void loop(); //while
    inline void tecla();
    inline void cfruta(); //comer fruta
    inline void muerte(); //muerte si pasa los limites o choca con su cuerpo
   
};
#endif