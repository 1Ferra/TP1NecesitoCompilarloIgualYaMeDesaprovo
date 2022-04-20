//
// Created by Ignacio on 14/4/2022.
//
#include "structs.h"
#include "validaciones.h"
#include <iostream>
using namespace  std;

void cambiarEstadoCasillaJugador(int posAlto, int posAncho, Tablero &tablero, int numJugador, Jugador &jugador, int soldadoElegido){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if((posAlto == i) && (posAncho == j) && (numJugador == 1) && (jugador.soldado[soldadoElegido].estadoVivo)){
                tablero.tablero1[i][j].estado = 1; //cambio estado Casilla a J1
            }
            else if((posAlto == i) && (posAncho == j) &&(numJugador == 2) && (jugador.soldado[soldadoElegido].estadoVivo)){
                tablero.tablero1[i][j].estado = 2; //cambio estado Casilla a J2
            }
        }
    }
}

void moverSoldado(Jugador &jugador, Tablero &tablero, int numJugador) {
    int soldadoElegido = -1;
    char posElegida = ' ';
    bool caeCasillaInactiva = false;
    bool caeCasillaAliada = false;
    bool caeLimiteTablero = false;
    int posAlto = 0;
    int posAncho = 0;
    int antPosAlto = 0;
    int antPosAncho = 0;

    if(numJugador == 1){
        while((soldadoElegido > 2) || (soldadoElegido < 0) || (!jugador.soldado[soldadoElegido].estadoVivo)){
            cout << "Elija soldado a utilizar: " << endl;
            for(int i = 0; i < 3; i++){
                if(jugador.soldado[i].estadoVivo){
                    cout << "Soldado [" << i << "]: Alto: " << jugador.soldado[i].posicionAlto << " Ancho: " << jugador.soldado[i].posicionAncho << endl;
                }
                else{
                    cout << "Soldado [" << i << "]: Abatido " << endl;
                }
            }
            cin >> soldadoElegido;
        }
    }
    else if(numJugador == 2){
        while((soldadoElegido > 5) || (soldadoElegido < 3) || (!jugador.soldado[soldadoElegido].estadoVivo)){
            cout << "Elija soldado a utilizar: " << endl;
            for(int i = 3; i < 6; i++){
                if(jugador.soldado[i].estadoVivo){
                    cout << "Soldado [" << i << "]: Alto: " << jugador.soldado[i].posicionAlto << " Ancho: " << jugador.soldado[i].posicionAncho << endl;
                }
                else{
                    cout << "Soldado [" << i << "]: Abatido " << endl;
                }
            }
            cin >> soldadoElegido;
        }
    }

    while(((posElegida != 'Q') && (posElegida != 'W') && (posElegida != 'E') && (posElegida != 'A') && (posElegida != 'D') && (posElegida != 'Z') && (posElegida != 'X') && (posElegida != 'C')) || (caeCasillaInactiva) || (caeCasillaAliada) || (caeLimiteTablero)){
        cout << "Mover soldado: "<< soldadoElegido << endl;
        cout << "[Q]: Superior Izquierdo"<< endl;
        cout << "[W]: Superior Central"<< endl;
        cout << "[E]: Superior Derecho"<< endl;
        cout << "[A]: Central Izquierdo"<< endl;
        cout << "[D]: Central Derecho"<< endl;
        cout << "[Z]: Inferior Izquierdo"<< endl;
        cout << "[X]: Inferior Central"<< endl;
        cout << "[C]: Inferior Derecha"<< endl;
        cin >> posElegida;//VALIDAR BIEN

        antPosAlto = jugador.soldado[soldadoElegido].posicionAlto;
        antPosAncho = jugador.soldado[soldadoElegido].posicionAncho;

        if(posElegida == 'Q'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto -1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho -1;
        }
        else if(posElegida == 'W'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto -1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho;
        }
        else if(posElegida == 'E'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto -1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho +1;
        }
        else if(posElegida == 'A'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho =-1;
        }
        else if(posElegida == 'D'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho +1;
        }
        else if(posElegida == 'Z'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto +1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho -1;
        }
        else if(posElegida == 'X'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto +1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho;
        }
        else if(posElegida == 'C'){
            posAlto = jugador.soldado[soldadoElegido].posicionAlto +1;
            posAncho = jugador.soldado[soldadoElegido].posicionAncho +1;
        }

        caeLimiteTablero = limiteTablero(caeLimiteTablero, posAlto, posAncho);
        if(!caeLimiteTablero){
            caeCasillaInactiva = esCasillaInactiva(tablero ,caeCasillaInactiva, posAlto, posAncho);
            caeCasillaAliada = esCasillaAliada(tablero, caeCasillaAliada, posAlto, posAncho, numJugador);
        }
    }

    jugador.soldado[soldadoElegido].posicionAlto = posAlto;
    jugador.soldado[soldadoElegido].posicionAncho = posAncho;
    tablero.tablero1[antPosAlto][antPosAncho].estado = 0;
    //cambiarEstadoCasillaJugador(soldadoElegido, soldadosTotal, tablero, jugador);
    comprobarHayDosSoldados(soldadoElegido, jugador, tablero, posAlto, posAncho, numJugador);
    cambiarEstadoCasillaJugador(posAlto, posAncho, tablero, numJugador, jugador, soldadoElegido);
}