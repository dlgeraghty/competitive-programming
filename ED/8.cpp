
#include <iostream>
#include "deque_eda.h"

using namespace std;

template <class T>
class ListaDuplica: public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void print() const{
		Nodo * prim = this->fantasma->sig;
		Nodo * ult = this->fantasma;
		Nodo * mostrar = prim;
		while(mostrar != ult){
			cout << mostrar->elem << " ";
			mostrar = mostrar->sig;
		}
	}
	void duplicar(){
		Nodo * prim = this->fantasma->sig;
		Nodo * ult = this->fantasma;
		Nodo *p = prim;
		while(p != nullptr && p != ult){
			Nodo * sig = p->sig;
			Nodo * aux = new Nodo(p->elem, p, sig); 
			p->sig = aux;
			sig->ant = aux;
			aux->ant = p;
			p = sig;	//actualizar para la siguiente vuelta
		}
		this->nelems *= 2;
	}
};
int main(){



	int in;
	while(cin >> in ){
		if(in != 0){
			ListaDuplica<int> q;
			q.push_back(in);
			while(cin >> in && in!= 0) q.push_back(in);
			q.duplicar();
			q.print();
		}
		cout << endl;
	}

	return 0;
}
