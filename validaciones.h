//
// Created by Ignacio on 17/4/2022.
//

#ifndef TP1_VALIDACIONES_H
#define TP1_VALIDACIONES_H
#include <string>
#include "structs.h"
/*
 * Compruebo si la casilla en la que cae (altura-ancho) hay un soldado enemigo, si es el caso cambio el estado de la casilla a vacio
 * y elimino a los dos soldas
*/
void comprobarHayDosSoldados(int soldadoElegido, Jugador &jugador, Tablero &tablero, int posAlto, int posAncho, int numJugador);
/*
 * Compruebo si la casilla en la que cae (altura-ancho) hay un soldado aliado
*/
bool limiteTablero(bool caeLimiteTablero,int posAlto, int posAncho);
/*
 * Compruebo si la casilla en la que cae (altura-ancho) se encuentra fuera de las dimensiones del tablero (0-9)
*/
bool esCasillaAliada(Tablero &tablero, bool casAliada, int posAlto, int posAncho, int jugador);
/*
 * Compruebo si la casilla en la que cae (altura-ancho) esta inactiva
*/
bool esCasillaInactiva(Tablero &tablero, bool casInactiva, int posAlto, int posAncho);
/*
 * valido los enteros del output (que se encuentre entre 0-9)
*/
int validarInt(std::string mensaje);

#endif //TP1_VALIDACIONES_H
