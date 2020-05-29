#ifndef fecha_h
#define fecha_h

#include <iostream>

using namespace std;

class fecha{
public:
	int dia;
	int hora;
	int minuto;

	friend istream &operator>>(istream &input, fecha & f){
		input >> f.dia >> f.hora;
	       	input.ignore();
		input >> f.minuto;
		return input;
	}

};

#endif
