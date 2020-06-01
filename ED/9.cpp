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
	void reverse(){
		Nodo * prim = this->fantasma->sig;
		Nodo * ult = this->fantasma;

		Nodo * act = prim;
		Nodo * ant = nullptr;
		while(act != nullptr && act != ult){
			ant = act->ant;
			Nodo * sig = act->sig;
			act->ant = act->sig;
			act->sig = ant;
			act = sig;
		}
		this->fantasma->sig = act->ant;

	}
};
int main(){



	int in;
	while(cin >> in ){
		if(in != 0){
			ListaDuplica<int> q;
			q.push_back(in);
			while(cin >> in && in!= 0) q.push_back(in);
			q.reverse();
			q.print();
		}
		cout << endl;
	}

	return 0;
}
