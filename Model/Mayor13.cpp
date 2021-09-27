#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar){
    int opcion;
    float gonzosResultado;
    srand(time(NULL));
    numeroJugador = 1 + rand() % 13;
    cout << "El numero que sacaste fue: " << numeroJugador << endl;
    cout << "Introduzca la opcion que desee (1. Jugar, 2. Rendirse): ";
    cin >> opcion;
    if (opcion == 1){
        return gonzosApostar/2;
    }
    numeroCasino = 1 + rand() % 13;
    cout << "El numero que saco el casino fue: " << numeroCasino << endl;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if (numeroJugador > numeroCasino){
        cout << "Ganaste" << endl;
        return 2*gonzosApostar;
    }
    else{
        cout << "Perdiste" << endl;
        return 0;
    }
}

Mayor13::~Mayor13() {

}

