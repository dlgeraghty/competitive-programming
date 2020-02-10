#ifndef PELICULA_H
#define PELICULA_H

#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<string>

#include "horas.h"

class pelicula{
private:
	horas comienzo;
	horas fin;
	std::string nombre;
public:
	pelicula(horas c, horas f, std::string s){
		comienzo = c; fin = f; nombre = s;
	}

	bool operator<(pelicula const & h) const {
		if(fin == h.fin)
			return nombre < h.nombre;
		else
			return fin < h.fin;
	}


	void print(std::ostream& o = std::cout) const {
		o << fin << " " << nombre << std::endl;
	}

};

inline std::ostream & operator<<(std::ostream & salida, pelicula const&h){
	h.print(salida);
	return salida;
}
#endif
