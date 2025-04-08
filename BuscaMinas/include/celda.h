//Mejoras buscaminas - Examen parcial 2
//Documentacion por Astrid Fernanda Ruíz López
// Carnet: 9959 25 2976
// nombre del jugador, resultado obtenidO.
//Además contarà con tres oportunidades de jugar (si en caso le explota alguna mina) en un tablero de 4 x 4.
//Al final deberá desplegar los datos personales del jugador y el marcador obtenido (puntos
//acumulados durante el juego) y el tiempo que durò su juego.
#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023

class Celda
{
    public:
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
        bool setMina(bool estadoMina);
        bool getMina();
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();
        void imprimirCelda();
    protected:

    private:
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
