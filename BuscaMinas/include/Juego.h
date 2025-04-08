//Mejoras buscaminas - Examen parcial 2
//Documentacion por Astrid Fernanda Ruíz López
// Carnet: 9959 25 2976
// nombre del jugador, resultado obtenidO.
//Además contarà con tres oportunidades de jugar (si en caso le explota alguna mina) en un tablero de 4 x 4.
//Al final deberá desplegar los datos personales del jugador y el marcador obtenido (puntos
//acumulados durante el juego) y el tiempo que durò su juego.
#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
#include <chrono> // Agregue Biblioteca para que permite medir intervalos de tiempo con precisión.(Dulce Reyes)
class Juego
{
private:
	Tablero tablero;
	int cantidadMinas;
	int vidas; //variable para las vidas
	std::string usuarioActual; //almacena el usuario actual

	int aleatorio_en_rango(int minimo, int maximo);
	int filaAleatoria();
	int columnaAleatoria();

	//Variables para el marcador
	int puntuacion;
    int puntosPorMina; //Puntos perdidos al descubrir una mina

    //Conteo de perdidas y victorias
    static int victorias;
    static int perdidas;

    // Agregue Variables para el cronómetro
    std::chrono::time_point<std::chrono::steady_clock> tiempoInicio, tiempoFin;

public:
    //Se modifico el constructor para agregar la reduccion por mina
    Juego(Tablero tablero, int cantidadMinas, int vidas, int puntosPorMina);
	void colocarMinasAleatoriamente();
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	bool jugadorGana();
	void iniciar();

	// Método de la portada que no está implementado en el juego.cpp
	void dibujarPortada(string nombreArchivo);

	//Integrar variables para registro de ususario
	bool registrarUsuario(const std::string& nombre);
	void mostrarMenuPrincipal();
	void setUsuarioActual(const std::string& nombre);
	std::string getUsuarioActual() const;
	void setNombreJugador(const std::string& nombre);

	//Obtener el total de perdidas y victorias
	int obtenerVictorias();
    int obtenerPerdidas();

};

#endif // JUEGO_H
