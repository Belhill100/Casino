#ifndef CASINO_GENSHIN_H
#define CASINO_GENSHIN_H

#include "Juego.h"
#include <ctime>

class Genshin : public Juego{
protected:
    float calcularResultado(float gonzosApostar) override;
public:
    virtual ~Genshin();
    float jugar(float gonzosApostar) override;
};

#endif //CASINO_GENSHIN_H
