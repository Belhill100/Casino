#ifndef CASINO_GENSHIN_H
#define CASINO_GENSHIN_H

#include "Juego.h"
#include <ctime>

class Genshin:public Juego{
protected:
    float calcularResultado(float gonzosApostar) override;
public:
    float jugar(float gonzosApostar) override;
    virtual ~Genshin();
};

#endif //CASINO_GENSHIN_H
