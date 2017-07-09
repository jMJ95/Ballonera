#include <iostream>
#include <windows.h>
#include "Sistema.h"

using namespace std;

int main()
{
    {
    string menuOpcion, titulo, autor, duracion;
    int opcionOtros;
    Sistema* objeto = new Sistema();

    do
    {
        cout << "Bienvenidos al sistema de Bellonera" << endl;
        cout << "Elija una opcion" << endl;
        cout << "1- Agregar nueva cancion " << endl;
        cout << "2- Visualizar canciones " << endl;
        cout << "3- Mostrar cancion actual " << endl;
        cout << "4- Proxima Cancion " << endl;
        cout << "5- Cancion Anterior " << endl;
        cout << "6- Activar Repeticion en lista" << endl;
        cout << "7- Eliminar " << endl;
        cout << "8- Salir " << endl;
        cin >> menuOpcion;

        //para agrega a la lista
        if (menuOpcion == "1")
        {
            cout << "Agregar cancion" << endl;
            cout << "Ingresar titulo: ";
            cin >> titulo;
            cout << "Ingresar artista: ";
            cin >> autor;
            cout << "Formato (horas:minutos:segundos) 1:45:34 \n Ingresar duracion: ";
            cin >> duracion;
            objeto->agregar(new Canciones(titulo,autor,duracion));
            system("pause");
            system("cls");
        }

        //para ver  la lista
        else if (menuOpcion == "2")
        {
            objeto->visualizar_Orden();
            system("pause");
            system("cls");
        }

        //OPCION CANCION ACTUAL
        else if (menuOpcion == "3")
        {
            objeto->cancion(1);
            system("pause");
            system("cls");


        }

        //OPCION CANCION PROXIMA
        else if (menuOpcion == "4")
        {
            objeto->cancion(2);
            system("pause");
            system("cls");
        }

        //OPCION CANCION ANTERIOR
        else if (menuOpcion == "5")
        {
            objeto->cancion(3);

            system("pause");
            system("cls");
        }

        //OPCION PARA ACTIVAR O DESACTIVAR REPETICION
        else if (menuOpcion == "6")
        {
            cout << "¿Desea activar o desactivas la repeticion? \n1-Si. \n2-No." << endl;
            cin >> opcionOtros;
            if(objeto->repeticion(opcionOtros))
            {
                cout << "Repeticion en lista activado" << endl;
            }
            else
            {
                cout << "Repeticion en lista inactiva" << endl;
            }

            system("pause");
            system("cls");
        }

        //OPCION PARA ELIMINAR UNA CANCION
        else if (menuOpcion == "7")
        {
            objeto->visualizar_Orden();
            cin >> opcionOtros;
            objeto->eliminar(opcionOtros);
            system("pause");
            system("cls");
        }

        //SI LA OPCION ES 8 EL SISTEMA SALDRA DE INMEDIATO
        else if(menuOpcion == "8")
        {
            cout << "Saliendo del sistem...." << endl;
            return 0;
        }

        else
        {
            cout << "Esta opcion no existe. Intente de nuevo." << endl;
            system("pause");
            system("cls");
        }

    }while(menuOpcion != "8");

    return 0;

}
}
