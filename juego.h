//
// Created by Ignacio on 14/4/2022.
//

#ifndef TP1_JUEGO_H
#define TP1_JUEGO_H
#include "structs.h"
#include <string>

/*
 * Asigna posiciones aleatorias de los 6 soldados (alto-ancho) sin que se solapen entre si
*/
void asignarPosSoldado(Jugador &jugador, Tablero &tablero);
/*
 * Compruebo si quedan soldados vivos en alguno de los bandos dependiendo del caso gana el jugador con soldados vivos,
 * si los dos jugadores no tienen soldados se da por empata la partida
*/
bool comprobarJuegoFinalizado(Jugador &jugador, bool juegoFunc);
/*
 *  Consulto al usuario si quiere mover un soldado (Y/N)
*/
std::string preguntarMoverSoldado(std::string moverSoldadoBool);
/*
 * En esta funcion se incializa el array con los 6 soldados y sus respectivas posiciones, los turnos de cada jugador con sus
 * respectivos inputs (atacar una casilla o mover un soldado)
*/
void juego(Tablero &tablero, std::string ruta1, std::string ruta2);

#endif //TP1_JUEGO_H
