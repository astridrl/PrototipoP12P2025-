//Mejoras buscaminas - Examen parcial 2
//Documentacion por Astrid Fernanda Ruíz López
// Carnet: 9959 25 2976
// nombre del jugador, resultado obtenidO.
//Además contarà con tres oportunidades de jugar (si en caso le explota alguna mina) en un tablero de 4 x 4.
//Al final deberá desplegar los datos personales del jugador y el marcador obtenido (puntos
//acumulados durante el juego) y el tiempo que durò su juego.
#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;


class Tablero
{
    public:
        Tablero();
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);
        int getAlturaTablero();
        int setAlturaTablero(int alturaTablero);
        int getAnchoTablero();
        int setAnchoTablero(int anchoTablero);
        bool getModoDesarrollador();
        bool setModoDesarrollador(bool modoDesarrollador);
        void imprimirSeparadorEncabezado();
        void imprimirSeparadorFilas();
        void imprimirEncabezado();
        void imprimir();
        bool colocarMina(int x, int y);
        bool descubrirMina(int x, int y);
        int contarCeldasSinMinasYSinDescubrir();

        //Se agrego un metodo para el valor de la celda
        int getMinasCercanas(int fila, int columna);


    protected:

    private:
        int alturaTablero, anchoTablero;
        bool modoDesarrollador;
        vector<vector<Celda> > contenidoTablero;

        string getRepresentacionMina(int x, int y);
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
