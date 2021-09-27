#include "Genshin.h"

float Genshin::jugar(float gonzosApostar) {
    int opcion, cartaNueva;
    float gonzosResultado;
    numeroJugador = 1 + rand() % 10;
    numeroCasino = 1 + rand() % 10;
    cout << "El primer numero de la casa es: " << numeroCasino << endl;
    cout << "El primer numero de tuyo es: " << numeroJugador << endl;
    srand(time(NULL));
    do{
        cartaNueva = 1 + rand() % 10;
        cout << "Tu nuevo numero es: " << cartaNueva << endl;
        numeroJugador = cartaNueva + numeroJugador;
        cout << "El acumulado que llevas es: " << numeroJugador << endl;
        cout << "Introduzca la opcion que desee (1. Seguir jugando, 0. Parar): ";
        cin >> opcion;
    } while (opcion != 0);
    while (numeroCasino < 17){
        cartaNueva = 1 + rand() % 10;
        cout << "Tu nuevo numero es: " << cartaNueva << endl;
        numeroCasino = cartaNueva + numeroCasino;
        cout << "El acumulado que llevas es: " << numeroCasino << endl;
    }
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float Genshin::calcularResultado(float gonzosApostar) {
    if (numeroJugador < 21 && (21 < numeroCasino || numeroCasino > numeroJugador)){
        cout << "Ganaste" << endl;
        return 2*gonzosApostar;
    }
    else{
        cout << "Perdiste" << endl;
        return 0;
    }
}

Genshin::~Genshin() {

}


