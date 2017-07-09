

#ifndef SISTEMA_H
#define SISTEMA_H
#include "Canciones.h"


class Sistema
{
    public:
        Sistema();
        virtual ~Sistema();

        void agregar(Canciones* _cancion);

        Canciones* visualizar_Orden();

        Canciones* cancion(int numero);

        bool repeticion(int numeroBool);

        void eliminar(int numero);

    protected:
    private:
        Canciones* PrimeraCancion;
        Canciones* UltimaCancion;
        Canciones* CancionActual;

};

#endif // SISTEMA_H
