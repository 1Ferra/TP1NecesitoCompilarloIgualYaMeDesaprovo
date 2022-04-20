//
// Created by Ignacio on 14/4/2022.
//

#ifndef TP1_MOVERSOLDADO_H
#define TP1_MOVERSOLDADO_H

/*
 * cambia el estado de la casilla cuando un soldado avanza a una posicion que previamente se encontraba vacia
*/
void cambiarEstadoCasillaJugador(int posAlto, int posAncho, Tablero &tablero, int numJugador, Jugador &jugador, int soldadoElegido);
/*
 * funcion que pregunta que soldado a elegir (dependiendo el jugador que sea) y pregunta en que manera mover ese soldado con
 * los comandos Q-W-E-A-D-Z-X-C, junto con las respectivas validaciones que impiden pisar un soldado aliado o una casilla inactiva
*/
void moverSoldado(Jugador &jugador, Tablero &tablero, int numJugador);

#endif //TP1_MOVERSOLDADO_H
