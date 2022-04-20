#include <cstdlib>
#include <string>
#include <ctime>
#include "constantes.h"
#include "structs.h"
#include "menu.h"
using namespace  std;
//const static int ANCHO = 10;
//const static int ALTO = 10;
/*
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

void printearEnTxt(Tablero &tablero, string rutaSalida, int jugador){
    ofstream salida;
    salida.open(rutaSalida.c_str());

    // escribe el contenido del archivo
    salida << "Tablero jugador N°" << jugador << endl;

    for(int i = 0; i < ALTO; i++){
        for(int j = 0; j < ANCHO; j++){
            if(tablero.tablero1[i][j].estado == 0){
                salida << '"' << ' ' << '"';
            }
            else if(tablero.tablero1[i][j].estado == 1 && jugador == 1){
                salida << '"' << '1' << '"';
            }
            else if(tablero.tablero1[i][j].estado == 2 && jugador == 2){
                salida << '"' << '2' << '"';
            }
            else if(tablero.tablero1[i][j].estado == 3){
                salida << '"' << 'X' << '"';
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
        }
        cout << endl;
    }
    cout << endl;

    salida.close();
}

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

int validarInt(int numero, string mensaje){
    //valido los enteros del output (que se encuentre entre 0-9)
    do{
        cout << mensaje << endl;
        cin >> numero;
    }
    while(numero < 0 || numero > 9);
}

void atacarCasilla(Tablero &tablero, Jugador &jugador, int numJugador){
    //funcion para atacar una casilla que no se encuentre inactiva, no haya un soldado aliado o que no se encuentre fuera del mapa
    int posAlto = -1;
    int posAncho = -1;
    bool casillaInactiva = false;
    bool casillaAliada = false;

    do{
        cout << "Elija una casilla a atacar: " << endl;
        posAlto = validarInt(posAlto, "Altura: ");
        posAncho = validarInt(posAncho, "Ancho: ");

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

char preguntarMoverSoldado(char moverSoldadoBool){
    //validacion para que solo pueda ingresar Y/N
    moverSoldadoBool = ' ';

    while((moverSoldadoBool != 'Y') && (moverSoldadoBool != 'N')){
        cout << "Desea mover un soldado? Y/N" << endl;
        cin >> moverSoldadoBool;
    }

    return moverSoldadoBool;
}

void juego(Tablero &tablero, string ruta1, string ruta2){
    //JUEGO
    //reseteo el estado del tablero cada vez que se juega un partida
    for(int m = 0; m < 10; m++){
        for(int n = 0; n < 10; n++){
            tablero.tablero1[m][n].estado = 0;
        }
    }
    //inicializo la array que contiene a los 6 soldados -- los primeros 3 del jugador 1 los restantes del jugador 2
    Jugador jugador;
    jugador.soldado = new Soldado[6];
    jugador.numeroJug1 = 1;
    jugador.numeroJug2 = 2;
    asignarPosSoldado(jugador, tablero);
    *
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
     /
    //string archivoConSecuenciaj1 = "datos/tableroj1.txt";
    //string archivoConSecuenciaj2 = "datos/tableroj2.txt";
    bool juegoFuncionando = true;
    char moverSoldadoBool;

    printearEnTxt(tablero, ruta1, jugador.numeroJug1);
    printearEnTxt(tablero, ruta2, jugador.numeroJug2);

    while(juegoFuncionando){
        cout << "Empezando juego" << endl;
        cout << "Turno Jugador 1: " << endl;
        //jugador 1 empieza atacando casilla
        atacarCasilla(tablero, jugador, jugador.numeroJug1);
        //pregunto si quiere mover un soldado
        moverSoldadoBool = preguntarMoverSoldado(moverSoldadoBool);
        if(moverSoldadoBool == 'Y'){
            moverSoldado(jugador, tablero, jugador.numeroJug2);
        }
        //compruebo si hay soldados vivos
        juegoFuncionando = comprobarJuegoFinalizado(jugador, juegoFuncionando);
        //salteo el turno del jugador 2 si ya termino la partida
        if(juegoFuncionando){
            cout << "Turno Jugador 2: " << endl;
            atacarCasilla(tablero, jugador, jugador.numeroJug2);
            //pregunto si quiere mover un soldado
            moverSoldadoBool = preguntarMoverSoldado(moverSoldadoBool);
            if(moverSoldadoBool == 'Y'){
                moverSoldado(jugador, tablero, jugador.numeroJug2);
            }
            //compruebo si hay soldados vivos
            juegoFuncionando = comprobarJuegoFinalizado(jugador, juegoFuncionando);
        }
        printearEnTxt(tablero, ruta1, jugador.numeroJug1);
        printearEnTxt(tablero, ruta2, jugador.numeroJug2);
    }
    delete [] jugador.soldado; //elimino de la memoria heap el array dinamico
}

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
*/
void inicializarTablero(Tablero &tablero){
    //inicializo el tablero que es un array 2d dinámica (matriz dinamica)
    tablero.tablero1 = new Casilla*[ALTO];
    for(int i = 0; i < ALTO; i++){
        tablero.tablero1[i] = new Casilla[ANCHO];
    }
}

int main() {
    Tablero tablero;
    inicializarTablero(tablero);
    string archivoConSecuenciaj1 = "datos/tableroj1.txt";
    string archivoConSecuenciaj2 = "datos/tableroj2.txt";
    srand(time(NULL));
    menu(tablero, archivoConSecuenciaj1, archivoConSecuenciaj2);

    for(int i = 0; i < ALTO; i++){
        delete [] tablero.tablero1[i];
    }
    delete [] tablero.tablero1;

    return 0;
}