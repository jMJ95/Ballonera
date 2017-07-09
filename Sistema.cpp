#include <iostream>
#include "Sistema.h"

Sistema::Sistema():PrimeraCancion(NULL), UltimaCancion(NULL), CancionActual(NULL){

}

Sistema::~Sistema(){

}

/*
aqui se crea el metodo para agregar las canciones
*/
void Sistema::agregar(Canciones* _cancion){
    if(PrimeraCancion == NULL){
        PrimeraCancion = _cancion;
        CancionActual = _cancion;
        UltimaCancion = _cancion;
    }else{
        Canciones* temporal=UltimaCancion;
        temporal->siguiente=_cancion;
        UltimaCancion=_cancion;
        UltimaCancion=_cancion;
        UltimaCancion->anterior = temporal;
        UltimaCancion->siguiente = PrimeraCancion;
        UltimaCancion->anterior = _cancion;

    }
    std::cout<<"La Cancion a sido agregada exitosamente"<<std::endl;

}

/*
    Esto es para visualizar las canciones

*/
Canciones* Sistema::visualizar_Orden(){
    int orden = 1;
    if(PrimeraCancion !=NULL){
            std::cout<<" Lista de Canciones"<<std::endl;
            Canciones* uno = PrimeraCancion;
            while(uno != NULL){
                std::cout<<orden<<"- "<<uno->titulo<<", "<<uno->autor<<", "<<uno->duracion<<std::endl;
                orden++;
                uno = uno->siguiente;
                if(PrimeraCancion->titulo == uno->titulo){
                    return NULL;
                }

            }
    }else{
        std::cout<<"No hay cancion en la lista."<<std::endl;
    }
    return NULL;
}
/*

Para seleccionar las canciones (anterior, actual ,proximo )
*/
Canciones* Sistema::cancion(int numero)
{
    if(PrimeraCancion == NULL)
    {
        std::cout << "No hay canciones en lista." << std::endl;
        return NULL;
    }else
    {

        switch (numero)
        {
        case 1:
            //Reproducira la cancion actual que es la primera

            if(PrimeraCancion != NULL)
            {
                std::cout << "Cancion Actual: " << std::endl;
                std::cout << CancionActual->getTitulo() << ", " << CancionActual->getAutor() << " " << CancionActual->getDuracion() << std::endl;
                return CancionActual;

            }
            else
            {
                std::cout << "No existen canciones Actuales." << std::endl;
            }
            break;
        case 2:
            //Al seleccionar el 2 resultara la cancion siguiente
            CancionActual = CancionActual->siguiente;
            if(CancionActual != NULL)
            {
                std::cout << "Proxima cancion: " << std::endl;
                std::cout << CancionActual->getTitulo() << ", " << CancionActual->getAutor() << " " << CancionActual->getDuracion() << std::endl;
                return CancionActual;
            }
            else
            {
                std::cout << "No existen canciones Proximas. Repeticion desactivada." << std::endl;
            }
            break;
        case 3:
            //Si selecciona el 3 retornara a la cancion anterior
            CancionActual = CancionActual->anterior;
            if(CancionActual != NULL)
            {
                std::cout << "Cancion Anterior: " << std::endl;
                std::cout << CancionActual->getTitulo() << ", " << CancionActual->getAutor() << " " << CancionActual->getDuracion() << std::endl;
                return CancionActual;
            }
            else
            {
                std::cout << "No existen canciones anteriores." << std::endl;
            }
            break;
        default:
            std::cout << "Esta opcion no existe." << std::endl;
            break;
        }

     }
    return NULL;
}

//-----------------------------------------------------------------------------------
//esta es la funcion que activa la repeticion (Agrega o elimina el siguiente a la ultima cancion)
bool Sistema::repeticion(int numeroBool)
{
    bool activo;
    if(PrimeraCancion == NULL)
    {
        std::cout << "No hay canciones en lista." << std::endl;
    }else
    {
        switch(numeroBool)
        {
            //Al seleccionar el 1 retornara la opcion repeticion
        case 1:
            UltimaCancion->siguiente = PrimeraCancion;
            activo = true;
            return activo;
            break;

            //Spara desactivar la opcion repeticion
        case 2:
            UltimaCancion->siguiente = NULL;
            activo = false;
            return activo;
            break;

        default:
            std::cout << "Esta opcion no existe." << std::endl;
            break;
        }
    }

    return NULL;
}


//-----------------------------------------------------------------------------------
//Este es para eliminar una cancion
void Sistema::eliminar(int numero)
{
    int orden = 1;
    std::string opcion , datos;
    if (PrimeraCancion != NULL)
    {
        Canciones* u = PrimeraCancion;
        while (u != NULL)
        {

            if(numero == orden)
            {
                std::cout << "¿Confirma que desea eliminar: "<< u->titulo << ", " << u->autor << " " << u->duracion << "? (S/N)" << std::endl;
                datos = u->titulo + ", " + u->autor + " " + u->duracion;
                std::cin >> opcion;
                if(opcion == "S")
                {
                    /*Aqui lo que se hace es que se sustituyen los campos donde el puntero
                    que se eliminara existe.*/
                    Canciones* temporal = u->siguiente;
                    Canciones* temporal2 = u->anterior;
                    temporal2->siguiente = temporal;
                    temporal->anterior = temporal2;

                    delete (u);

                    std::cout << datos << " ha sido eliminada con exito" << std::endl;
                    return;
                }
                else if(opcion == "N")
                {
                    std::cout << "Eligio no eliminar esta cancion." << std::endl;
                    return;
                }
            }

            orden++;
            u = u->siguiente;
        }
    }else
    {
        std::cout << "No hay canciones en lista." << std::endl;
    }


}



