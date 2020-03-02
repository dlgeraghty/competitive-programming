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
	void reverse(){
		Nodo * ant = nullptr;
		Nodo * next = nullptr;
		Nodo * act = this->prim;
		while(act != nullptr){
			next = act->sig;
			act->sig = ant;
			ant = act;
			act = next;
		}
		this->prim = ant;
	}
};
int main(){



	int in;
	while(cin >> in ){
		if(in != 0){
			ListaDuplica<int> q;
			q.push(in);
			while(cin >> in && in!= 0) q.push(in);
			q.reverse();
			q.print();
		}
		cout << endl;
	}

	return 0;
}
