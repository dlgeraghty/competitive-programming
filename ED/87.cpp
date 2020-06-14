#include <iostream>
#include "bintree_eda.h"

using namespace std;

bool par(int x){
	return x % 2 == 0;
}

template <typename T>
int pares(bintree<T> a){
	if(a.empty())
		return 0;
	int l = pares(a.left());
	int r = pares(a.right());
	if(!a.left().empty()&& !a.right().empty() && par(a.root()) && par(a.left().root()) && par(a.right().root()))
		return max(max(l+1, r+1), l+r+1);
	if(par(a.root()))
		return 1;
	else 
		return max(l,r);
}

void resuelvecaso(){
	auto a = leerArbol(-1);
	printf("%d\n", pares(a));
}

int main(){
	int n;
	cin >> n;
	while(n--)resuelvecaso();
}
