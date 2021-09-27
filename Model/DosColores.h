
#ifndef CASINO_DOSCOLORES_H
#define CASINO_DOSCOLORES_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class DosColores:public Juego {

protected:
    int colorJugador;
    int colorCasino;
    float calcularResultado(float gonzosApostar) override;

public:
    float jugar(float gonzosApostar) override;
    virtual ~DosColores();

};


#endif //CASINO_DOSCOLORES_H
