#include <iostream>
#include "bintree_eda.h"
#include <algorithm>

using namespace std;

struct s{
	bool ok = false;
	int i = 0;
};

template <typename T>
s genealogico(bintree<T> t){
	if(t.empty())
		return {true , 0};
	if(t.left().empty() && !t.right().empty()) return {false, 0};
	if(!t.left().empty())
		if(t.root() -18 < t.left().root())return {false, 0};
	if(!t.left().empty() && !t.right().empty()){
		if(t.root()-18 < t.right().root() || t.root() -18 < t.left().root())return {false, 0};
		if(t.left().root() -2 < t.right().root())return {false, 0};
	}
	bool sb = genealogico(t.left()).ok && genealogico(t.right()).ok;
	int si = 1 + max(genealogico(t.left()).i, genealogico(t.right()).i);
	return {sb, si};
}

template <typename T>
bintree<T> leerArbol_ext(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = leerArbol_ext(vacio);
      auto dr = leerArbol_ext(vacio);
      return {iz, raiz, dr};
   }
}

int main(){
	int in;
	cin >> in;
	while(in--){
		auto arbol = leerArbol_ext(-1);
		s o = genealogico(arbol);
		o.ok == true ? cout << "SI " << o.i: cout << "NO";
		cout << endl;

	}
	return 0;
}
