#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int altura_max;

void recorrerArbol(int r, int & altura){
	for(int i = 0; i < r; i++){
		int x;
		cin >> x;
		//printf("visitando nodo con: %d hijos en la rama: %d altura actual: %d \n " , x, i, altura + 1);
		int ola = 1 + altura;
		altura_max = max(altura_max, ola);
		recorrerArbol(x, ola);
	}
}

int main(){

	int in;
	cin >> in;
	while(in--){
		int raiz;
		cin >> raiz;
		int altura = 0;
		altura_max = 0;
		recorrerArbol(raiz, altura);
		printf("%d\n", altura_max + 1);
	}

	return 0;
}
