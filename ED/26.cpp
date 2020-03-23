#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

   bool checkBST(){
	   return checkBST(this->raiz, NULL, NULL);
   }

private:
   bool checkBST(Link r, Link i = NULL, Link d = NULL){
	if(r == NULL)return true;
	if(i != NULL && r->elem <= i->elem) return false;
	if(d != NULL && r->elem >= d->elem) return false;

	return checkBST(r->left, i, r) && checkBST(r->right, r, d);
   }
};

template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {
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
		if(arbol.checkBST())cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
