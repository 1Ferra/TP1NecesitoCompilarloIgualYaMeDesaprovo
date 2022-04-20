//
// Created by Ignacio on 14/4/2022.
//

#ifndef TP1_ATACARCASILLA_H
#define TP1_ATACARCASILLA_H
#include "structs.h"

/*
 * Se consulta que casilla a atacar pidiendo la altura y el ancho (entre 0-9) mientras que no sea en una casilla inactiva
 * aliada o no traspase las dimensiones del tablero
*/
void atacarCasilla(Tablero &tablero, Jugador &jugador, int numJugador);

#endif //TP1_ATACARCASILLA_H
