
#include "Canciones.h"

Canciones::Canciones(std::string _titulo,std::string _autor, std::string _duracion): siguiente(NULL), anterior(NULL)
{
    //ctor
    this->titulo = _titulo;
    this->autor = _autor;
    this->duracion = _duracion;
}

Canciones::~Canciones()
{
    //dtor
}

