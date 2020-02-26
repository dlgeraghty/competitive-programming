
#include <iostream>
#include "queue.h"

using namespace std;

template <class T>
class ListaDuplica: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print() const{
		Nodo * mostrar = this->prim;
		for(int i = 0; i < this->nelems; i++){
			cout << mostrar->elem << " ";
			mostrar = mostrar->sig;
		}
	}
	void duplicar(){
		Nodo *p = this->prim;
		while(p != nullptr){
		p->sig = new Nodo(p->elem, p->sig);
		p = p->sig->sig;	//actualizar para la siguiente vuelta
		}
		this->ult = this->ult->sig;
		this->nelems *= 2;
	}
};
int main(){



	int in;
	while(cin >> in ){
		if(in != 0){
			ListaDuplica<int> q;
			q.push(in);
			while(cin >> in && in!= 0) q.push(in);
			q.duplicar();
			q.print();
		}
		cout << endl;
	}

	return 0;
}
