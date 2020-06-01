
#include <iostream>
#include "queue_eda.h"

using namespace std;

template <class T> 
class customLista : public queue<T>{
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
	void orden(customLista & l){

		if(this->prim->elem < l.prim->elem)
			this->prim = R(this->prim, l.prim);
		else
			this->prim = R(l.prim, this->prim);
		this->nelems += l.nelems;

		l.prim = nullptr;
		l.nelems = 0;
	}

	Nodo * R(Nodo * a, Nodo * b){
		Nodo * result = nullptr;
		
		if(a == nullptr)return b;
		if(b == nullptr)return a;

		if(a->elem <= b->elem){
			result = a;
			result->sig = R(a->sig, b);
		}
		else{
			result = b;
			result->sig = R(a, b->sig);
		}
		return result;
		
	}

};

void resuelvecaso(){

	customLista<int> o;
	customLista<int> p;
	int x;
	while(cin >> x && x != 0) 
		o.push(x);
	while(cin >> x && x != 0) 
		p.push(x);

	if( p.empty()){
		o.print();
	}else if( o.empty()){
		p.print();
	}
	else{
		o.orden(p);
		o.print();
	}

	
}

int main(){

	int x;
	cin >> x;
	while(x--)resuelvecaso();

	return 0;

}
