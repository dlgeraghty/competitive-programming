#include <iostream>
#include "bintree_eda.h"

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
   using Link = typename bintree<T>::Link;
public:
   bintree_ext() : bintree<T>() {}
   bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
   size_t altura() const {
      return altura(this->raiz);
   }
   size_t nodos() const{
	   return nodos(this->raiz);
   }
   size_t hojas() const{
	   return hojas(this->raiz);
   }
private:
   static size_t altura(Link r) {
      if (r == nullptr) {
         return 0;
      } else {
         return 1 + std::max(altura(r->left), altura(r->right));
      }
   }
   static size_t nodos(Link r){
	   if(r == nullptr)
		   return 0;
	   else
		   return 1 + nodos(r->left) + nodos(r->right);
   }
   static size_t hojas(Link r){
	   if(r == nullptr) return 0;
	   else if(r->left == NULL && r->right == NULL) return 1;
	   else return hojas(r->left) + hojas(r->right);
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
		auto arbol = leerArbol_ext('.');
		printf("%d %d %d\n" , arbol.nodos(), arbol.hojas(), arbol.altura());
	}
	return 0;
}
