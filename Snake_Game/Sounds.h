#ifndef __SOUNDS_H__
#define __SOUNDS_H__

#include <SFML/Audio.hpp>
using namespace sf;
Music musica_fondo;
Music coin;
Music choque;
bool ReproducirMusica1() {
    while (!musica_fondo.openFromFile("mario-coin.wav")) {
        return false;
    }
    musica_fondo.play();
}
bool ReproducirMusica2() {
    while (!musica_fondo.openFromFile("choque.wav")) {
        return false;
    }
    musica_fondo.play();
}
bool ReproducirMusica3() {
    while (!musica_fondo.openFromFile("cascabel.wav")) {
        return false;
    }
    musica_fondo.play();
}
#endif