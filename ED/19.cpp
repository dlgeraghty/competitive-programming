#include <iostream>
#include "bintree_eda.h"

using namespace std;

struct t{
	int n = 0;
	int h = 0;
	int a = 0;
};

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

template <typename T>
t solucion(bintree<T> a){

	if(a.empty())
	       return{0, 0, 0};	
	if(a.left().empty() && a.right().empty())
		return {1, 1, 1};
	
	t d = solucion(a.right());
	t i = solucion(a.left());
	int n = 1 + d.n + i.n;
	int h = d.h + i.h;
	int l = 1 + std::max(d.a , i.a);

	return {n, h, l};
}

int main(){
	int in;
	cin >> in;
	while(in--){
		auto arbol = leerArbol('.');
		t s = solucion(arbol);
//		printf("%li %li %li\n" , arbol.nodos(), arbol.hojas(), arbol.altura());
		printf("%d %d %d\n", s.n , s.h, s.a);
	}
	return 0;
}
