//
// Created by Ignacio on 14/4/2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include "constantes.h"
#include "structs.h"

using namespace std;

void printearEnTxt(Tablero &tablero, string rutaSalida, int jugador){
    ofstream salida;
    salida.open(rutaSalida.c_str(),ios_base::app);

    // escribe el contenido del archivo
    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO; j++){
            if(tablero.tablero1[i][j].estado == 0){
                salida << "'" << ' ' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 1 && jugador == 1){
                salida << "'" << '1' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 2 && jugador == 2){
                salida << "'" << '2' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 3){
                salida << "'" << 'X' << "'";
            }
            else{
                salida << "'" << ' ' << "'";
            }
        }
        salida << endl;
    }

    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO; j++){
            if(tablero.tablero1[i][j].estado == 0){
                cout << "'" << ' ' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 1 && jugador == 1){
                cout << "'" << '1' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 2 && jugador == 2){
                cout << "'" << '2' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 3){
                cout << "'" << 'X' << "'";
            }
            else{
                cout << "'" << ' ' << "'";
            }
        }
        cout << endl;
    }
    cout << endl;

    salida.close();
}

void limpiarEnTxt(Tablero &tablero, string rutaSalida, int jugador){
    ofstream salida;
    salida.open(rutaSalida.c_str());

    // escribe el contenido del archivo
    salida << "Tablero jugador N°" << jugador << endl;

    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO; j++){
            if(tablero.tablero1[i][j].estado == 0){
                salida << "'" << ' ' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 1 && jugador == 1){
                salida << "'" << '1' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 2 && jugador == 2){
                salida << "'" << '2' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 3){
                salida << "'" << 'X' << "'";
            }
            else{
                salida << "'" << ' ' << "'";
            }
        }
        salida << endl;
    }

    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO; j++){
            if(tablero.tablero1[i][j].estado == 0){
                cout << "'" << ' ' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 1 && jugador == 1){
                cout << "'" << '1' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 2 && jugador == 2){
                cout << "'" << '2' << "'";
            }
            else if(tablero.tablero1[i][j].estado == 3){
                cout << "'" << 'X' << "'";
            }
            else{
                cout << "'" << ' ' << "'";
            }
        }
        cout << endl;
    }
    cout << endl;

    salida.close();
}