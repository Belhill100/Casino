
#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout << "Inicialice casino";
    jugadoresMap.insert({1,new Jugador(1,"Pedro rodriguez", 500)});

    // Inicia los juegos disponibles y los agrega al mapa de juegos
    Mayor13 * juego1 = new Mayor13();
    juegosDisponibles.push_back(juego1);
    DosColores * juego2 = new DosColores();
    juegosDisponibles.push_back(juego2);
    Genshin * juego3 = new Genshin();
    juegosDisponibles.push_back(juego3);
}

void Casino::agregarJugador(long id, string nombreJugador, double dinero) {
    float cantidadGonzos;
    // Se agrega jugador solo si no existe con anticipacion
    if (!verExisteJugador(id)){
        cantidadGonzos = convertirPesosAGonzos(dinero);
        Jugador * pJugador = new Jugador (id, nombreJugador, cantidadGonzos);
        jugadoresMap.insert({pJugador->getId(), pJugador});

    }
    else{
        throw std::domain_error("La identificacion ya existe\n");
    }
}

bool Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    int posJuego;
    float gonzosGanados;
    if (gonzosApostar < 1 ){
        throw std::domain_error("Debe apostar al menos 1 gonzo\n");
    }
    if (verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > juegosDisponibles.size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador, gonzosApostar)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    posJuego = idJuego - 1;
    Juego * pJuegoAJugar = juegosDisponibles.at(idJuego-1);
    Jugador * pJugador = jugadoresMap[idJugador];
    gonzosGanados = pJuegoAJugar->jugar(gonzosApostar) - gonzosApostar;
    pJugador->actualizarGonzos(gonzosGanados);
    pJugador->aumentarJuegos();

    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    return(gonzosGanados >= 0);
}

void Casino::verInfoJugador(long idJugador){
    throw std::logic_error("Metodo por implementar");
}

bool Casino::verPuedeContinuar(int idJugador, float gonzosApostar) {
    throw std::logic_error("Metodo por implementar");

}

void Casino::retirarJugador(long idJugador) {
    throw std::logic_error("Metodo por implementar");

}

void Casino::recargarGonzos(long idJugador) {
    throw std::logic_error("Metodo por implementar");
}



bool Casino::verExisteJugador(long id) {
    for (map<long, Jugador*>::iterator jugador = jugadoresMap.begin(); jugador != jugadoresMap.end(); jugador++){
        if (jugador->first == id){
            return true;
        }
    }
    return false;
}

double Casino::convertirPesosAGonzos(double dinero) {
    return (dinero / 100);
}


Casino::~Casino() {
    cout << "Llame al destructor de casino \n";
    // Se libera la memoria del jugadores y de juegos
    for(map<long, Jugador*>::iterator it = jugadoresMap.begin(); it != jugadoresMap.end(); it++)
    {
        Jugador * jugadorTemp = jugadoresMap[it->first];
        delete jugadorTemp;
    }

    for(int i=0; i< juegosDisponibles.size(); i++)
    {
        Juego * juegoTemp = juegosDisponibles.at(i);
        delete juegoTemp;
    }
}