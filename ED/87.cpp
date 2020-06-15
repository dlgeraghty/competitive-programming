#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct t{
	int mejor;
	int raiz;
};

template <typename T>
t pares(bintree<T> a){
	if(a.empty())
		return {0,0};
	else{
		t l = pares(a.left());
		t r = pares(a.right());
		if(a.root()% 2 == 1)
			return {max(l.mejor, r.mejor), 0};
		else
			return {max(1 + l.raiz + r.raiz, max(l.raiz , r.raiz)), 1 + max(l.raiz , r.raiz)};
	}
}

void resuelvecaso(){
	auto a = leerArbol(-1);
	printf("%d\n", pares(a).mejor);
}

int main(){
	int n;
	cin >> n;
	while(n--)resuelvecaso();
}
