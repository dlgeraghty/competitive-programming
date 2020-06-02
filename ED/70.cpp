
#include <iostream>
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
	void intercambia(){

		Nodo * ant = nullptr;
		Nodo * a = this->prim;
		Nodo * b = a->sig;
		Nodo * sig = nullptr;

		while(a != nullptr){
			b = a->sig;
			if(b == nullptr) break;
			sig = b->sig;

			a->sig = sig;
			b->sig = a;
			if(ant != nullptr)
				ant->sig = b;
			else
				this->prim = b;

			ant = a;
			a = sig;
		}

		if(b == nullptr)
			this->ult = a;
		else 
			this->ult = b;
	
	}
};

bool resuelvecaso(){

	int x, i;
	cin >> x;
	if(x == 0)return false;

	customLista<int> l;
	while(x--){
		cin >> i;
		l.push(i);
	}
	l.intercambia();
	l.print();

	return true;
}

int main(){
	while(resuelvecaso());

	return 0;
}
