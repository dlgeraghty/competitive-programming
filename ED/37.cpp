
#include <iostream>
#include "37.h"

using namespace std;

bool resuelvecaso(){

	string a,b,c;
	int x;

	cin >> a;
	if(!cin)
		return false;

	autoescuela H;

	while(a != "FIN"){
		try{
			if(a == "alta"){
				cin >> b >> c;
				H.alta(b,c);
			}
			else if(a == "es_alumno"){
				cin >> b >> c;
				if(H.es_alumno(b,c))
					printf("%s es alumno de %s\n", b.c_str(), c.c_str());
				else
					printf("%s no es alumno de %s\n", b.c_str(), c.c_str());
			}
			else if(a == "examen"){
				cin >> b >> x;
				printf("Alumnos de %s a examen:\n", b.c_str());
				for(string i: H.examen(b, x))
					printf("%s\n", i.c_str());
			}
			else if(a == "puntuacion"){
				cin >> b;
				int i = H.puntuacion(b);
				printf("Puntuacion de %s: %d\n", b.c_str(), i);
			}
			else if(a == "aprobar"){
				cin >> b;
				H.aprobar(b);
			}
			else if(a == "actualizar"){
				cin >> b >> x;
				H.actualizar(b, x);
			}
		}catch(domain_error e){
			cout << e.what() << "\n";
		
		}
		cin >> a;
	}
	printf("---\n");
	return true;
}

int main(){

	while(resuelvecaso());

	return 0;

}
