#ifndef CANCIONES_H
#define CANCIONES_H
#include <string>


class Canciones
{
    public:
        Canciones(std::string titulo, std::string autor,std::string duracion);
        virtual ~Canciones();

	std::string getTitulo()
	{
		return titulo;
	}
    std::string getAutor()
    {
		return autor;
	}
	std::string getDuracion()
	{
		return duracion;
	}

    protected:
    private:
        std::string titulo;
        std::string autor;
        std::string duracion;
        Canciones* siguiente;
        Canciones* anterior;
        friend class Sistema;
};

#endif // CANCIONES_H
