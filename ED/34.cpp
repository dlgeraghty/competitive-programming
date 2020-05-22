#include <iostream>
#include "34.h"

using namespace std;

bool resuelveCaso(){

	string s;
	int n;

	cin >> s;
	if(!cin)
		return false;

	carnet_puntos d;

	while(s != "FIN"){
		try{
			if(s == "nuevo"){
				cin >> s;
				d.nuevo(s);
			}
			else if(s == "quitar"){
				cin >> s >> n;
				d.quitar(s, n);
			}
			else if(s == "consultar"){
				cin >> s;
				int x = d.consultar(s); //para que produzca la excepcion si es necesario
				printf("Puntos de %s: %d\n", s.c_str(), x);
			}
			else if(s == "cuantos_con_puntos"){
				cin >> n;
				int x = d.cuantos_con_puntos(n);
				printf("Con %d puntos hay %d\n", n, x);
			}
		}catch(domain_error e){
			cout << "ERROR: " << e.what() << '\n';
		}
		cin >> s;

	}
	cout << "---\n";
	return true;
}

int main(){

	while(resuelveCaso());

	return 0;
}
