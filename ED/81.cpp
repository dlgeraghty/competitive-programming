#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <typename T>
bool especular(bintree<T> iz, bintree<T> dr){
	if(iz.empty() && dr.empty())
		return true;
	if(!iz.empty() && !dr.empty() && iz.root() == dr.root())
		return especular(iz.left(), dr.right()) && especular(iz.right() , dr.left());

	return false;
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
		auto arbol = leerArbol_ext('.');
		especular(arbol.left(), arbol.right()) == true ? cout << "SI" : cout << "NO";
		cout << endl;

	}
	return 0;
}
