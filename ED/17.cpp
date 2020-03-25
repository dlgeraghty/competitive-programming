#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recorrerArbol(int r){
	int maxh = 0;
	for(int i = 0; i < r; i++){
		int x;
		cin >> x;
		//printf("visitando nodo con: %d hijos en la rama: %d altura actual:\n " , x, i);
		int local = recorrerArbol(x);
		if(local > maxh) maxh = local;
	}
	return maxh+1;
}

int main(){

	int in;
	cin >> in;
	while(in--){
		int raiz;
		cin >> raiz;
		int ola = recorrerArbol(raiz);
		cout << ola << endl;
	}

	return 0;
}
