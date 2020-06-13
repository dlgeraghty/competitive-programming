#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct par{
	int a;
	int b;
};

template <typename T>
par atrapados(bintree<T> a){
	par iz, dr;
	if(a.empty())
		return {0,0};
	else{
		iz = atrapados(a.left());
		dr = atrapados(a.right());
		if(a.root() == 0)		return {iz.a+dr.a, max(iz.b,dr.b)};
		else
			if(iz.a + dr.a == 0)	return {1, a.root()};
			else			return {iz.a+dr.a, max(iz.b + a.root(), dr.b + a.root())}; 
	}
}

int main(){
	int in;
	cin >> in;
	while(in--){
		auto arbol = leerArbol(-1);
		par s= atrapados(arbol);
		printf("%d %d\n", s.a , s.b);

	}
	return 0;
}
