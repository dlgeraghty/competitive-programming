#include <iostream>
#include "queue_eda.h"
//#include "queue.h"
using namespace std;

template <class T>
class ListaMerge: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print() const{
		Nodo * mostrar = this->prim;
		for(int i = 0; i < this->nelems; i++){
			cout << mostrar->elem << " ";
			mostrar = mostrar->sig;
		}
	}
	void merge(ListaMerge<int> & other, int pos){
		if(pos == 0){
			other.ult->sig = this->prim;
			this->prim = other.prim;
		}
		else{
			pos--;
			Nodo * p = this->prim;
			while(pos--)p = p->sig;
			Nodo * q =p->sig;
			other.ult->sig = q;
			p->sig = other.prim;
		}
		other.prim = nullptr;
		this->nelems += other.nelems;
		other.nelems = 0;
	}
};
int main(){

	int n;
	while(cin >> n){
		ListaMerge<int> a;
		int x;
		while(n--){
			cin >> x;
			a.push(x);
		}
		ListaMerge<int> b;
		int y, pos;
		cin >> y >> pos;
		while(y--){
			cin >> x;
			b.push(x);
		}
		if(b.size() != 0 && a.size() != 0){
			a.merge(b, pos);
			a.print();
		}
		else{
			if(b.size() == 0) a.print();
			else b.print();
		}
		cout << endl;
	}
	return 0;
}
