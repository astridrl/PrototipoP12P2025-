//Mejoras buscaminas - Examen parcial 2
//Documentacion por Astrid Fernanda Ru�z L�pez
// Carnet: 9959 25 2976
// nombre del jugador, resultado obtenidO.
//Adem�s contar� con tres oportunidades de jugar (si en caso le explota alguna mina) en un tablero de 4 x 4.
//Al final deber� desplegar los datos personales del jugador y el marcador obtenido (puntos
//acumulados durante el juego) y el tiempo que dur� su juego.
#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"

using namespace std;

//Integraci�n de vidas (Astrid)
int main()
{
    const int FILASTABLERO = 4;
    const int COLUMNASTABLERO = 4;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    //Valores predeterminados la reduccion, tambien agragados al constructor de Config
    const int REDUCCIONPUNTOS= 3;
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO, REDUCCIONPUNTOS);
    //Se agregaron las configuraciones de los puntos por celda y de la recuccion de puntos en el constructor Juego
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()),
                configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero(),configuracionJuego.getReduccionPuntos());

    //Mostrar la portada al inicio del programa
    juego.dibujarPortada("portada.txt");

    srand(getpid());
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2: //Agregu� el registro del usuario
            {
                string nombre; //variable
                cout << "\t\tIngrese su nombre de usuario: ";
                cin.ignore();
                getline(cin, nombre);

                if (nombre.empty()) {
                    nombre = "Invitado"; //si deja vacio el nombre se pondr� como invitado
                }
                juego.setUsuarioActual(nombre);

                //Agrege los puntos por celda y la reduccion de puntos
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()),
                                    configuracionJuego.getminasTablero(), configuracionJuego.getvidasTablero(),configuracionJuego.getReduccionPuntos());

                juegoTemporal.setUsuarioActual(nombre);
                juegoTemporal.iniciar();

                string resultado = juegoTemporal.jugadorGana() ? "Ganaste" : "Perdiste";
                cout << "\n\t" << nombre << ", " << resultado << " el Juego!\n";

                //Total  de jurgos ganados y perdidos
                cout << "\n\tTotal de juegos ganados: " << juego.obtenerVictorias() << endl;
                cout << "\tTotal de juegos perdidos: " << juego.obtenerPerdidas() << endl << endl;

                system("pause");
                break;
            }
        case 3: repetir = false;
                break;
        }
    } while (repetir);
    system("cls");
    return 0;
}

//mejorar las vidas, si tiene 3 que se cumplan las 3
