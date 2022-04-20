//
// Created by Ignacio on 17/4/2022.
//
#include "structs.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace  std;



void comprobarHayDosSoldados(int soldadoElegido, Jugador &jugador, Tablero &tablero, int posAlto, int posAncho, int numJugador){
    if((tablero.tablero1[posAlto][posAncho].estado == jugador.numeroJug2)  && (numJugador == jugador.numeroJug1)){
        cout << "Un soldado del jugador 1 cayo en una casilla con un soldado del jugador 2! Los dos soldados quedan eliminados!"<< endl;
        //jugador.soldado[soldadoElegido].estadoVivo = false;
        //filtro para saber que soldado era el que estaba antes en la casilla
        for(int k = 0; k < 6; k++){
            if((jugador.soldado[k].posicionAlto == posAlto) && (jugador.soldado[k].posicionAncho == posAncho)){
                jugador.soldado[k].estadoVivo = false;
            }
        }
        tablero.tablero1[posAlto][posAncho].estado = 0; //la casilla vuelve a esta vacia
    }
    else if((tablero.tablero1[posAlto][posAncho].estado == jugador.numeroJug1)  && (numJugador == jugador.numeroJug2)){
        cout << "Un soldado del jugador 2 cayo en una casilla con un soldado del jugador 1! Los dos soldados quedan eliminados!"<< endl;
        //jugador.soldado[soldadoElegido].estadoVivo = false;
        //filtro para saber que soldado era el que estaba antes en la casilla
        for(int k = 0; k < 6; k++){
            if((jugador.soldado[k].posicionAlto == posAlto) && (jugador.soldado[k].posicionAncho == posAncho)){
                jugador.soldado[k].estadoVivo = false;
            }
        }
        tablero.tablero1[posAlto][posAncho].estado = 0; //la casilla vuelve a esta vacia
    }
}

bool limiteTablero(bool caeLimiteTablero,int posAlto, int posAncho){
    //valida si no se encuentra fuera del tablero
    if((posAlto < 0) || (posAncho < 0) || (posAlto > 10) || (posAncho > 10)){
        caeLimiteTablero = true;
        cout << "Seleccione otra posicion, pasa el limite del tablero" << endl;
    }
    else{
        caeLimiteTablero = false;
    }
    return caeLimiteTablero;
}

bool esCasillaAliada(Tablero &tablero, bool casAliada, int posAlto, int posAncho, int jugador){
    //valida si la casilla tiene un soldado del mismo bando
    if(tablero.tablero1[posAlto][posAncho].estado == jugador){
        casAliada = true;
        cout << "Hay un soldado aliado en esta casilla" << endl;
    }
    else{
        casAliada = false;
    }
    return casAliada;
}

bool esCasillaInactiva(Tablero &tablero, bool casInactiva, int posAlto, int posAncho){
    if(tablero.tablero1[posAlto][posAncho].estado == 3){
        casInactiva = true;
        cout << "Casilla Inactiva" << endl;
    }
    else{
        casInactiva = false;
    }
    return casInactiva;
}

int validarInt(string mensaje){
    //valido los enteros del output (que se encuentre entre 0-9)
    stringstream objeto;
    string inputStr = "";
    int numeroInt;
    do{
        cout << mensaje << endl;
        cin >> inputStr;
    }
    //while(numeroInt < 0 || numeroInt > 9);
    while(inputStr != "0" && inputStr != "1" && inputStr != "2" && inputStr != "3" && inputStr != "4" && inputStr != "5" && inputStr != "6" && inputStr != "7" && inputStr != "8" && inputStr != "9");
    objeto  << inputStr;
    objeto  >> numeroInt;
    return numeroInt;
}