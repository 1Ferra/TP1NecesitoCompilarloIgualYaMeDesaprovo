//
// Created by Ignacio on 14/4/2022.
//
#include "validaciones.h"
#include <iostream>
using namespace  std;

void atacarCasilla(Tablero &tablero, Jugador &jugador, int numJugador){
    //funcion para atacar una casilla que no se encuentre inactiva, no haya un soldado aliado o que no se encuentre fuera del mapa
    int posAlto;
    int posAncho;
    bool casillaInactiva = false;
    bool casillaAliada = false;

    do{
        cout << "Elija una casilla a atacar: " << endl;
        posAlto = validarInt("Altura: ");
        posAncho = validarInt("Ancho: ");

        casillaInactiva = esCasillaInactiva(tablero, casillaInactiva, posAlto, posAncho);
        casillaAliada = esCasillaAliada(tablero, casillaAliada, posAlto, posAncho, numJugador);
    }
    while(casillaInactiva || casillaAliada);

    cout << "Se ha disparado a la casilla en la Altura: " << posAlto << " y Ancho: " << posAncho << endl;

    if(tablero.tablero1[posAlto][posAncho].estado == 0){
        tablero.tablero1[posAlto][posAncho].estado = 3;
        cout << "Has disparado a una casilla sin Soldado" << endl;
    }
    else if((tablero.tablero1[posAlto][posAncho].estado == 1 && numJugador == 2) || (tablero.tablero1[posAlto][posAncho].estado == 2 && numJugador == 1)){
        for(int k = 0; k < 6; k++){
            if((jugador.soldado[k].posicionAlto == posAlto) && (jugador.soldado[k].posicionAncho == posAncho)){
                jugador.soldado[k].estadoVivo = false;
            }
        }
        cout << "Soldado eliminado!" << endl;
        tablero.tablero1[posAlto][posAncho].estado = 3;
    }
}