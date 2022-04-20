//
// Created by Ignacio on 14/4/2022.
//
#include "menu.h"
#include <iostream>
#include <string>
#include "menu.h"
#include "structs.h"
#include "juego.h"
using namespace std;

void menu(Tablero &tablero, string ruta1, string ruta2){
    //MENU
    bool menuFuncionando = true;
    string opcionMenuSeleccionada = "";

    while(opcionMenuSeleccionada != "2" && menuFuncionando){
        cout << "[1]Empezar juego" << endl;
        cout << "[2]Salir" << endl;
        cin >> opcionMenuSeleccionada;

        if(opcionMenuSeleccionada == "1"){
            cout << "|||INICIANDO JUEGO|||" << endl;
            juego(tablero, ruta1, ruta2);
        }
        else if(opcionMenuSeleccionada == "2"){
            cout << "Cerrando Programa..." << endl;
            menuFuncionando = false;
        }
        else{
            cout << "Opcion incorrecta" << endl;
        }
    }
}

