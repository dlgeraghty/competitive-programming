
#include <iostream>
#include "horas.h"
#include "queue_eda.h"

using namespace std;

template <class T>
class customLista: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(){
		Nodo * i = this->prim;
		while(i != nullptr){
			cout << i->elem << " ";
			i = i->sig;
		}
		cout << "\n";
	}
	void eliminar(){

		Nodo * a = this->prim;
		Nodo * eliminar = a->sig;
		Nodo * b = nullptr; 
		int eliminados = 0;

		while(a != nullptr && eliminar != nullptr){

			b = eliminar->sig;
			if(b == nullptr){		//legamos a una situacion en la que solo hay 2 elementos
				a->sig = nullptr;
				this->ult = a;		//eliminamos el segundo de los elementos, el par
				eliminados++;		//aumentamos en 1 el numero de eleminados
				break;
			}else{
				a->sig = b;
				a = b;
				eliminados++;		
				eliminar = a->sig;
			}
		}

		this->nelems -= eliminados;
	}
};

bool resuelvecaso(){

	int x;
	cin >> x;
	if(x == 0)return false;

	customLista<horas> l;
	horas h;
	while(x--){
		cin >> h;
		l.push(h);
	}
	l.eliminar();
	l.print();

	return true;
}

int main(){
	while(resuelvecaso());

	return 0;
}
