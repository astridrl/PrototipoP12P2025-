//Mejoras buscaminas - Examen parcial 2
//Documentacion por Astrid Fernanda Ruíz López
// Carnet: 9959 25 2976
// nombre del jugador, resultado obtenidO.
//Además contarà con tres oportunidades de jugar (si en caso le explota alguna mina) en un tablero de 4 x 4.
//Al final deberá desplegar los datos personales del jugador y el marcador obtenido (puntos
//acumulados durante el juego) y el tiempo que durò su juego.
#ifndef CONFIG_H
#define CONFIG_H

class Config
{
    public:
        //Se agregaron los parametros para los puntos por celda y para la recuccion
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero,
               int vidasTablero, int reduccionPuntos);
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);

        void menuConfiguracion();

        //Metodos para obtener y establecer las recucciones de puntos
        int getReduccionPuntos();
        void setReduccionPuntos(int reduccionPuntos);

    protected:

    private:
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
        //Valores de reduccion
        int reduccionPuntos;
};

#endif // CONFIG_H
