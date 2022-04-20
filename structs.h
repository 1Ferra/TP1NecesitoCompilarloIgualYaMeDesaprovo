//
// Created by Ignacio on 19/4/2022.
//

#ifndef TP1_STRUCTS_H
#define TP1_STRUCTS_H

typedef struct{
    int estado = 0;
} Casilla;
//Casilla.estado --- [0] vacio, [1] j1, [2] j2,[3] inactivo

typedef struct{
    Casilla** tablero1;
} Tablero;

typedef struct{
    int posicionAncho;
    int posicionAlto;
    bool estadoVivo = true;
} Soldado;

typedef struct{
    Soldado* soldado;
    int numeroJug1;
    int numeroJug2;
} Jugador;

#endif //TP1_STRUCTS_H
