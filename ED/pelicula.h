#ifndef PELICULA_H
#define PELICULA_H

#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<string>

class pelicula{
private:
	horas comienzo;
	horas fin;
	string nombre;
public:
	pelicula(horas c, horas f, string s){
		comienzo = c; fin = f; nombre = s;
	}

};

#endif
