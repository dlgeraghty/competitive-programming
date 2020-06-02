
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
		Nodo * b = a->sig; 
		int eliminados = 0;

		while(a != nullptr && b != nullptr && a->sig != nullptr){

			b = a->sig;

			while(b->elem < a->elem){
				if(b->sig == nullptr){		//vamos a llegar al final
					a->sig = nullptr;
					this->ult = a;
					break;
				}else{
					a->sig = b->sig;
					b = b->sig;
				}
			}
			a = a->sig;

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
