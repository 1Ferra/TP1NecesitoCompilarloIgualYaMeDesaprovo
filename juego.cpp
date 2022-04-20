//
// Created by Ignacio on 14/4/2022.
//
#include "atacarCasilla.h"
#include "moverSoldado.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "structs.h"
#include "printearTablero.h"
using namespace  std;

void asignarPosSoldado(Jugador &jugador, Tablero &tablero){
    //asigno aleatoriamente la casilla de casa soldado (alto y ancho)
    int posicionRandomAncho = 0;
    int posicionRandomAlto = 0;
    for(int i = 0; i < 6; i++){
        posicionRandomAncho = rand() %10;
        while(posicionRandomAncho == jugador.soldado[i].posicionAncho){
            posicionRandomAncho = rand() %10;
        }
        jugador.soldado[i].posicionAncho = posicionRandomAncho;
        posicionRandomAlto = rand() %10;
        while(posicionRandomAlto == jugador.soldado[i].posicionAlto){
            posicionRandomAlto = rand() %10;
        }
        jugador.soldado[i].posicionAlto = posicionRandomAlto;
        if((i >= 0 && i <= 2)){
            tablero.tablero1[posicionRandomAlto][posicionRandomAncho].estado = 1;
        }
        else if((i >= 3 && i <= 5)){
            tablero.tablero1[posicionRandomAlto][posicionRandomAncho].estado = 2;
        }
    }
}

bool comprobarJuegoFinalizado(Jugador &jugador, bool juegoFunc){
    //comprueba si todos los soldados de un bando o simultaneos han quedado abatidos, dependiendo el caso se le dara la victoria al respectivo ganador o sera un empate
    if(!jugador.soldado[0].estadoVivo && !jugador.soldado[1].estadoVivo && !jugador.soldado[2].estadoVivo && !jugador.soldado[3].estadoVivo && !jugador.soldado[4].estadoVivo && !jugador.soldado[5].estadoVivo){
        juegoFunc = false;
        cout << "Empate, no quedan soldado en ninguno de los bandos." << endl;
    }
    else if(!jugador.soldado[0].estadoVivo && !jugador.soldado[1].estadoVivo && !jugador.soldado[2].estadoVivo){
        juegoFunc = false;
        cout << "El Jugador 1 no tiene mas soldados, Gana el Jugador 2!" << endl;
    }
    else if(!jugador.soldado[3].estadoVivo && !jugador.soldado[4].estadoVivo && !jugador.soldado[5].estadoVivo){
        juegoFunc = false;
        cout << "El Jugador 2 no tiene mas soldados, Gana el Jugador 1!" << endl;
    }
    return juegoFunc;
}


string preguntarMoverSoldado(string moverSoldadoBool){
    //validacion para que solo pueda ingresar Y/N
    moverSoldadoBool = ' ';

    while((moverSoldadoBool != "Y") && (moverSoldadoBool != "N")){
        cout << "Desea mover un soldado? Y/N" << endl;
        cin >> moverSoldadoBool;
    }

    return moverSoldadoBool;
}

void juego(Tablero &tablero, string ruta1, string ruta2){
    //JUEGO
    //Soldado jug1_1, jug1_2, jug1_3, jug2_1, jug2_2, jug2_3;
    //Soldado soldadosTotales[6] = {jug1_1, jug1_2, jug1_3, jug2_1, jug2_2, jug2_3};
    for(int m = 0; m < 10; m++){
        for(int n = 0; n < 10; n++){
            tablero.tablero1[m][n].estado = 0;
        }
    }
    Jugador jugador;
    jugador.soldado = new Soldado[6];
    jugador.numeroJug1 = 1;
    jugador.numeroJug2 = 2;
    asignarPosSoldado(jugador, tablero);
    /*
    jugador.soldado[0].posicionAlto = 0;
    jugador.soldado[0].posicionAncho = 1;
    jugador.soldado[1].posicionAlto = 0;
    jugador.soldado[1].posicionAncho = 2;
    jugador.soldado[2].posicionAlto = 0;
    jugador.soldado[2].posicionAncho = 3;
    jugador.soldado[3].posicionAlto = 1;
    jugador.soldado[3].posicionAncho = 1;
    jugador.soldado[4].posicionAlto = 1;
    jugador.soldado[4].posicionAncho = 2;
    jugador.soldado[5].posicionAlto = 1;
    jugador.soldado[5].posicionAncho = 3;
    tablero.tablero1[0][1].estado = 1;
    tablero.tablero1[0][2].estado = 1;
    tablero.tablero1[0][3].estado = 1;
    tablero.tablero1[1][1].estado = 2;
    tablero.tablero1[1][2].estado = 2;
    tablero.tablero1[1][3].estado = 2;
    */
    //string archivoConSecuenciaj1 = "datos/tableroj1.txt";
    //string archivoConSecuenciaj2 = "datos/tableroj2.txt";
    bool juegoFuncionando = true;
    string moverSoldadoBool;

    limpiarEnTxt(tablero, ruta1, jugador.numeroJug1);
    limpiarEnTxt(tablero, ruta2, jugador.numeroJug2);

    while(juegoFuncionando){
        cout << "Empezando juego" << endl;
        cout << "Turno Jugador 1: " << endl;
        atacarCasilla(tablero, jugador, jugador.numeroJug1);

        moverSoldadoBool = preguntarMoverSoldado(moverSoldadoBool);
        if(moverSoldadoBool == "Y"){
            moverSoldado(jugador, tablero, jugador.numeroJug2);
        }

        juegoFuncionando = comprobarJuegoFinalizado(jugador, juegoFuncionando);

        if(juegoFuncionando){
            cout << "Turno Jugador 2: " << endl;
            atacarCasilla(tablero, jugador, jugador.numeroJug2);

            moverSoldadoBool = preguntarMoverSoldado(moverSoldadoBool);
            if(moverSoldadoBool == "Y"){
                moverSoldado(jugador, tablero, jugador.numeroJug2);
            }

            juegoFuncionando = comprobarJuegoFinalizado(jugador, juegoFuncionando);
        }
        printearEnTxt(tablero, ruta1, jugador.numeroJug1);
        printearEnTxt(tablero, ruta2, jugador.numeroJug2);
    }
    delete [] jugador.soldado;
}