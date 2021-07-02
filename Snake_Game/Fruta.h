#ifndef __FRUTA_H__
#define __FRUTA_H__
#include "Recursos.h"
#include <iostream>
using namespace std;

class Fruta {
public:
    int x, y;
    char cuerpo;
};
class Fruta2 : public Fruta {
};
class Fruta3 : public Fruta {
};

#endif